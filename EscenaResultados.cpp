#include "EscenaResultados.h"
#include "EscenaPartida.h"
#include "Juego.h"
#include "EscenaMenu.h"

EscenaResultados::EscenaResultados (Juego &j, int puntos) : Escena(j) {
	m_font.loadFromFile("asap.ttf");
	
	m_text.setFont(m_font);
	m_text.setPosition(250,250);
	m_text.setCharacterSize(40);
	m_text.setString("Score: "+std::to_string(puntos));
	m_text.setFillColor({255,128,128});
}

void EscenaResultados::Actualizar () {
	int aux = m_clock.getElapsedTime().asSeconds()*2;
	float s = aux%2;
	m_text.setScale({s,s});
}

void EscenaResultados::Dibujar (RenderWindow & w) {
	w.clear({0,0,0});
	w.draw(m_text);
}

void EscenaResultados::ProcesarEvento (Event &e){
	if (e.type==Event::KeyPressed) {
		if (e.key.code==Keyboard::Escape) m_juego.Salir();
		if (e.key.code==Keyboard::Return) m_juego.cambiarEscena(new EscenaMenu(m_juego));
	}
}

