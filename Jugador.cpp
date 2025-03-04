#include "Jugador.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

Jugador::Jugador() : m_armaEquipada(make_unique<ArmaBase>()){
	m_texture.loadFromFile("assets/player/player.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(IntRect(0,0,32,16));
	m_sprite.setOrigin((m_texture.getSize().x/2)/2,(m_texture.getSize().y/2)/2);
	ConfigurarControles();
	m_sprite.setPosition(320,240);
}

void Jugador::Dibujar (RenderWindow & w) {
	w.draw(m_sprite);
	m_armaEquipada->Dibujar(w);
}

void Jugador::Actualizar() {
	mover();
	rotarSprite();
	m_armaEquipada->Actualizar();
	if(sePresionoDisparo()){
		m_armaEquipada->Disparar(m_sprite.getPosition(), m_sprite.getRotation());
	}
}

void Jugador::moverPosicion (Vector2f pos) {
	m_sprite.setPosition(pos);
}

bool Jugador::sePresionoDisparo ( ) {
	return Keyboard::isKeyPressed(m_disp_aba) or 
	Keyboard::isKeyPressed(m_disp_arr) or
	Keyboard::isKeyPressed(m_disp_izq) or
	Keyboard::isKeyPressed(m_disp_der);
}	

void Jugador::CambiarArma (unique_ptr<Arma> nuevaArma) {
	m_armaEquipada = move(nuevaArma);
}

bool Jugador::lograAtacar (FloatRect hb) {
	return m_armaEquipada->VerificarColision(hb);
}

int Jugador::verDanioArma ( ) {
	return m_armaEquipada->verDanio();
}

void Jugador::restarVida ( ) {
	m_vidas--;
}
	
void Jugador::sumarVida ( ) {
	m_vidas++;
}
	
int Jugador::verVidas ( ) {
	return m_vidas;
}
	
void Jugador::sumarPuntos (int n) {
	m_puntajeActual+=n;
}
	
int Jugador::verPuntos ( ) {
	return m_puntajeActual;
}

void Jugador::ConfigurarControles ( ) {
	//asignacion de los controles, despues se tendria que hacer leyendo desde un archivo.
	m_der = Keyboard::D;
	m_izq = Keyboard::A;
	m_arr = Keyboard::W;
	m_aba = Keyboard::S;
	
	m_disp_arr = Keyboard::I;
	m_disp_aba = Keyboard::K;
	m_disp_izq = Keyboard::J;
	m_disp_der = Keyboard::L;
}

void Jugador::mover ( ) {
	Vector2f movimiento(0.0f, 0.0f);
	
	// Verificar si las teclas están presionadas y asignar la dirección
	if (sf::Keyboard::isKeyPressed(m_arr)) {
		movimiento.y -= 1.0f; // Movimiento hacia arriba
	}
	if (sf::Keyboard::isKeyPressed(m_aba)) {
		movimiento.y += 1.0f; // Movimiento hacia abajo
	}
	if (sf::Keyboard::isKeyPressed(m_izq)) {
		movimiento.x -= 1.0f; // Movimiento hacia la izquierda
	}
	if (sf::Keyboard::isKeyPressed(m_der)) {
		movimiento.x += 1.0f; // Movimiento hacia la derecha
	}
	
	// Normalizar el vector de movimiento (para que el jugador se mueva a la misma velocidad en todas las direcciones)
	// Esto es porque normalmente cuando movemos a un personaje diagonalmente, la velocidad suele ser mayor, este codigo arregla eso
	if (movimiento.x != 0.0f || movimiento.y != 0.0f) {
		float longitud = sqrt(movimiento.x * movimiento.x + movimiento.y * movimiento.y);
		movimiento /= longitud;  // Normalizar
		
		// Mover al jugador con la velocidad
		m_sprite.move(movimiento * m_velocidad);
	}
}

void Jugador::rotarSprite ( ) {
	Vector2f direccion(0.f, 0.f);
	
	if (Keyboard::isKeyPressed(m_disp_arr)) {
		direccion.y -= 1.f; // Arriba
	}
	if (Keyboard::isKeyPressed(m_disp_aba)) {
		direccion.y += 1.f; // Abajo
	}
	if (Keyboard::isKeyPressed(m_disp_izq)) {
		direccion.x -= 1.f; // Izquierda
	}
	if (Keyboard::isKeyPressed(m_disp_der)) {
		direccion.x += 1.f; // Derecha
	}
	
	// Si el jugador presiona alguna tecla, rota el sprite
	if (direccion != Vector2f(0.f, 0.f)) {
		float angulo = atan2(direccion.y, direccion.x) * 180 / M_PI;
		m_sprite.setRotation(angulo);
	}
}
