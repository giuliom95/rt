#include "Scene.h"

void Scene::transformWorld(const Transform& t)
{
	for(auto& v : vertices)
		v = t(v);
}

Scene::Scene(std::istream& input) : 
vertices {}, normals{}, trisNum{0}, vertsNum{0}, lastInv{}
{
	std::vector<Point> tmpVs;
	std::vector<Vector> tmpNs;

	int normalsNum = 0;

	while(!input.eof())
	{
		std::string first;
		input >> first;
		if(first == "v")
		{
			Point v;
			input >> v.x >> v.y >> v.z;
			tmpVs.push_back(v);
		}

		if(first == "vn")
		{
			Vector n;
			input >> n.x >> n.y >> n.z;
			tmpNs.push_back(Vector::normalize(n));
			++normalsNum;
		}

		if(first == "f")
		{
			if(normalsNum)
			{
				for(auto i = 0; i < 3; ++i)
				{
					std::string elem;
					input >> elem;
					int sep = elem.find('/');
					int idx = std::stoi(elem.substr(0, sep));
					vertices.push_back(tmpVs[idx-1]);
					
					idx = std::stoi(elem.substr(sep+2, elem.length()-(sep+2)));
					normals.push_back(tmpNs[idx-1]);
				}
			} 
			else 
			{
				int ii[3];
				input >> ii[0] >> ii[1] >> ii[2];

				for(auto i : ii)
					vertices.push_back(tmpVs[i-1]);
			}
			++trisNum;
		}
	}

	vertsNum = trisNum*3;
}

bool Scene::intersect(const Ray& r, Point& p, Vector& n, Vector& err)
{
	bool ret = false;

	transformWorld(lastInv*r.w2r);
	lastInv = r.r2w;
	
	auto nearestT = Infinity;
	for(auto i = 0; i <= vertsNum; i+=3)
	{
		Point p0 = vertices[i];
		Point p1 = vertices[i+1];
		Point p2 = vertices[i+2];
		auto coords = RaySpace::origBarCoords(p0, p1, p2);

		auto a = coords.first;
		auto b = coords.second;
		auto c = 1 - a - b;

		if(a+b <= 1 && a >= 0 && b >= 0)
		{
			auto t = RaySpace::getT(a, b, p0, p1, p2);

			if(t > 0 && t < nearestT)
			{
				n = c*normals[i] + a*normals[i+1] + b*normals[i+2];
				p = r(t);
				
				// Compute floating point error
				Float xAbsSum = (std::abs(c * p0.x) + std::abs(a * p1.x) + std::abs(b * p2.x));
				Float yAbsSum = (std::abs(c * p0.y) + std::abs(a * p1.y) + std::abs(b * p2.y));
				Float zAbsSum = (std::abs(c * p0.z) + std::abs(a * p1.z) + std::abs(b * p2.z));
				err = gamma(7) * Vector(xAbsSum, yAbsSum, zAbsSum);

				ret = true;
				nearestT = t;
			}
		}
	}

	return ret;
}

std::vector<int> Scene::render(Camera& cam, Light& l)
{
	auto res = cam.getFilmRes();

	std::vector<int> film(res*res, 255);

	unsigned x = 0, y = 0;
	for(auto& pixel : film)
	{
		Ray r = cam.generateRay(x, y);
		Point p {}; Vector n {}; Vector err {};
		if(intersect(r, p, n, err))
		{
			Float w = Vector::dot(-l.d, n);
			
			// Computes the origin of the shadow ray
			auto offset = (Vector::dot(Vector::abs(n), err) + 0.001)*n;
			auto newP = p+offset;
			r = Ray(newP, -l.d);

			// Shoots shadow ray
			if(intersect(r, p, n, err))
				// Does a weighted average on the color weight
				w = (3*w-4)/12;
			
			// The color is ranged between 70 - 130
			pixel = (int)((w+1)*70 + 60);
		}
		
		++x;
		if(x==res)
		{
			x = 0;
			++y;
		}
	}

	return film;
}