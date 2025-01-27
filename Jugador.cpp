#include "Jugador.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;
using namespace sf;


Jugador::Jugador() : PersonajeBase("assets/player/SpriteSheetGuns.png", 2.5f) {
	ConfigurarControles();
	m_sprite.setTextureRect(IntRect(0,48,48,48));
	m_sprite.setOrigin((m_texture.getSize().x/2)/2,(m_texture.getSize().y/2)/2);
	m_sprite.setPosition(320,240);
}

void Jugador::Actualizar() {
	mover();
	rotarSprite();
}

/* 
seccion de disparo, habria que ver si esto se podria hacer de mejor manera
 en vez de hacer tantos metodos 
*/

bool Jugador::debeDisparar ( ) {
	if (m_clock.getElapsedTime().asMilliseconds()<300){
		return false;
	}
	if (not sePresionoDisparo()){
		m_sprite.setTextureRect(IntRect(0,48,48,48));
		return false;
	}
	m_clock.restart();
	return true;
}

Disparo Jugador::generarDisparo (Texture &text) {
	m_sprite.setTextureRect(IntRect(48,48,48,48));
	Vector2f p = m_sprite.getPosition();
	float ang = m_sprite.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	return Disparo(text, p+25.f*d,d);
}

bool Jugador::sePresionoDisparo ( ) {
	return Keyboard::isKeyPressed(m_disp_aba) or 
		Keyboard::isKeyPressed(m_disp_arr) or
		Keyboard::isKeyPressed(m_disp_izq) or
		Keyboard::isKeyPressed(m_disp_der);
}

/*fin seccion disparo*/

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

int Jugador::verPuntos ( ) {
	return PuntajeActual;
}

void Jugador::sumarPuntos (int n) {
	PuntajeActual+=n;
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
	if (movimiento.x != 0.0f || movimiento.y != 0.0f) {
		float longitud = sqrt(movimiento.x * movimiento.x + movimiento.y * movimiento.y);
		movimiento /= longitud;  // Normalizar
		
		// Mover al jugador con la velocidad
		m_sprite.move(movimiento * verVel());
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

void Jugador::restarVida ( ) {
	m_vidas--;
	//cuando pierde una vida vuelve a la posicion inicial. luego se tendria que
	//implementar mejor, como reiniciando el nivel
	m_sprite.setPosition(320,240);
	
}

void Jugador::sumarVida ( ) {
	m_vidas++;
}

int Jugador::verVidas ( ) {
	return m_vidas;
}

