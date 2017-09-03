#include "general.h"

#include "Camera.h"
#include "Scene.h"


int main()
{
	const int res = 512;

	std::ifstream input {"./bunny.obj"};
	Scene s {input};

	Camera c {{0, -0.2, 7.5}, {0, 0, -1}, {0,1,0}, 30, res};
	//Camera c {{-7, 0, -7}, {0.707107, 0, 0.707107}, {0, 1, 0}, 30, res};
	//Camera c {{-8, 6.5, 7}, Vector::normalize({1, -1, -1}), {0, 1, 0}, 30, res};
	Light l {Vector::normalize({0, -1, -1})};

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