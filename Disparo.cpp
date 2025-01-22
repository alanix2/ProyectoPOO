#include "Disparo.h"
#include <cmath>

Disparo::Disparo(Texture &text, Vector2f pos, Vector2f dir) {
	m_sprite.setTexture(text);
	m_sprite.setTextureRect(IntRect(256,160,16,16));
	m_sprite.setPosition(pos);
	m_sprite.setOrigin(8,8);
	m_sprite.rotate(atan2(dir.y,dir.x)*180/M_PI);
	m_vel = dir*3.f;
}

void Disparo::Actualizar ( ) {
	m_sprite.move(m_vel);
}

void Disparo::Dibujar(RenderWindow &w) {
	w.draw(m_sprite);
}

Vector2f Disparo::verPosicion ( ) {
	return m_sprite.getPosition();
}


bool Disparo::Colisiona (Vector2f pos) {
	Vector2f v = verPosicion()-pos;
	return sqrt(v.x*v.x+v.y*v.y)<25;
}

