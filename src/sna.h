#ifndef lol
#define lol
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <ProgramStack.hpp>
using namespace sf;
using namespace std;

class InterFace {
private:
	
public:

	void draw(RenderWindow& windowScreen);

	InterFace();
};

class Snake {
	
public:
	
	enum Snake_turn
	{
		TURN_NONE,
		TURN_LEFT,
		TURN_UP,
		TURN_RIGHT,
		TURN_DOWN
	};
	ProgramStack Nick;
	Snake_turn turn = TURN_LEFT;
	int col[3] = {0, 0, 0};
	int CurrentTurn = TURN_RIGHT;
	bool b = true;
	int flag = 3;
	int last_time = 0;
	bool index = true;
	Font fo;

	string nickname = "Player";

	int snk[100][2] = {
		{80, 20},
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

class sfmlWindow
{
private:
	bool nickInput = true;
	bool interFaceDraw = true;



	RenderWindow *windowScreen;

public:

	RectangleShape draw_line(int x, int y, int x_2, int y_2);
	RectangleShape draw_line(int x, int y, int x_2, int y_2, bool t, Snake& obj);
	
	void events(RenderWindow& windowScreen);
	void draw_lines(RenderWindow& windowScreen);
	void loop();
	void mainFoo();

	sfmlWindow(InterFace& interFaceObj, Snake& snakeClassObj, RenderWindow windowScreen) {
	
		windowScreen = 
		mainFoo();
	}

};

#endif