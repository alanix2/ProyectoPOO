#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Map
{
public:
	Map();
	void draw(sf::RenderWindow &window);

private:
	void initIntRect();
	void setTileIntRect(int tileId, sf::IntRect &ir);

private:
	//Especificar en constructor
	const int tileWidth;
	const int tileHeight;

	// This textures holds the textures for the tiles
	// It should be a single image with multiple tiles (like a spritesheet)
	sf::Texture tileSheet;

	sf::Sprite tile;

	// Add / remove these in order to add more tiles
	// This depends on the amount of tiles in your texture
	sf::IntRect piso;
	
	sf::IntRect esquinaSupIzq;
	sf::IntRect esquinaSupDer;
	sf::IntRect esquinaInfIzq;
	sf::IntRect esquinaInfDer;
	
	sf::IntRect paredSuperior;
	sf::IntRect paredInferior;
	sf::IntRect paredIzquierda;
	sf::IntRect paredDerecha;
};
