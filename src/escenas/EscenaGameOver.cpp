#include "EscenaGameOver.h"
#include "EscenaPartida.h"
#include "EscenaMenu.h"
#include "../core/Juego.h"
#include <sstream>
#include <iomanip>
using namespace std;

EscenaGameOver::EscenaGameOver (Juego &j, int puntos) : Escena(j) {
	m_font.loadFromFile("assets/fonts/asap.ttf");
	m_text.setFont(m_font);
	m_text.setPosition(250,250);
	m_text.setCharacterSize(50);
	stringstream pts;
	pts << "SCORE: " << setw(8) << setfill('0') << puntos ;
	m_text.setString(pts.str());
	m_text.setFillColor({255,128,128});
}

void EscenaGameOver::Actualizar () {
	int aux = m_clock.getElapsedTime().asSeconds()*2;
	float s = aux%2;
	m_text.setScale({s,s});
}

void EscenaGameOver::Dibujar (RenderWindow & w) {
	w.clear({0,0,0});
	w.draw(m_text);
}

void EscenaGameOver::ProcesarEvento (Event &e){
	if (e.type==Event::KeyPressed) {
		if (e.key.code==Keyboard::Escape) m_juego.Salir();
		if (e.key.code==Keyboard::Return) m_juego.cambiarEscena(new EscenaMenu(m_juego));
	}
}

