#include "ItemBase.h"
#include <iostream>

ItemBase::ItemBase() {
	m_texture.loadFromFile("assets/item/Power.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(8,8);
	m_sprite.setPosition(220, 240);
}


void ItemBase::RecogerItem (Jugador & j) {
	j.sumarPuntos(3);
}

void ItemBase::Dibujar (RenderWindow & w) {
	w.draw(m_sprite);
}

void ItemBase::Actualizar ( ) {
	
}

Vector2f ItemBase::verPosicion ( ) {
	return m_sprite.getPosition();
}

