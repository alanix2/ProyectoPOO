#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "EntidadDibujable.h"
#include <SFML/Graphics/Rect.hpp>
using namespace sf;

class Disparo : public EntidadDibujable {
public:
	Disparo(Texture &t, IntRect TexturePortion, Vector2f pos, Vector2f dir, float vel);
	bool verEstado();
	void Destruir();
	virtual ~Disparo() {}
protected:
	Vector2f m_velocidad;
	bool m_destruido = false; //booleano para saber si el proyectil sigue activo, si no lo está, el arma deberia de quitarlo del vector.
private:

};

#endif

