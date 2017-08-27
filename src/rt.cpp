#include "general.h"

#include "Camera.h"
#include "Scene.h"


int main()
{
	const int res = 128;

	std::ifstream input {"./bunny.obj"};
	Scene s {input};

	//Camera c {{0, 5, 0}, {0, -1, 0}, {1,0,0}, 3, res};
	//Camera c {{-3, 0, -3}, {0.707107, 0, 0.707107}, {0, 1, 0}, 2, res};
	Camera c {{0, 0, 5}, {0, 0, -1}, {0, 1, 0}, 2, res};
	Light l {Vector::normalize({1, -1, 0})};

	auto film = s.render(c, l);

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