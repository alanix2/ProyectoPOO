#include "EnemigoBase.h"
#include <cmath>
using namespace std;

EnemigoBase::EnemigoBase (Texture & t, Vector2f pos, float vel, int puntos) : EntidadDibujable(t) , m_velocidad(vel), m_puntos(puntos){
	m_sprite.setPosition(pos);
}


int EnemigoBase::verPuntos ( ) {
	return m_puntos;
}

float EnemigoBase::verVelocidad ( ) {
	return m_velocidad;
}
