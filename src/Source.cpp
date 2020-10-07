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


	bool kok = true;

	set.antialiasingLevel = 8;
	RenderWindow window(VideoMode::getFullscreenModes()[0], "snake", Style::Default, set);

	bool menu = true;

	string txt = "Nick: ";

	InterFace f;

	while (menu)
	{
		events(window);
		f.draw(window);
		window.display();
		window.clear(Color(90, 90, 90));
	}
	Snake d;
	
	int i = 0;
	int x = 0;
	while (window.isOpen()) {
		if (kok) {
			events(window);
			d.sn_func(window);

			window.display();
			window.clear(Color(0, 0, 0));
		}
	}

	return 0;
}