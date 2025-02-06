#include "Disparo.h"
#include <cmath>

Disparo::Disparo(Texture &t, Vector2f pos, Vector2f dir) : EntidadDibujable(t, IntRect(256,160,16,16) ) {
	m_sprite.setPosition(pos);
	m_sprite.setRotation(atan2(dir.y,dir.x) * 180/ static_cast<float>(M_PI));
}
