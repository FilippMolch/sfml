#include "sna.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

void sfmlWindow::mainFoo() {
	loop();
}

void sfmlWindow::loop(){
	
	Event eve;

	while (windowScreen.isOpen())
	{
		events(windowScreen);
		
		if (interFaceDraw) {

			interFaceObj.draw(windowScreen);

		}

		windowScreen.clear(Color(0, 0, 0));
		windowScreen.display();
	}

}

InterFace::InterFace() {

}

void InterFace::draw(RenderWindow& windowScreen) {
	const int width = VideoMode::getFullscreenModes()[0].width;
	const int height = VideoMode::getFullscreenModes()[0].width;
	
	while (true)
	{
		Event eve;

		while (windowScreen.pollEvent(eve))
		{

			if (eve.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				windowScreen.close();

			if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {

			}

			if (eve.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "mouse x: " << eve.mouseButton.x << std::endl;
				std::cout << "mouse y: " << eve.mouseButton.y << std::endl;
			}

			if (eve.type == sf::Event::TextEntered)
			{
				if (eve.text.unicode) {
					//txt = txt + static_cast<char>(eve.text.unicode);
					//cout << txt << endl;
				}

			}

		}

		RectangleShape NickNameInput(Vector2f(100, 10));
		NickNameInput.move(120, 120);
		NickNameInput.setFillColor(Color::Black);

		windowScreen.clear(Color(90, 90, 90));
		windowScreen.draw(NickNameInput);
	
		windowScreen.display();

		ProgramStack Nick;
	}

}
	

void Snake::draw_nickname(RenderWindow& win) {
	Text t;

	t.setFont(fo);
	t.setCharacterSize(10);
	t.setString(this->nickname);
	t.move(this->snk[0][0]-10, this->snk[0][1]-14);
	t.setFillColor(Color(150, 150, 150));
	
	win.draw(t);
}

Snake::Snake(){
	/*snk.push_back(vector<int>());
	snk[0][0] = 20;
	snk[0][1] = 20;
	*/
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
	this->draw_nickname(win);
	
	//draw_lines(win);
}

void Snake::anim_snake() {
	bool v = true;
	int time = clock();
	bool SnakeIsDead = false;

	if (time >= 1000 && index) {
		this->last_time = time;
		this->index = false;
	}
	
	if (!SnakeIsDead) {
		if (Keyboard::isKeyPressed(Keyboard::Left) && CurrentTurn != TURN_RIGHT)
			CurrentTurn = TURN_LEFT;
		if (Keyboard::isKeyPressed(Keyboard::Up) && CurrentTurn != TURN_DOWN)
			CurrentTurn = TURN_UP;
		if (Keyboard::isKeyPressed(Keyboard::Right) && CurrentTurn != TURN_LEFT)
			CurrentTurn = TURN_RIGHT;
		if (Keyboard::isKeyPressed(Keyboard::Down) && CurrentTurn != TURN_UP)
			CurrentTurn = TURN_DOWN;
	}

	if (time - last_time >= 200) {
		last_time = time;

		switch (CurrentTurn)
		{
			case TURN_NONE:
				break;
			case TURN_LEFT:
				this->snk[0][0] -= 20;
				break;
			case TURN_UP:
				this->snk[0][1] -= 20;
				break;
			case TURN_RIGHT:
				this->snk[0][0] += 20;
				break;
			case TURN_DOWN:
				this->snk[0][1] += 20;
				break;
		}

		this->push_snk();
		this->pop_snk();

	}

}

void Snake::draw_snake(RenderWindow& win) {

	for (int iu = 0; b ; iu++)
	{
		if (this->snk[iu][0] == 3) {
			b = false;
			break;
		}
		//win.draw(draw_line(20, 20, this->snk[iu][0], this->snk[iu][1], true, *this));
	}
	b = true;
}


ProgramStack Nick;
string txt = "";
string txt_2 = "";
void sfmlWindow::events(RenderWindow& windowScreen) {
	
	Event eve;

	while (windowScreen.pollEvent(eve))
	{

		if (eve.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			windowScreen.close();

		if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {

		}

		if (eve.mouseButton.button == sf::Mouse::Left)
		{
			std::cout << "the right button was pressed" << std::endl;
			std::cout << "mouse x: " << eve.mouseButton.x << std::endl;
			std::cout << "mouse y: " << eve.mouseButton.y << std::endl;
		}

		if (eve.type == sf::Event::TextEntered)
		{
			if (eve.text.unicode) {
				//txt = txt + static_cast<char>(eve.text.unicode);
				//cout << txt << endl;
			}

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
	bool Index = true;
	int x, y;

	for (int i = 0; Index; i++)
	{
		if (this->snk[i][0] == 3) {
			x = this->snk[i-1][0];
			y = this->snk[i-1][1];

			this->snk[i][0] = x + 15;
			this->snk[i][1] = y;

			this->snk[i + 1][0] = 3;
			this->snk[i + 1][1] = 3;

			Index = false;
			break;
		}
		cout << this->snk[i][0] << endl;
	}

}

RectangleShape sfmlWindow::draw_line(int x, int y, int x_2, int y_2, bool t, Snake& obj) {
	RectangleShape l(Vector2f(x, y));
	l.move(x_2, y_2);
	l.setFillColor(Color(obj.col[0], obj.col[1], obj.col[2]));
	return l;
}

RectangleShape sfmlWindow::draw_line(int x, int y, int x_2, int y_2) {
	RectangleShape l(Vector2f(x, y));
	l.move(x_2, y_2);
	l.setFillColor(Color(50, 50, 50));
	return l;
}

void sfmlWindow::draw_lines(RenderWindow& windowScreen) {
	bool line = true;
	bool line2 = true;

	int li = 0;
	int li2 = 0;
	
	while (line) {
		windowScreen.draw(draw_line(1, VideoMode::getFullscreenModes()[0].width, li, 0));
		li += 20;
		if (li >= VideoMode::getFullscreenModes()[0].width)
			line = false;
	}
	
	while (line2) {
		windowScreen.draw(draw_line(VideoMode::getFullscreenModes()[0].width, 1, 0, li2));
		li2 += 20;
		if (li2 >= VideoMode::getFullscreenModes()[0].width)
			line2 = false;
	}

}