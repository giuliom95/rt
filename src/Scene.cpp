#include "Scene.h"

void Scene::transformWorld(const Transform& t)
{
	for(auto& v : vertices)
		v = t(v);
}

Scene::Scene(std::string path) : vertices {}, trisNum{0}, vertsNum{0}
{
	std::vector<Point> tmp;
	std::ifstream ifs(path);

	while(!ifs.eof())
	{
		char first;
		ifs >> first;
		if(first == 'v')
		{
			Point v;
			ifs >> v.x >> v.y >> v.z;
			tmp.push_back(v);
		}

		if(first == 'f')
		{
			int i1, i2, i3;
			ifs >> i1 >> i2 >> i3;
			vertices.push_back(tmp[i1-1]);
			vertices.push_back(tmp[i2-1]);
			vertices.push_back(tmp[i3-1]);
			++trisNum;
		}
	}

	vertsNum = trisNum*3;
}

int Scene::intersect(const Ray& r)
{
	int ret = 0;

	transformWorld(r.w2r);
	
	for(auto i = 0; i <= vertsNum; i+=3)
	{
		//std::cerr << i << "/" << vertsNum << "\n";
		auto coords = RaySpace::origBarCoords(
			vertices[i], vertices[i+1], vertices[i+2]);
		auto a = coords.first;
		auto b = coords.second;

		if(a+b <= 1 && a >= 0 && b >= 0)
		{
			auto t = RaySpace::getT(
				a, b, vertices[i], vertices[i+1], vertices[i+2]);

			if(t > 0)
				ret = 1;
		}
	}
	transformWorld(r.r2w);

	return ret;
}