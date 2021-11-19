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

	ConsoleScreen[2][0] = MAP_TILES::EMPTY;
	ConsoleScreen[3][0] = MAP_TILES::EMPTY;
	ConsoleScreen[2][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
	ConsoleScreen[3][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;





}