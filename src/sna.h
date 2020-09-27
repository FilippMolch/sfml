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
	vector<int> snake;
	int last_time;
	bool index = true;
	int vect = 0;
	int speed = 200;
	int index_bufer = 0;
	vector<RectangleShape> bufer;

	void add_snake_arr();
	RectangleShape get_rect(int x, int y);
	bool draw_snake();
	void anim_snake();

	Snake() {

		snake[0] += 20;
		snake[0] += 20;

		snake[1] += 40;
		snake[1] += 20;
		
		snake[2] += 60;
		snake[2] += 20;
	
		snake[3] += 80;
		snake[3] += 20;

	};

	~Snake();
};

RectangleShape draw_line(float x, float y, int gr, float x_2, float y_2);
RectangleShape draw_line_2(float x, float y, int gr, float x_2, float y_2);
#endif