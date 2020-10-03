#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <sna.h>
using namespace sf;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	ContextSettings set;
	set.antialiasingLevel = 8;
	RenderWindow window(VideoMode(1920/2, 1080/2), "snake", Style::Default, set);
	Snake d;
	int i = 0;
	int x = 0;
	while (window.isOpen()) {
		events(window);
		d.sn_func(window);

		window.display();
		window.clear(Color(0, 0, 0));
	}

	return 0;
}