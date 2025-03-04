#include "Map.h"

Map::Map()
	// Change the values when using tiles other than 30x30
	: tileWidth(64)
	, tileHeight(64)
{
	// Load the texture which contains the tiles
	if (!tileSheet.loadFromFile("assets/level/level2.png"))
	{
		std::cout << "Could not load file" <<  std::endl;
	}

	// Set the tiles
	tile.setTexture(tileSheet);

	// Assign the tiles to the IntRect
	initIntRect();
}

void Map::draw(sf::RenderWindow &window)
{
	// This is the map (20x20 tiles)
	// Change when needed
	const int mapRows = 10;
	const int mapColumns = 7;

	/*
	The codes with their corresponding tiles
		-0 piso
		-1 esquinaSupIzq;
		-2 esquinaSupDer;
		-3 esquinaInfIzq;
		-4 esquinaInfDer;
	
		-5 paredSuperior;
		-6 paredInferior;
		-7 paredIzquierda;
		-8 paredDerecha;
	*/

	int map[mapRows][mapColumns] =
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

	// IntRect placeholder
	sf::IntRect placeHolder;

	// Loop through the rows
	for (int row = 0; row < mapRows; row++)
	{
		// Loop through the columns
		for (int column = 0; column < mapColumns; column++)
		{
			// Add / remove cases when tiles are added / removed
//			setTileIntRect(map[row][column], placeHolder);
			switch (map[row][column]){
			case 0:
				placeHolder = piso;
				break;
			case 1:
				placeHolder = esquinaSupIzq;
				break;
			case 2:
				placeHolder = esquinaSupDer;
				break;
			case 3:
				placeHolder = esquinaInfIzq;
				break;
			case 4:
				placeHolder = esquinaInfDer;
				break;
			case 5:
				placeHolder = paredSuperior;
				break;
			case 6:
				placeHolder = paredInferior;
				break;
			case 7:
				placeHolder = paredIzquierda;
				break;
			case 8:
				placeHolder = paredDerecha;
				break;
			}

			// Set the correct part of the spritesheet
			tile.setTextureRect(placeHolder);

			// Set the position
			tile.setPosition((row * tileWidth), (column * tileHeight+32));
			//test 


			// Draw the sprite to the screen
			window.draw(tile);
		}
	}
}

// Check the SFML documentation about intrect if you do not know what is going on here
// Add / remove some when needed (if you use less or more tiles in the texture)
// The value of 30 is the width / height of a tile
// Change if the tiles should be bigger / smaller
void Map::initIntRect()
{
	piso.left = 64;
	piso.top = 64;
	piso.width = tileWidth;
	piso.height = tileHeight;
	
	esquinaSupIzq.left = 0;
	esquinaSupIzq.top = 0;
	esquinaSupIzq.width = tileWidth;
	esquinaSupIzq.height = tileHeight;
	
	esquinaSupDer.left = 0;
	esquinaSupDer.top = 128;
	esquinaSupDer.width = tileWidth;
	esquinaSupDer.height = tileHeight;
	
	esquinaInfIzq.left = 128;
	esquinaInfIzq.top = 0;
	esquinaInfIzq.width = tileWidth;
	esquinaInfIzq.height = tileHeight;
	
	esquinaInfDer.left = 128;
	esquinaInfDer.top = 128;
	esquinaInfDer.width = tileWidth;
	esquinaInfDer.height = tileHeight;
	
	paredSuperior.left = 0;
	paredSuperior.top = 64;
	paredSuperior.width = tileWidth;
	paredSuperior.height = tileHeight;
	
	paredInferior.left = 128;
	paredInferior.top = 64;
	paredInferior.width = tileWidth;
	paredInferior.height = tileHeight;
	
	paredIzquierda.left = 64;
	paredIzquierda.top = 0;
	paredIzquierda.width = tileWidth;
	paredIzquierda.height = tileHeight;
	
	paredDerecha.left = 64;
	paredDerecha.top = 128;
	paredDerecha.width = tileWidth;
	paredDerecha.height = tileHeight;
}

void Map::setTileIntRect (int tileId, sf::IntRect &ir) {	
	switch (tileId){
	case 0:
		ir = piso;
		break;
	case 1:
		ir = esquinaSupIzq;
		break;
	case 2:
		ir = esquinaSupDer;
		break;
	case 3:
		ir = esquinaInfIzq;
		break;
	case 4:
		ir = esquinaInfDer;
		break;
	case 5:
		ir = paredSuperior;
		break;
	case 6:
		ir = paredInferior;
		break;
	case 7:
		ir = paredIzquierda;
		break;
	case 8:
		ir = paredDerecha;
		break;
	}
}

