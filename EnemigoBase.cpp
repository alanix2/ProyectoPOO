#include "EnemigoBase.h"
#include <cmath>
using namespace std;

EnemigoBase::EnemigoBase (Texture & t, Vector2f pos, float vel, int puntos) : m_velocidad(vel), m_puntos(puntos){
	m_sprite.setTexture(t);
	m_sprite.setPosition(pos);
	m_sprite.setOrigin(t.getSize().x/2 ,t.getSize().y/2);
}

void EnemigoBase::Actualizar (Vector2f pos_jugador) {
	
}

Vector2f EnemigoBase::verPosicion ( ) {
	return m_sprite.getPosition();
}

int EnemigoBase::verPuntos ( ) {
	return m_puntos;
}

float EnemigoBase::verVelocidad ( ) {
	return m_velocidad;
}

void EnemigoBase::Dibujar (RenderWindow & w) {
	w.draw(m_sprite);
}

bool EnemigoBase::Colisiona (Vector2f pos) {
	Vector2f v = verPosicion()-pos;
	return sqrt(v.x*v.x+v.y*v.y)<25;
}

