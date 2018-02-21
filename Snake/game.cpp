#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

struct players
{
	string username; // Ник игрока
	int highscore;
};

struct participants
{
	players playerlist[3];
};

// Профили
void print(players, int);
players player1(string);
players player2(string);
players player3(string);

bool gameover;
const int width = 40; // Width of map = 20 (от этого зависит скорость и глючность игры, точнее - карты)
const int height = 20; // Height of map = 20 
int x, y, fruit_X, fruit_Y, score;
int tail_X[100], tail_Y[100]; // массивы "клеток", по которым перемещается змейка
int tail;
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN }; // Определяет действия при нажатии кнопок
direction d;
participants z;

void Setplayer()
{
	for (int i = 0; i<3; i++)
	{
		string username;

		cout << "Enter username: " << endl;
		cin >> z.playerlist[i].username;
		cout << endl;
	}
}

// Таблица рекордов для трёх лучших игроков
void print(players a, players b, players c)
{
	cout << "High score of player 1: " << a.highscore << endl;
	cout << "High score of player 2: " << b.highscore << endl;
	cout << "High score of player 3: " << c.highscore << endl;
}

void Setup() 
{
	gameover = false;
	d = STOP;
	x = width / 2;
	y = height / 2;
	fruit_X = rand() % width;
	fruit_Y = rand() % height;
	score = 0;
}

void Draw() // Карта
{
	system("cls");
	for (int i = 0; i<width + 2; i++) // Границы право-лево
		cout << "*"; 
	cout << endl;

	for (int i = 0; i<height; i++) // Потолок
	{
		for (int j = 0; j<width; j++)
		{
			if (j == 0)
				cout << "*";
			if (i == y && j == x)
				cout << "D";
			else if (i == fruit_Y && j == fruit_X)
				cout << "o";
			else
			{
				bool print = false;
				for (int k = 0; k<tail; k++)
				{
					if (tail_X[k] == j && tail_Y[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == width - 1)
				cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i<width + 2; i++) // Пол
		cout << "*";
	cout << endl;
	cout << "Score:" << score << endl; // Очки
}

void Input() // Управление
{
	if (_kbhit()) // <conio.h>
	{
		switch (_getch())
		{
		case 'a': 
			d = LEFT;
			break;

		case 'd': 
			d = RIGHT;
			break;

		case 'w': 
			d = UP;
			break;

		case 's': 
			d = DOWN;
			break;

		case 'o': 
			gameover = true;
			break;
		}
	}
}

void Logic()
{
	int prev_X = tail_X[0]; 
	int prev_Y = tail_Y[0]; 
	int prev2_X, prev2_Y;
	tail_X[0] = x;
	tail_Y[0] = y;

	for (int i = 1; i<tail; i++)
	{
		prev2_X = tail_X[i];
		prev2_Y = tail_Y[i];
		tail_X[i] = prev_X;
		tail_Y[i] = prev_Y;
		prev_X = prev2_X;
		prev_Y = prev2_Y;
	}
	switch (d)
	{
	case LEFT:
		x--;
		break;

	case RIGHT:
		x++;
		break;

	case UP:
		y--; 
		break;

	case DOWN:
		y++; 
		break;

	default:
		break;
	}
	if (x>width || x<0 || y>height || y<0) // Если змейка коснулась границ - конец игры
		gameover = true;
	for (int i = 0; i<tail; i++)
		if (tail_X[i] == x && tail_Y[i] == y) // Если змейка коснулась сама себя - конец игры
			gameover = true;

	if (x == fruit_X && y == fruit_Y) // Когда фрукт съеден, добавляет очки, добавляет новый фрукт, увеличивает змейку
	{
		score += 10;
		fruit_X = rand() % width;
		fruit_Y = rand() % height;
		tail++;
	}
}

int main()
{
	Setplayer();
	for (int r = 0; r>2; r++)
	{

	}

	Setup();
	for (int i = 0; i<2; i++)
	{
		while (!gameover) // Когда game_over is false, run Draw, Input, Logic
		{
			Draw();
			Input();
			Logic();
			Sleep(10); // по сути, настройка сложности
					   //z.playerlist[i].highscore=highscore;

		}

	}

	return 0;
}