#ifndef ITEMBASE_H
#define ITEMBASE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Jugador.h"

class ItemBase {
public:
	ItemBase();
	void RecogerItem(Jugador &j);
	void Dibujar();
private:
	Texture m_texture;
	Sprite m_sprite;
	int Puntos;
	
};

#endif

