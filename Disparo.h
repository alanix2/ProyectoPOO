#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;

class Disparo {
public:
	Disparo(Texture &text, Vector2f pos, Vector2f dir);
	void Actualizar();
	void Dibujar(RenderWindow &w);
	Vector2f verPosicion();
private:
	Sprite m_sprite;
	Vector2f m_vel;
};

#endif

