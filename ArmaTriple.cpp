#include "ArmaTriple.h"
#include <cmath>
using namespace std;

//las funciones hacen casi lo mismo que las del arma base, solo que para 3 vectores en vez de uno.

ArmaTriple::ArmaTriple() : Arma(3, 200) {
	
}

void ArmaTriple::Actualizar ( ) {

	for(auto &b : m_balas1){
		b.Actualizar();
	}
	for(auto &b : m_balas2){
		b.Actualizar();
	}
	for(auto &b : m_balas3){
		b.Actualizar();
	}
	
	destruirFueraDePantalla();
	destruirInactivos();
}

void ArmaTriple::Dibujar (RenderWindow & w) {
	for(auto &b : m_balas1)
		b.Dibujar(w);
	for(auto &b : m_balas2)
		b.Dibujar(w);
	for(auto &b : m_balas3)
		b.Dibujar(w);
}

void ArmaTriple::Disparar (Vector2f pos, float rotation) {
	if (debeDisparar()){
		float ang1 = rotation * static_cast<float>(M_PI) / 180.f;
		float ang2 = (rotation - 10) * static_cast<float>(M_PI) / 180.f;
		float ang3 = (rotation + 10) * static_cast<float>(M_PI) / 180.f;
	
		Vector2f dir1(cos(ang1), sin(ang1));
		Vector2f dir2(cos(ang2), sin(ang2));
		Vector2f dir3(cos(ang3), sin(ang3));
		
		m_balas1.push_back(DisparoTriple(m_bala_textura, pos + 25.f * dir1, dir1));
		m_balas2.push_back(DisparoTriple(m_bala_textura, pos + 25.f * dir2, dir2));
		m_balas3.push_back(DisparoTriple(m_bala_textura, pos + 25.f * dir3, dir3));
		m_temporizadorDisparo.restart();
	}
}


bool ArmaTriple::VerificarColision (FloatRect & hb) {
	for(auto &b : m_balas1){
		if(b.verHitbox().intersects(hb)){
			b.Destruir();
			return true;
		}
	}
	for(auto &b : m_balas2){
		if(b.verHitbox().intersects(hb)){
			b.Destruir();
			return true;
		}
	}
	for(auto &b : m_balas3){
		if(b.verHitbox().intersects(hb)){
			b.Destruir();
			return true;
		}
	}
	return false;
}

void ArmaTriple::destruirFueraDePantalla ( ) {
	auto it = remove_if(m_balas1.begin(),m_balas1.end(),fuera_de_la_pantalla);
	m_balas1.erase(it,m_balas1.end());
	
	it = remove_if(m_balas2.begin(),m_balas2.end(),fuera_de_la_pantalla);
	m_balas2.erase(it,m_balas2.end());
	
	it = remove_if(m_balas3.begin(),m_balas3.end(),fuera_de_la_pantalla);
	m_balas3.erase(it,m_balas3.end());
}

void ArmaTriple::destruirInactivos ( ) {
	auto it = remove_if(m_balas1.begin(),m_balas1.end(),esta_destruido);
	m_balas1.erase(it,m_balas1.end());
	it = remove_if(m_balas2.begin(),m_balas2.end(),esta_destruido);
	m_balas2.erase(it,m_balas2.end());
	it = remove_if(m_balas3.begin(),m_balas3.end(),esta_destruido);
	m_balas3.erase(it,m_balas3.end());
}
