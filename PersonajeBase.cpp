#include "PersonajeBase.h"

PersonajeBase::PersonajeBase (std::string NombreTextura) {
	m_tex.loadFromFile(NombreTextura);
	m_spr.setTexture(m_tex);
}

void PersonajeBase::Dibujar (RenderWindow & w) {
	w.draw(m_spr);
}

Vector2f PersonajeBase::verPosicion ( ) {
	return m_spr.getPosition();
}


