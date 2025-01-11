#ifndef ITEMBASE_H
#define ITEMBASE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Jugador.h"
#include <SFML/Graphics/RenderWindow.hpp>

class ItemBase {
public:
	ItemBase();
	void RecogerItem(Jugador &j);
	void Dibujar(RenderWindow &w);
	void Actualizar();
	Vector2f verPosicion();
private:
	Texture m_texture;
	Sprite m_sprite;
	int Puntos;
	
};

#endif

