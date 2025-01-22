#include "Zombie.h"
#include <cmath>

Zombie::Zombie (sf::Texture & t, sf::Vector2f pos) : EnemigoBase(t,pos,2.0f,50) {
	m_sprite.setScale(0.5,0.5);
}

void Zombie::Actualizar (sf::Vector2f pos_jugador) {
	AtacarJugador(pos_jugador);
}

void Zombie::AtacarJugador (sf::Vector2f pos_jugador) {
	// Calcular la dirección hacia el jugador
	sf::Vector2f dir = pos_jugador - m_sprite.getPosition();
	
	// Rotar el zombie hacia la dirección del jugador
	m_sprite.setRotation(std::atan2(dir.y,dir.x)*180/M_PI);
	
	// Normalizar el vector de dirección
	float longitud = std::sqrt(dir.x * dir.x + dir.y * dir.y);
	if (longitud != 0) {
		dir /= longitud;  // Normalizamos el vector
	}
	
	// Mover al zombie en esa dirección
	m_sprite.move(dir * m_velocidad);
}

