#ifndef lol
#define lol
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <ctime>
using namespace sf;
using namespace std;

class Snake {
	
public:

	int col[3] = {0, 0, 0};

	bool b = true;
	int flag = 3;
	int last_time = 0;
	bool index = true;
	Font fo;

	string nickname = "FilippFox";

	int snk[100][2] = {
		{40, 10},
		{30, 10},
		{20, 10},
		{10, 10},
		{3, 3}
	};



	void pop_snk();
	void push_snk();

	void draw_nickname(RenderWindow& win);

	void anim_snake();
	void draw_snake(RenderWindow &win);

	void rand_color(Snake& obj);

	void sn_func(RenderWindow& win);

	Snake();
};

RectangleShape draw_line(int x, int y, int x_2, int y_2);
RectangleShape draw_line(int x, int y, int x_2, int y_2, bool t, Snake& obj);
void events(RenderWindow &win);
void draw_lines(RenderWindow &wi);

#endif