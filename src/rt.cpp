#include "rt.h"

std::vector<int> render(Camera& cam, Scene& scene)
{
	auto resX = cam.getFilmResX();
	auto resY = cam.getFilmResY();

	std::vector<int> film(resX*resY, 0);

	unsigned x = 0, y = 0;
	for(auto& pixel : film)
	{
		Ray r = cam.generateRay(x, y);
		pixel = scene.intersect(r);

		++x;
		if(x==resX)
		{
			x = 0;
			++y;
		}
	}
}

int main()
{
	Scene s {"./scene.obj"};
	Camera c {{5, 0, 0}, {-1, 0, 0}, 40, 256, 256};

	render(c, s);
}