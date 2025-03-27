#ifndef FONDOHABITACION_H
#define FONDOHABITACION_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
using namespace std;
using namespace sf;
//Redactar mejor xd
/*
Para evitar dibujar la habitacion con una textura entera,
utilizaremos una textura con las porciones (o baldosas) de texturas
y dibujaremos las baldosas varias veces dependiendo de la necesidad.
Por ejemplo, para una pared solo tendremos una baldosa con la textura de la pared
y la dibujaremos varias veces una al lado de la otra para evitar cargar una textura mas grande.

*/

class FondoHabitacion {
public:
	FondoHabitacion();
	FondoHabitacion(Texture &t, int Width, int Height);
	void Dibujar(RenderWindow &w);

private:
	void initIntRect();

private:
//	Altura y Anchura de cada baldosa
//	Especificar en constructor
	const int tileWidth;
	const int tileHeight;

//	Esta textura contiene las texturas de las baldosas. 
//	Debería ser una sola imagen con varias baldosas.
	Texture tileSheet;
	Sprite tile;
	
//	Vector que contiene rectangulos con el tamaño de la baldosa y su respectiva coordenada en la textura
//	Cambiar tamaño dependiendo de la necesidad
	IntRect TileSheetPositions[9];	
};

#endif
