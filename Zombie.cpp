#include "Zombie.h"
#include <cmath>
#include <random>
#include "ItemPuntos.h"
#include "ItemVidaExtra.h"
#include "ItemArmaTriple.h"
using namespace std;
// 2 de velocidad, 50 puntos y 2 de vida
Zombie::Zombie (Texture & t, Vector2f pos) : EnemigoBase(t,pos,2.0f,50,2) {
	m_sprite.setScale(0.5,0.5);
}

void Zombie::Actualizar (Vector2f pos_jugador) {
	AtacarJugador(pos_jugador);
	if(m_vida <= 0)
		Morir();
}

void Zombie::AtacarJugador (Vector2f pos_jugador) {
	// Calcular la direcci�n hacia el jugador
	sf::Vector2f dir = pos_jugador - m_sprite.getPosition();
	
	// Rotar el zombie hacia la direcci�n del jugador
	m_sprite.setRotation(std::atan2(dir.y,dir.x)*180/M_PI);
	
	// Normalizar el vector de direcci�n
	float longitud = sqrt(dir.x * dir.x + dir.y * dir.y);
	if (longitud != 0) {
		dir /= longitud;  // Normalizamos el vector
	}
	
	// Mover al zombie en esa direcci�n
	m_sprite.move(dir * m_velocidad);
}


unique_ptr<ItemBase> Zombie::GenerarItem (Texture & t) {
	//una verga esta cosa deberia de haber una mejor manera xd
	static random_device rd;
	static mt19937 gen(rd());
	static discrete_distribution<> distrib{70,20,10}; // Probabilidades
	
	switch(distrib(gen)) {
	case 0: // Dinero
		return make_unique<ItemPuntos>(t, m_sprite.getPosition());
	case 1: //arma 
		return make_unique<ItemArmaTriple>(t, m_sprite.getPosition());
	case 2: // Coraz�n
		return make_unique<ItemVidaExtra>(t, m_sprite.getPosition());
	default:
		return nullptr;
	}
}
