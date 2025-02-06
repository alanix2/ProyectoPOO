#include "DisparoNormal.h"
#include <cmath>
using namespace std;


DisparoNormal::DisparoNormal (Texture & t, Vector2f pos, Vector2f dir, float vel) : Disparo(t,pos,dir) {
	m_velocidad = dir * vel;
}

void DisparoNormal::Actualizar () {
	m_sprite.move(m_velocidad);
}

bool DisparoNormal::Colisiona (Vector2f pos) {
	Vector2f v = m_sprite.getPosition()-pos;
	return sqrt(v.x*v.x+v.y*v.y)<25;
	//return m_sprite.getGlobalBounds().contains(pos);
}
