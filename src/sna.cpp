#include "sna.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <ctime>

void Snake::add_snake_arr() {

}

RectangleShape Snake::get_rect(int x, int y) {
	RectangleShape snak(Vector2f(20, 20));
	snak.move(this->snake[x], this->snake[y]);
	snak.setFillColor(Color(0, 200, 0));
	return snak;
}

void Snake::anim_snake() {
	int time = clock();
	if (time >= 1000 && index) {
		this->last_time = time;
		this->index = false;
	}

	if (time - last_time >= this->speed) {
		last_time = time;
		if (vect == 0)
			snake[1] += 20;
		if (vect == 1)
			snake[1] -= 20;
		if (vect == 2)
			snake[2] += 20;
		if (vect == 3)
			snake[2] -= 20;
	}
}
bool Snake::draw_snake() {
	
	for (int i = 0; i < 10000; i++) {
		if (this->snake[i] == 0x00) {
			break;
		}
		if (snake[i] == 199442) {
			this->bufer[index_bufer] = this->get_rect(this->snake[i + 1], this->snake[i + 2]);
			this->index_bufer += 1;
		}
	}
	return true;
}

RectangleShape draw_line(float x, float y, int gr, float x_2, float y_2) {
	RectangleShape line(Vector2f(x, y));
	line.setFillColor(Color(gr, gr, gr));
	line.rotate(90.f);
	line.move(x_2, y_2);
	return line;
}

RectangleShape draw_line_2(float x, float y, int gr, float x_2, float y_2) {
	RectangleShape line(Vector2f(x, y));
	line.setFillColor(Color(gr, gr, gr));
	line.rotate(0.f);
	line.move(x_2, y_2);
	return line;
}