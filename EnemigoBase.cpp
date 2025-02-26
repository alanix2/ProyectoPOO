#include "EnemigoBase.h"
#include <cmath>
using namespace std;

EnemigoBase::EnemigoBase (Texture & t, Vector2f pos, float vel, int puntos, int vida) : EntidadDibujable(t) , m_velocidad(vel), m_puntos(puntos), m_vida(vida) {
	m_sprite.setPosition(pos);
}

void EnemigoBase::restarVida (int danio) {
	m_vida -= danio;

}

int EnemigoBase::verVida ( ) {
	return m_vida;
}

int EnemigoBase::verPuntos ( ) {
	return m_puntos;
}

float EnemigoBase::verVelocidad ( ) {
	return m_velocidad;
}


