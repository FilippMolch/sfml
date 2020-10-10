#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <sna.h>

using namespace sf;
using namespace std;

InterFace interFaceSnake;

Snake snakeObj;

ContextSettings set;

int main()
{
	setlocale(LC_ALL, "Rus");
	set.antialiasingLevel = 8;

	RenderWindow windowScreen(VideoMode::getFullscreenModes()[0], "SNAKE", Style::Fullscreen, set);

	//RenderWindow mainWin(VideoMode::getFullscreenModes()[0], "SNAKE", Style::Fullscreen, set);
	
	sfmlWindow snakeScreen(interFaceSnake, snakeObj, windowScreen);


	return 0;
}