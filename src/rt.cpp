#include "rt.h"

std::vector<int> render(Camera& cam, Scene& scene)
{
	auto res = cam.getFilmRes();

	std::vector<int> film(res*res, 255);
	Vector light {0, 1, 0};

	unsigned x = 0, y = 0;
	for(auto& pixel : film)
	{
		Ray r = cam.generateRay(x, y);
		Vector v {};
		if(scene.intersect(r, v))
		{
			double w = Vector::dot(light, v);
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

int main()
{
	const int res = 256;

	Scene s {"./bunny.obj"};
	//Camera c {{0, 5, 0}, {0, -1, 0}, {1,0,0}, 3, res};
	//Camera c {{1, 0, -1}, {-0.707107, 0, 0.707107}, {0, 1, 0}, 2, res};
	Camera c {{0, 0, 5}, {0, 0, -1}, {0, 1, 0}, 2, res};

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