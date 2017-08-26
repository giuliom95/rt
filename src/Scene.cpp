#include "Scene.h"

void Scene::transformWorld(const Transform& t)
{
	for(auto& v : vertices)
		v = t(v);
}

Scene::Scene(std::string path) : 
vertices {}, normals{}, trisNum{0}, vertsNum{0}, lastInv{}
{
	std::vector<Point> tmpVs;
	std::vector<Vector> tmpNs;
	std::ifstream ifs(path);

	int normalsNum = 0;

	while(!ifs.eof())
	{
		std::string first;
		ifs >> first;
		if(first == "v")
		{
			Point v;
			ifs >> v.x >> v.y >> v.z;
			tmpVs.push_back(v);
		}

		if(first == "vn")
		{
			Vector n;
			ifs >> n.x >> n.y >> n.z;
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
					ifs >> elem;
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
				ifs >> ii[0] >> ii[1] >> ii[2];

				for(auto i : ii)
					vertices.push_back(tmpVs[i-1]);
			}
			++trisNum;
		}
	}

	vertsNum = trisNum*3;
}

bool Scene::intersect(const Ray& r, Vector& n)
{
	bool ret = false;

	transformWorld(lastInv*r.w2r);
	lastInv = r.r2w;
	
	auto nearestT = std::numeric_limits<double>::infinity();
	for(auto i = 0; i <= vertsNum; i+=3)
	{
		auto coords = RaySpace::origBarCoords(
			vertices[i], vertices[i+1], vertices[i+2]);
		auto a = coords.first;
		auto b = coords.second;

		if(a+b <= 1 && a >= 0 && b >= 0)
		{
			auto t = RaySpace::getT(
				a, b, vertices[i], vertices[i+1], vertices[i+2]);

			if(t < nearestT)
			{
				/*
				Vector v1 = vertices[i+1]-vertices[i];
				Vector v2 = vertices[i+2]-vertices[i];
				Vector planeN = Vector::normalize(Vector::cross(v1,v2));
				Transform trans {r.w2r.getM().t()};
				n = trans(planeN);
				*/
				n = (1-a-b)*normals[i] + a*normals[i+1] + b*normals[i+2];

				ret = true;
				nearestT = t;
			}
		}
	}

	return ret;
}