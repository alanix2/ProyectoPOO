#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "EntidadDibujable.h"
using namespace sf;

class Disparo : public EntidadDibujable {
public:
	Disparo(Texture &t, Vector2f pos, Vector2f dir);
	virtual bool Colisiona(Vector2f pos) = 0;
	virtual ~Disparo() {}
protected:
	Vector2f m_velocidad;
private:

};

#endif

