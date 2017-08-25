#include "rt.h"

std::vector<int> render(Camera& cam, Scene& scene)
{
	auto res = cam.getFilmRes();

	std::vector<int> film(res*res, 255);

	unsigned x = 0, y = 0;
	for(auto& pixel : film)
	{
		Ray r = cam.generateRay(x, y);
		pixel = scene.intersect(r);
		
		++x;
		if(x==res)
		{
			x = 0;
			++y;
		}
	}

	return film;
}

int main()
{
	const int res = 215;

	Scene s {"./scene.obj"};
	//Camera c {{5, 0, 5}, {-0.707107, 0, -0.707107}, {0,1,0}, 3, res};
	Camera c {{1, 0, 5}, {0, 0, -1}, {0, 1, 0}, 3, res};

	auto film = render(c, s);

	std::cout << "P2\n" << res << " " << res << "\n255\n";

	auto x = 0;
	for(auto pixel : film)
	{
		std::cout << pixel << " ";

		++x;
		if(x==res)
		{
			x = 0;
			std::cout << std::endl;
		}
	}
}