#include "Map.h"

Map::Map()
	// Change the values when using tiles other than 30x30
	: tileWidth(32)
	, tileHeight(32)
{
	// Load the texture which contains the tiles
	if (!tileSheet.loadFromFile("assets/level/level.png"))
	{
		std::cout << "Could not load \"tiles.png\"!" << std::endl;
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

		- 0	=	pink path
		- 1	=	stone wall
		- 2	=	wooden box
		- 3	=	grass
	*/

	int map[mapRows][mapColumns] =
	{
		{ 1, 1, 1, 1, 1, 1, 1}, // row 1
		{ 1, 0, 0, 0, 0, 0, 0}, // row 2
		{ 1, 0, 0, 0, 0, 0, 0}, // row 3
		{ 1, 0, 0, 2, 2, 2, 2}, // row 4
		{ 1, 0, 0, 2, 3, 3, 3}, // row 5
		{ 1, 0, 0, 2, 3, 2, 2}, // row 6
		{ 1, 0, 0, 2, 3, 2, 0}, // row 7
		{ 1, 0, 0, 2, 3, 2, 0}, // row 8
		{ 1, 0, 0, 2, 2, 2, 0}, // row 9
		{ 1, 0, 0, 0, 0, 0, 0}, // row 10
		
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
			switch (map[row][column])
			{
			case 0:
				placeHolder = pinkPath;
				break;
			case 1:
				placeHolder = stoneWall;
				break;
			case 2:
				placeHolder = woodenBox;
				break;
			case 3:
				placeHolder = grass;
				break;
			}

			// Set the correct part of the spritesheet
			tile.setTextureRect(placeHolder);

			// Set the position
			tile.setPosition((row * tileWidth), (column * tileHeight+16));

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
	grass.left = 0;
	grass.top = 0;
	grass.width = tileWidth;
	grass.height = tileHeight;

	pinkPath.left = 32;
	pinkPath.top = 0;
	pinkPath.width = tileWidth;
	pinkPath.height = tileHeight;

	stoneWall.left = 0;
	stoneWall.top = 32;
	stoneWall.width = tileWidth;
	stoneWall.height = tileHeight;

	woodenBox.left = 30;
	woodenBox.top = 32;
	woodenBox.width = tileWidth;
	woodenBox.height = tileHeight;
}
