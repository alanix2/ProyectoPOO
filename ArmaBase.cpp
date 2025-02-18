#include "ArmaBase.h"
#include <cmath>
using namespace std;

//<- FUNCIONES AUXILIARES

bool fuera_de_la_pantalla(Disparo &d) {
	Vector2f p = d.verPosicion();
	if (p.x<0 or p.x>640) return true;
	if (p.y<0 or p.y>480) return true;
	return false;
}
// ->

ArmaBase::ArmaBase() : Arma(200) {

}

void ArmaBase::Disparar (Vector2f pos, float rotation) {
	if (debeDisparar()){
		float ang = rotation * static_cast<float>(M_PI) / 180.f;
		Vector2f dir(cos(ang), sin(ang));
		m_balas.push_back(DisparoNormal(m_bala_textura, pos + 25.f * dir, dir));
		m_temporizadorDisparo.restart();
	}
}

bool ArmaBase::debeDisparar ( ) {
	return m_temporizadorDisparo.getElapsedTime() >= m_intervaloDisparo;
}

void ArmaBase::Actualizar ( ) {
	for(auto &b : m_balas){
			b.Actualizar();
	}
	auto it = remove_if(m_balas.begin(),m_balas.end(),fuera_de_la_pantalla);
	m_balas.erase(it,m_balas.end());
	
}

void ArmaBase::Dibujar (RenderWindow & w) {
	for(auto &b : m_balas)
		b.Dibujar(w);
}

