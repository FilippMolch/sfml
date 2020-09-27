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
	bool line_bool = false;
	bool line_bool_2 = false;
	float pos_1, pos_2;
	pos_1 = 20;
	pos_2 = 20;
	Snake snuk;
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(1920/2, 1080/2), "SFML Works!", Style::Default, settings);
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)){
				int time = clock();
				cout << time;
				window.close();
			
			}

		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && snuk.vect !=1)
			snuk.vect = 0;		
		if (Keyboard::isKeyPressed(Keyboard::Left) && snuk.vect != 0)
			snuk.vect = 1;
		if (Keyboard::isKeyPressed(Keyboard::Down) && snuk.vect != 3)
			snuk.vect = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up) && snuk.vect != 2)
			snuk.vect = 3;

		//RectangleShape snak(Vector2f(20, 20));
		//snak.move(snuk.snake[1], snuk.snake[2]);
		//snak.setFillColor(Color(0, 200, 0));

		//window.draw(snak);

		//snuk.add_snake_arr();
		//snuk.anim_snake();
		//if (snuk.draw_snake()) {
			//for (int ind = 0; ind < 10000; ind++) {
		//		if (snuk.bufer[ind] == NULL)
		//			break;
			//}
		//}

		while (!line_bool) {
			window.draw(draw_line(540.f, 1.f, 100, pos_1, 0.f));
			pos_1 += 20;
			if (pos_1 >= 1920/2)
				line_bool = true;
		}

		while (!line_bool_2) {
			window.draw(draw_line_2(1920 / 2, 1.f, 100, 0.f, pos_2));
			pos_2 += 20;
			if (pos_2 >= 540)
				line_bool_2 = true;
		}
		
		window.display();
		window.clear(Color(0, 0, 0));
		line_bool = false;
		line_bool_2 = false;
		pos_1 = 20;
		pos_2 = 20;
	}

	return 0;
}