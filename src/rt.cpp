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

	return film;
}

int main()
{
	const int resX = 512;
	const int resY = 512;

	Scene s {"./scene.obj"};
	Camera c {{5, 5, 5}, {-0.57735, -0.57735, -0.57735}, 130, resX, resY};

	auto film = render(c, s);

	std::cout << "P1\n" << resX << " " << resY << "\n";

	auto x = 0;
	for(auto pixel : film)
	{
		std::cout << pixel << " ";

		++x;
		if(x==resX)
		{
			x = 0;
			std::cout << std::endl;
		}
	}
}