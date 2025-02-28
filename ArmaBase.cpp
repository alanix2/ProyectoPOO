#include "ArmaBase.h"
#include <cmath>
using namespace std;

ArmaBase::ArmaBase() : Arma(1, 300) {

}

void ArmaBase::Actualizar ( ) {
	for(auto &b : m_balas){
			b.Actualizar();
	}
	
	destruirFueraDePantalla();
	destruirInactivos();
	
}

void ArmaBase::Dibujar (RenderWindow & w) {
	for(auto &b : m_balas)
		b.Dibujar(w);
}

void ArmaBase::Disparar (Vector2f pos, float rotation) {
	if (debeDisparar()){
		float ang = rotation * static_cast<float>(M_PI) / 180.f;
		Vector2f dir(cos(ang), sin(ang));
		m_balas.push_back(DisparoNormal(m_bala_textura, pos + 25.f * dir, dir));
		m_temporizadorDisparo.restart();
	}
}

bool ArmaBase::VerificarColision (FloatRect & hb) {
	for(auto &b : m_balas){
		if(b.verHitbox().intersects(hb)){
			b.Destruir();
			return true;
		}
	}
	return false;
}

void ArmaBase::destruirFueraDePantalla ( ) {
	auto it = remove_if(m_balas.begin(),m_balas.end(),fuera_de_la_pantalla);
	m_balas.erase(it,m_balas.end());
}

void ArmaBase::destruirInactivos ( ) {
	auto it = remove_if(m_balas.begin(),m_balas.end(),esta_destruido);
	m_balas.erase(it,m_balas.end());
}
