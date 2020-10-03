#include "sna.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <ctime>

void Snake::draw_nickname(RenderWindow& win) {
	Text t;

	t.setFont(fo);
	t.setCharacterSize(10);
	t.setString(this->nickname);
	t.move(this->snk[0][0]-10, this->snk[0][1]-14);
	t.setFillColor(Color(150, 150, 150));
	//t.setStyle(sf::Text::Bold | sf::Text::Underlined);
	win.draw(t);
}

Snake::Snake(){
	fo.loadFromFile("Font/arial.ttf");
	rand_color(*this);
}

void Snake::rand_color(Snake& obj) {
	
	obj.col[0] = 0;
	obj.col[1] = 150;
	obj.col[2] = 0;
}

void Snake::sn_func(RenderWindow& win) {
	this->draw_snake(win);
	this->anim_snake();
	draw_lines(win);
	this->draw_nickname(win);
}

void Snake::anim_snake() {
	bool v = true;
	int time = clock();

	cout << time - last_time << endl;

	if (time >= 1000 && index) {
		this->last_time = time;
		this->index = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
		this->flag = 1;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		this->flag = 2;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		this->flag = 3;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		this->flag = 4;

	if (time - last_time >= 100) {
		last_time = time;

		if (flag == 1) {
			this->snk[0][0] -= 10;
		}

		if (flag == 2) {
			this->snk[0][1] -= 10;
		}

		if (flag == 3) {
			this->snk[0][0] += 10;
		}

		if (flag == 4) {
			this->snk[0][1] += 10;
		}
	}

	for (int i = 0; v; i++)
	{
		if (this->snk[i][0] == 3) {
			
			v = false;
			break;
		}
	}
}

void Snake::draw_snake(RenderWindow& win) {

	for (int iu = 0; b ; iu++)
	{
		if (this->snk[iu][0] == 3) {
			b = false;
			break;
		}
		win.draw(draw_line(10, 10, this->snk[iu][0], this->snk[iu][1], true, *this));
	}
	b = true;
}

void events(RenderWindow &win) {
	
	Event eve;

	while (win.pollEvent(eve))
	{

		if (eve.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
			int time = clock();
			cout << time;
			win.close();

		}

	}

}

void Snake::pop_snk() {
	bool v = true;

	for (int i = 0; v; i++)
	{
		if (this->snk[i][0] == 3) {
			
			this->snk[i - 1][0] = 3;
			this->snk[i - 1][1] = 3;

			this->snk[i][0] = NULL;
			this->snk[i][1] = NULL;

			v = false;
			break;
		}
	}
}

void Snake::push_snk() {
	bool v = true;
	int x, y;

	for (int i = 0; v ; i++)
	{
		if (this->snk[i][0] == 3) {
			x = this->snk[i-1][0];
			y = this->snk[i-1][1];

			this->snk[i][0] = x + 10;
			this->snk[i][1] = y;

			this->snk[i + 1][0] = 3;
			this->snk[i + 1][1] = 3;

			v = false;
			break;
		}
		cout << this->snk[i][0] << endl;
	}
}

RectangleShape draw_line(int x, int y, int x_2, int y_2, bool t, Snake& obj) {
	RectangleShape l(Vector2f(x, y));
	l.move(x_2, y_2);
	l.setFillColor(Color(obj.col[0], obj.col[1], obj.col[2]));
	return l;
}

RectangleShape draw_line(int x, int y, int x_2, int y_2) {
	RectangleShape l(Vector2f(x, y));
	l.move(x_2, y_2);
	l.setFillColor(Color(50, 50, 50));
	return l;
}

void draw_lines(RenderWindow &wi) {
	bool line = true;
	bool line2 = true;

	int li = 0;
	int li2 = 0;
	
	while (line) {
		wi.draw(draw_line(1, 1920/2, li, 0));
		li += 10;
		if (li >= 1920/2 + 40)
			line = false;
	}
	
	while (line2) {
		wi.draw(draw_line(1920 / 2, 1, 0, li2));
		li2 += 10;
		if (li2 >= 1080/2)
			line2 = false;
	}

}