#include "Jugador.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include "DisparoNormal.h"

using namespace std;
using namespace sf;

Jugador::Jugador() {
	m_texture.loadFromFile("assets/player/player.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(IntRect(0,0,32,16));
	m_sprite.setOrigin((m_texture.getSize().x/2)/2,(m_texture.getSize().y/2)/2);
	ConfigurarControles();
	m_sprite.setPosition(320,240);
}

void Jugador::Actualizar() {
	mover();
	rotarSprite();
}

unique_ptr<Disparo> Jugador::generarDisparo (Texture &t) {
	Vector2f pos = m_sprite.getPosition();
	float ang = m_sprite.getRotation() * static_cast<float>(M_PI) / 180.f;
	Vector2f dir(cos(ang), sin(ang));
	
	switch(m_tipoDisparoActual) {
		case TipoDisparo::Normal:
			return make_unique<DisparoNormal>(t, pos + 25.f * dir, dir);
		//case mas tipos...
		default:
			return nullptr;
	}
}

bool Jugador::debeDisparar ( ) {
	return (m_temporizadorDisparo.getElapsedTime() >= m_intervaloDisparo && sePresionoDisparo());
}

bool Jugador::sePresionoDisparo ( ) {
	return Keyboard::isKeyPressed(m_disp_aba) or 
	Keyboard::isKeyPressed(m_disp_arr) or
	Keyboard::isKeyPressed(m_disp_izq) or
	Keyboard::isKeyPressed(m_disp_der);
}	

	
void Jugador::ReestablecerTemporizadorDisparo ( ) {
	m_temporizadorDisparo.restart();
}
	
void Jugador::CambiarArma (TipoDisparo nuevaArma) {
	m_tipoDisparoActual = nuevaArma;
	// Configurar parámetros específicos del arma
	switch(nuevaArma) {
		case TipoDisparo::Normal:
			m_intervaloDisparo = sf::milliseconds(200);
			break;
	}
}

void Jugador::restarVida ( ) {
	m_vidas--;
	m_sprite.setPosition(320,240);
}
	
void Jugador::sumarVida ( ) {
	m_vidas++;
}
	
int Jugador::verVidas ( ) {
	return m_vidas;
}
	
void Jugador::sumarPuntos (int n) {
	PuntajeActual+=n;
}
	
int Jugador::verPuntos ( ) {
	return PuntajeActual;
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
