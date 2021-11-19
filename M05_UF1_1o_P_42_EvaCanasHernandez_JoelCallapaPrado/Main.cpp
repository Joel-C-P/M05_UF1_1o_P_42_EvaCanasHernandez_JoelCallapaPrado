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

int main()
{
	RellenarMapa();
	while (run) {
		Inputs();
		ImprimirPantalla();
		Logica();
	}

}