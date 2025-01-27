#include "PersonajeBase.h"
#include <cmath>
using namespace std;

PersonajeBase::PersonajeBase (string t, float vel) : m_vel(vel) {
	m_texture.loadFromFile(t);
	m_sprite.setTexture(m_texture);
}

void PersonajeBase::Dibujar (RenderWindow & w) {
	w.draw(m_sprite);
}

Vector2f PersonajeBase::verPosicion ( ) {
	return m_sprite.getPosition();
}


float PersonajeBase::verVel ( ) {
	return m_vel;
}

bool PersonajeBase::Colisiona (Vector2f pos) {
	Vector2f v = verPosicion()-pos;
	return sqrt(v.x*v.x+v.y*v.y)<25;
}


