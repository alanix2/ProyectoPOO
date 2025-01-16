#include "Juego.h"
#include <SFML/Window/Event.hpp>
using namespace sf;

Juego::Juego () : m_win(VideoMode(640,480),"Ejemplo de SFML", Style::Titlebar | Style::Close) {
	m_win.setFramerateLimit(60);
	//tendriamos que hacer que el highscore se lea desde un archivo, que tenga los 10 mejores puntajes y 3 letras
}

void Juego::Jugar (Escena *primera_escena) {
	m_EscenaActual = primera_escena;
	while(m_win.isOpen()) {
		ProcesarEventos();
		Actualizar();
		m_win.clear(Color(150,150,150,255));
		Dibujar();
		m_win.display();
		
		if (m_ProximaEscena){
			delete m_EscenaActual;
			m_EscenaActual = m_ProximaEscena;
			m_ProximaEscena = nullptr;
		}
	}
}

void Juego::ProcesarEventos(){
	Event e;
	while(m_win.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_win.close();
		else m_EscenaActual->ProcesarEvento(e);
	}
}

void Juego::Actualizar(){
	m_EscenaActual->Actualizar();
}

void Juego::Dibujar(){
	m_EscenaActual->Dibujar(m_win);
}


void Juego::cambiarEscena (Escena * nueva_escena) {
	m_ProximaEscena = nueva_escena;
}

void Juego::Salir ( ) {
	m_win.close();
}

int Juego::VerHighscore ( ) const {
	return m_highscore;
}

void Juego::ActualizarScore (int nuevo_score) {
	//Aca se tendria que guardar en un archivo
	if (nuevo_score>m_highscore) m_highscore = nuevo_score;
}

Juego::~Juego ( ) {
	delete m_EscenaActual;
}
