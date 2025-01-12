#include "PersonajeBase.h"

PersonajeBase::PersonajeBase (string t, float vel) : m_vel(vel) {
	m_texture.loadFromFile(t);
	m_spr.setTexture(m_texture);
}

void PersonajeBase::Dibujar (RenderWindow & w) {
	w.draw(m_spr);
}

Vector2f PersonajeBase::verPosicion ( ) {
	return m_spr.getPosition();
}


float PersonajeBase::verVel ( ) {
	return m_vel;
}

