#include "DisparoNormal.h"

DisparoNormal::DisparoNormal (Texture & t, Vector2f pos, Vector2f dir) : Disparo(t,IntRect(256,160,16,16),pos,dir, 3.0f) {
	
}

void DisparoNormal::Actualizar () {
	m_sprite.move(m_velocidad);
}
