#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "EntidadDibujable.h"
#include <SFML/Graphics/Rect.hpp>
using namespace sf; 
//la clase base para el disparo, bala, o proyectil que contiene cada arma.

class Disparo : public EntidadDibujable {
public:
	Disparo(Texture &t, IntRect TexturePortion, Vector2f pos, Vector2f dir, float vel);
	bool verEstado(); //Para ver si está destruido o no.
	void Destruir(); //Xd
	virtual ~Disparo() {}
protected:
	Vector2f m_velocidad; //la velocidad a la que se mueve el disparo. No todos los disparos lo necesitarian (creo xd).
	bool m_destruido = false; //booleano para saber si el proyectil sigue activo, si no lo está, el arma deberia de quitarlo del vector.
private:

};

#endif

