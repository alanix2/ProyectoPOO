#include "Arma.h"

Arma::Arma (float delayDisparos) : m_delayDisparos(delayDisparos) {
	m_bala_textura.loadFromFile("assets/player/bullet.png");
}

bool Arma::debeDisparar ( ) {
	return m_temporizadorDisparo.getElapsedTime() >= m_intervaloDisparo;
}

bool Arma::fuera_de_la_pantalla (Disparo & d) {
	Vector2f p = d.verPosicion();
	if (p.x<0 or p.x>640) return true;
	if (p.y<0 or p.y>480) return true;
	return false;
}
