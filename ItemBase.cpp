#include "ItemBase.h"

ItemBase::ItemBase() {
	m_texture.loadFromFile("assets/item/Power.png)");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(8,8);
}


void ItemBase::RecogerItem (Jugador & j) {
	
}

