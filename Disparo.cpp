#include "Disparo.h"
#include <cmath>

//necesita la textura, porci�n de la textura, la posici�n, direcci�n y velocidad.
Disparo::Disparo(Texture &t,IntRect TexturePortion, Vector2f pos, Vector2f dir, float vel) : EntidadDibujable(t,TexturePortion) {
	m_sprite.setPosition(pos);
	m_sprite.setRotation(atan2(dir.y,dir.x) * 180 / static_cast<float>(M_PI));
	m_velocidad = dir * vel;
}

void Disparo::Destruir ( ) {
	m_destruido = true;
}

bool Disparo::verEstado ( ) {
	return m_destruido;
}

