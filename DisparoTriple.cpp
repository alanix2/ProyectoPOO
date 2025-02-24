#include "DisparoTriple.h"

DisparoTriple::DisparoTriple (Texture & t, Vector2f pos, Vector2f dir) : Disparo(t,IntRect(0,17,16,16),pos,dir,5.0f){
	
}

void DisparoTriple::Actualizar ( ) {
	m_sprite.move(m_velocidad);
}

