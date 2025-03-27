#include "ArmaNormal.h"
#include <cmath>
using namespace std;

ArmaNormal::ArmaNormal() : Arma(1, 300) {

}

//actualiza cada bala que hay en el vector y destruye las que estan inactivas o fuera de la pantalla
void ArmaNormal::Actualizar ( ) {

	for(auto &b : m_balas){
			b.Actualizar();
	}
	
	destruirFueraDePantalla();
	destruirInactivos();
	
}

void ArmaNormal::Dibujar (RenderWindow & w) {
	for(auto &b : m_balas)
		b.Dibujar(w);
}

//dispara dependiendo de la posicion del jugador y a donde esté apuntando.
//si pasó el tiempo suficiente entre cada disparo, agrega una bala al vector y reinicia el reloj.
void ArmaNormal::Disparar (Vector2f pos, float rotation) {
	if (debeDisparar()){
		float ang = rotation * static_cast<float>(M_PI) / 180.f;
		Vector2f dir(cos(ang), sin(ang));
		m_balas.push_back(DisparoNormal(m_bala_textura, pos + 25.f * dir, dir));
		m_temporizadorDisparo.restart();
	}
}

//verifica si cada una de las balas colisionó con la hitbox.
////si lo hace, marca como destruido a la bala que colisionó y retorna true.
bool ArmaNormal::VerificarColision (FloatRect & hb) {
	for(auto &b : m_balas){
		if(b.verHitbox().intersects(hb)){
			b.Destruir();
			return true;
		}
	}
	return false;
}

//destruye del vector todas las balas que estan fuera de la pantalla...
void ArmaNormal::destruirFueraDePantalla ( ) {
	auto it = remove_if(m_balas.begin(),m_balas.end(),fuera_de_la_pantalla);
	m_balas.erase(it,m_balas.end());
}

//... o las que estan marcadas como inactivas
void ArmaNormal::destruirInactivos ( ) {
	auto it = remove_if(m_balas.begin(),m_balas.end(),esta_destruido);
	m_balas.erase(it,m_balas.end());
}
