#include "Zombie.h"
#include <cmath>

Zombie::Zombie (Texture & t, Vector2f pos) : EnemigoBase(t,pos,2.0f,50) {
	m_sprite.setScale(0.5,0.5);
}

void Zombie::Actualizar ( ) {
	
}

void Zombie::Actualizar (Vector2f pos_jugador) {
	AtacarJugador(pos_jugador);
}

void Zombie::AtacarJugador (Vector2f pos_jugador) {
	// Calcular la direcci�n hacia el jugador
	sf::Vector2f dir = pos_jugador - m_sprite.getPosition();
	
	// Rotar el zombie hacia la direcci�n del jugador
	m_sprite.setRotation(std::atan2(dir.y,dir.x)*180/M_PI);
	
	// Normalizar el vector de direcci�n
	float longitud = std::sqrt(dir.x * dir.x + dir.y * dir.y);
	if (longitud != 0) {
		dir /= longitud;  // Normalizamos el vector
	}
	
	// Mover al zombie en esa direcci�n
	m_sprite.move(dir * m_velocidad);
}



FloatRect Zombie::verHitbox ( ) {
	FloatRect hitbox = m_sprite.getGlobalBounds();
//	hitbox.left += 30.f;  // Reducir margen izquierdo
//	hitbox.top += 30.f;   // Reducir margen superior
	hitbox.width -= 25.f; // Hacer el hitbox m�s angosto
	hitbox.height -= 25.f; // Hacer el hitbox m�s bajo
	return hitbox;
}

