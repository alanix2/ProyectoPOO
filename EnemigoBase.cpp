#include "EnemigoBase.h"

EnemigoBase::EnemigoBase (sf::Texture & t, sf::Vector2f pos, float vel, int puntos) : m_velocidad(vel), m_puntos(puntos){
	m_sprite.setTexture(t);
	m_sprite.setPosition(pos);
}

void EnemigoBase::Actualizar (sf::Vector2f pos_jugador) {
	
}

sf::Vector2f EnemigoBase::verPosicion ( ) {
	return m_sprite.getPosition();
}

int EnemigoBase::verPuntos ( ) {
	return m_puntos;
}

float EnemigoBase::verVelocidad ( ) {
	return m_velocidad;
}

void EnemigoBase::Dibujar (sf::RenderWindow & w) {
	w.draw(m_sprite);
}

