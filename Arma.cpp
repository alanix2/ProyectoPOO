#include "Arma.h"

Arma::Arma (int danio, float delayDisparos) : m_danio(danio), m_delayDisparos(delayDisparos) {
	m_bala_textura.loadFromFile("assets/player/bullet.png");
}

bool Arma::debeDisparar ( ) {
	return m_temporizadorDisparo.getElapsedTime() > m_intervaloDisparo;
}

int Arma::verDanio ( ) {
	return m_danio;
}

bool Arma::fuera_de_la_pantalla (Disparo & d) {
	Vector2f p = d.verPosicion();
	//si la posición está fuera de la pantalla visible, se devuelve true.
	//a lo mejor podria cambiarlo para los bordes de las paredes.
	if (p.x<0 or p.x>640) return true;
	if (p.y<0 or p.y>480) return true;
	return false;
}

bool Arma::esta_destruido (Disparo & d) {
	return d.verEstado();
}
