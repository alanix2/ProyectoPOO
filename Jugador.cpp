#include "Jugador.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;
using namespace sf;


Jugador::Jugador() : PersonajeBase("assets/player/Jugador1.png") {
	m_spr.setPosition(320, 240);
	//asignacion de los controles, despues se tendria que hacer leyendo desde un archivo.
	m_der = Keyboard::D;
	m_izq = Keyboard::A;
	m_arr = Keyboard::W;
	m_aba = Keyboard::S;
	
	m_disp_arr = Keyboard::I;
	m_disp_aba = Keyboard::K;
	m_disp_izq = Keyboard::J;
	m_disp_der = Keyboard::L;

	m_spr.setOrigin(33,30);
}

void Jugador::Actualizar() {
	//controles del jugador, se podria configurar de mejor manera pero hasta ahora sirve.
	
	if (Keyboard::isKeyPressed(m_arr)){
		m_spr.move(0,-2);
	}
	if (Keyboard::isKeyPressed(m_aba)){
		m_spr.move(0,2);
	}
	if (Keyboard::isKeyPressed(m_izq)){
		m_spr.move(-2,0);
	}
	if (Keyboard::isKeyPressed(m_der)){
		m_spr.move(2,0);
	}
	
	// la idea es que en vez de que el sprite rote con las teclas de movimiento, lo haga con las teclas de disparo.
	if (Keyboard::isKeyPressed(m_disp_arr)){
		m_spr.setRotation(270); 
	}
	if (Keyboard::isKeyPressed(m_disp_aba)){
		m_spr.setRotation(90); 
	}
	if (Keyboard::isKeyPressed(m_disp_izq)){
		m_spr.setRotation(180); 
	}
	if (Keyboard::isKeyPressed(m_disp_der)){
		m_spr.setRotation(0);
	}
	
	//para mover diagonalmente al personaje
	
	if (Keyboard::isKeyPressed(m_disp_arr) && Keyboard::isKeyPressed(m_disp_izq)){
		m_spr.setRotation(225); 
	}
	if (Keyboard::isKeyPressed(m_disp_arr) && Keyboard::isKeyPressed(m_disp_der)){
		m_spr.setRotation(315);
	}
	if (Keyboard::isKeyPressed(m_disp_aba) && Keyboard::isKeyPressed(m_disp_der)){
		m_spr.setRotation(45); 
	}
	if (Keyboard::isKeyPressed(m_disp_aba) && Keyboard::isKeyPressed(m_disp_izq)){
		m_spr.setRotation(135); 
	}
}


bool Jugador::debeDisparar ( ) {
	if (m_clock.getElapsedTime().asMilliseconds()<500) return false;
	if (sePresionoDisparo()) return false;
	m_clock.restart();
	return true;
}

Disparo Jugador::generarDisparo (Texture &text) {
	Vector2f p = m_spr.getPosition();
	float ang = m_spr.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	return Disparo(text, p+25.f*d,d);
}

bool Jugador::sePresionoDisparo ( ) {
	return not Keyboard::isKeyPressed(m_disp_aba) && 
		not Keyboard::isKeyPressed(m_disp_arr) &&
		not Keyboard::isKeyPressed(m_disp_izq) &&
		not Keyboard::isKeyPressed(m_disp_der);
}

