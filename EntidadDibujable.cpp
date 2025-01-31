#include "EntidadDibujable.h"
#include <SFML/Graphics/Rect.hpp>

EntidadDibujable::EntidadDibujable ( ) {
	
}

EntidadDibujable::EntidadDibujable (Texture & t) {
	m_sprite.setTexture(t);
	m_sprite.setOrigin((t.getSize().x/2)/2,(t.getSize().y/2)/2);
}

EntidadDibujable::EntidadDibujable (Texture & t, IntRect TexturePortion) {
	m_sprite.setTexture(t);
	m_sprite.setTextureRect(TexturePortion);
	FloatRect bounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(bounds.width/2.0f, bounds.height/2.0f);
}

void EntidadDibujable::Dibujar (RenderWindow & w) {
	w.draw(m_sprite);
}

FloatRect EntidadDibujable::verHitbox ( ) {
	return m_sprite.getGlobalBounds();
}

Vector2f EntidadDibujable::verPosicion ( ) {
	return m_sprite.getPosition();
}

