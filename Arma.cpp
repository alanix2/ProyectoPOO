#include "Arma.h"

Arma::Arma (float delayDisparos) : m_delayDisparos(delayDisparos) {
	m_bala_textura.loadFromFile("assets/player/bullet.png");
}

