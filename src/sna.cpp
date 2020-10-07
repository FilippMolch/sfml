#include "sna.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <ctime>

InterFace::InterFace() {

}

void InterFace::draw(RenderWindow& win) {
	const int width = VideoMode::getFullscreenModes()[0].width;
	const int height = VideoMode::getFullscreenModes()[0].width;
	RectangleShape NickNameInput(Vector2f(width / 2 - 100, height / 2 + 10));
	NickNameInput.move(0, 0);
	NickNameInput.setFillColor(Color::Black);
	
	ProgramStack Nick;
	Event eve;

}

void foo() {
	vector< vector<int> > v;
	v.push_back(vector<int>());
	v[0].push_back(100500);
	int a = v[0][0];
	//cout << a << endl;
}
	

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
	
	draw_lines(win);
	foo();
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
		
	/*for (int i = 1; v; i++)
	{
		if (this->snk[i][0] == 3) {
			snk[i-1][0] = NULL;
			snk[i-1][1] = NULL;
			
			v = false;
			break;
		}
	}*/

	}

}

void Snake::draw_snake(RenderWindow& win) {

	for (int iu = 0; b ; iu++)
	{
		if (this->snk[iu][0] == 3) {
			b = false;
			break;
		}
		win.draw(draw_line(20, 20, this->snk[iu][0], this->snk[iu][1], true, *this));
	}
	b = true;
}


void events(RenderWindow &win) {
	
	Event eve;
	ProgramStack Nick;

	while (win.pollEvent(eve))
	{

		if (eve.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
			int time = clock();
			cout << time;
			win.close();

		}

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
				Nick.push('o');//static_cast<char>(eve.text.unicode));
				cout << Nick.GetNickName() << endl;
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
	bool v = true;
	int x, y;

	for (int i = 0; v ; i++)
	{
		if (this->snk[i][0] == 3) {
			x = this->snk[i-1][0];
			y = this->snk[i-1][1];

			this->snk[i][0] = x + 15;
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

void draw_lines(RenderWindow &win) {
	bool line = true;
	bool line2 = true;

	int li = 0;
	int li2 = 0;
	
	while (line) {
		win.draw(draw_line(1, VideoMode::getFullscreenModes()[0].width, li, 0));
		li += 20;
		if (li >= VideoMode::getFullscreenModes()[0].width)
			line = false;
	}
	
	while (line2) {
		win.draw(draw_line(VideoMode::getFullscreenModes()[0].width, 1, 0, li2));
		li2 += 20;
		if (li2 >= VideoMode::getFullscreenModes()[0].width)
			line2 = false;
	}

}