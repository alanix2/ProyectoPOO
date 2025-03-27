#include "FondoHabitacion.h"

#include <iostream>
using namespace std;

FondoHabitacion::FondoHabitacion() : tileWidth(64), tileHeight(64) {
	if (!tileSheet.loadFromFile("assets/level/level4.png"))
		cout << "Could not load file" <<  endl;
	
	tile.setTexture(tileSheet);
	
	initIntRect();
}

FondoHabitacion::FondoHabitacion (Texture & t, int Width=64, int Height=64) : tileWidth(Width), tileHeight(Height) {
	tile.setTexture(t);
	initIntRect();
}

void FondoHabitacion::Dibujar(sf::RenderWindow &w)
{
	// tamaño de la habitación (10x7 baldosas)
	// cambiar dependiendo de la necesidad
	const int Rows = 10;
	const int Columns = 7;

	/*
	cada posicion del vector de TileSheetPositions corresponde a una parte de la textura
		0: Piso
		1: Esquina superior izquierda
		2: Esquina superior derecha
		3: Esquina inferior izquierda
		4: Esquina inferior derecha
		5: Pared de arriba
		6: Pared de abajo
		7: Pared a la izquieda
		8: Pared a la derecha
	*/
	//una matriz de enteros con las posiciones de las baldosas
	int FondoHabitacion[Rows][Columns] =
	{
		{ 1, 5, 5, 5, 5, 5, 2}, // fila 1
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 2
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 3
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 4
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 5
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 6
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 7
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 8
		{ 7, 0, 0, 0, 0, 0, 8}, // fila 9
		{ 3, 6, 6, 6, 6, 6, 4}, // fila 10
		
	};

	IntRect placeHolder;

	// Recorrer filas
	for (int row = 0; row < Rows; row++)
	{
		// Recorrer columnas
		for (int column = 0; column < Columns; column++) {
			//explicar esto xd
			int tileId = FondoHabitacion[row][column];
			placeHolder = TileSheetPositions[tileId];
			tile.setTextureRect(placeHolder);
			tile.setPosition((row * tileWidth), (column * tileHeight+32));
			w.draw(tile);
		}
	}
}

void FondoHabitacion::initIntRect() {
//asignamos cada rectangulo con el tamaño de la baldosa y la posicion de su textura en el tilesheet
	TileSheetPositions[0].left = 64;
	TileSheetPositions[0].top = 64;
	
	TileSheetPositions[1].left = 0;
	TileSheetPositions[1].top = 0;
	
	TileSheetPositions[2].left = 0;
	TileSheetPositions[2].top = 128;
	
	TileSheetPositions[3].left = 128;
	TileSheetPositions[3].top = 0;
	
	TileSheetPositions[4].left = 128;
	TileSheetPositions[4].top = 128;
	
	TileSheetPositions[5].left = 0;
	TileSheetPositions[5].top = 64;
	
	TileSheetPositions[6].left = 128;
	TileSheetPositions[6].top = 64;
	
	TileSheetPositions[7].left = 64;
	TileSheetPositions[7].top = 0;
	
	TileSheetPositions[8].left = 64;
	TileSheetPositions[8].top = 128;
	
	for (auto &t : TileSheetPositions){
		t.width = tileWidth;
		t.height = tileHeight;
	}
	
}
