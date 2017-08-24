#include "Scene.h"

	

Scene::Scene(std::string path) : vertices {}
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
		}
	}
}

void Scene::transformWorld(const Transform& t)
{
	for(auto& v : vertices)
		v = t(v);
}