#include <iostream>
using namespace std;
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119

void ImprimirPantalla();
void RellenarMapa();
void Inputs();
void Logica();

enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '.' };

//Los botones que darán el movimiento
enum USER_INPUTS { NONE, UP, RIGHT, QUIT, LEFT, DOWN };

//Caractares para imprimir en consola
MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];


char personaje = 'O';
//Posicion inicial del jguador en consola
int personaje_x = 10;
int personaje_y = 5;
int personaje_points = 0;
int map_points = 0;



USER_INPUTS input = USER_INPUTS::NONE;
bool run = true;
int personaje_y_new = personaje_y;
int personaje_x_new = personaje_x;

//Clase donde llamare a las variables
int main()
{
	RellenarMapa();
	while (run) {
		Inputs();
		ImprimirPantalla();
		Logica();
	}

}

void RellenarMapa()
{
	//Valores y posiciones que se dan para la fila y la columna
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			//cout << i << "," << j << ".";
			if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1)
			{
				ConsoleScreen[i][j] = MAP_TILES::WALL;
			}
			else
			{
				ConsoleScreen[i][j] = MAP_TILES::EMPTY;
			}

		}

	}


    //Cordenadas de la parte del muro donde podremos pasar de un lado a otro
	ConsoleScreen[2][0] = MAP_TILES::EMPTY;
	ConsoleScreen[3][0] = MAP_TILES::EMPTY;
	ConsoleScreen[2][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
	ConsoleScreen[3][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;

	//Cordenadas donde los puntos estarán ubicados 
	ConsoleScreen[2][0] = MAP_TILES::POINT;
	map_points++;
	ConsoleScreen[2][1] = MAP_TILES::POINT;
	map_points++;
	ConsoleScreen[2][2] = MAP_TILES::POINT;
	map_points++;
	ConsoleScreen[2][3] = MAP_TILES::POINT;
	map_points++;
	ConsoleScreen[2][4] = MAP_TILES::POINT;
	map_points++;



	void Inputs() {
		char input_raw;
		cin >> input_raw;
		int newPos_X;
		int newPos_Y;
		switch (input_raw)
		{
		case 'W':
		case 'w':
			input = USER_INPUTS::UP;
			break;
		case 'A':
		case 'a':
			input = USER_INPUTS::LEFT;
			break;
		case 'S':
		case 's':
			input = USER_INPUTS::DOWN;
			break;
		case 'D':
		case 'd':
			input = USER_INPUTS::RIGHT;
			break;
		case 'Q':
		case 'q':
			input = USER_INPUTS::QUIT;
			break;
		default:
			input = USER_INPUTS::NONE;
			break;

		}

	}
	void Logica()
	{
		int personaje_y_new = personaje_y;
		int personaje_x_new = personaje_x;
		switch (input)
		{
		case NONE:
			break;
		case UP:
			personaje_y_new--;
			break;
		case DOWN:
			personaje_y_new++;
			break;
		case RIGHT:
			personaje_x_new++;
			break;
		case LEFT:
			personaje_x_new--;
			break;
		case QUIT:
			run = false;
			break;

		}
		//Condisional para transportal al personaje al lado contrario del mapa
		if (personaje_x_new < 0) {
			personaje_x_new = CONSOLE_WIDTH - 1;
		}
		personaje_x_new %= CONSOLE_WIDTH;
		if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::WALL) {
			personaje_y_new = personaje_y;
			personaje_x_new = personaje_x;
		}
		//Condicional para obtención de puntos 
		else if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::POINT) {
			map_points--;
			personaje_points++;
			//Con está linea lograremos hacer desaparecer a los puntos
			(ConsoleScreen[personaje_y_new][personaje_x_new]) = MAP_TILES::EMPTY;
		}

		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
	}


	void ImprimirPantalla() {
		system("CLS");
		for (int i = 0; i < CONSOLE_HEIGHT; i++)
		{
			for (int j = 0; j < CONSOLE_WIDTH; j++)
			{
				if (personaje_x == j && personaje_y == i)
				{
					cout << personaje;
				}
				else
				{
					cout << (char)ConsoleScreen[i][j];
				}
			}
			cout << endl;
		}
	}
}