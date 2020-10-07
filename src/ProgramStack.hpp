// Realization by RidgyTheFox.
// 05:14 AM | 05.10.2020
// :3

#include <iostream>

using namespace std;

class ProgramStack
{
private:
	const int stackSize = 256;
	char stack[256];
	int pointer = 0;
	string Nick = "";

	bool debugMode = true;


public:
	ProgramStack()
	{
		stackClear();
	}

	// Добавление элемента.
	bool push(char symb)
	{
		bool isFailrue = false;

		if (pointer + 1 < stackSize)
		{
			pointer++;
			stack[pointer] = symb;
		}
		else
		{
			isFailrue = true;
			if (debugMode)
				cout << "STACK OVERFLOW!" << endl;
		}

		return isFailrue;
	}

	// Чтение элемента.
	char pop()
	{
		if (pointer > 0)
		{
			pointer--;
			char tmp = stack[pointer+1];
			stack[pointer + 1] = ' ';
			return tmp;
		}
		else
		{
			cout << "STACK UNDERFLOW!" << endl;
			return NULL;
		}

		return ' ';
	}

	// Получение элемента первого элемента.
	char peek()
	{
		return stack[0];
	}

	int stackPointerPosition()
	{
		return pointer;
	}

	// Очистка стека.
	void stackClear()
	{
		for (int i = 0; i < stackSize; i++)
		{
			stack[i] = ' ';
			pointer = 0;
		}
	}

	string GetNickName() 
	{
		for (int i = 0; i < stackSize; i++)
		{
			Nick += stack[i];
			cout << stack[i] << endl;
		}
		return Nick;
	}
};