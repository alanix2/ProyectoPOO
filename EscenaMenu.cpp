#include "EscenaMenu.h"
#include <SFML/Window/Keyboard.hpp>
#include "EscenaPartida.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"

#include <sstream>
#include <iomanip>
using namespace std;
using namespace sf;

EscenaMenu::EscenaMenu(Juego &j) : Escena(j) {

	m_font.loadFromFile("assets/fonts/asap.ttf");
	for (Text &text : m_texts) {
		text.setFont(m_font);
		text.setFillColor({255,255,255});
		text.setOutlineColor({0,0,0});
		text.setOutlineThickness(1);
		
	}
	m_texts[1].setPosition(130,150);
	m_texts[1].setCharacterSize(29);
	m_texts[1].setString("Super Shooter");
	m_texts[1].setOutlineThickness(2);
	m_texts[1].setFillColor({241,214,32});
	
	m_texts[0].setPosition(420,200);
	m_texts[0].setRotation(-20);
	m_texts[0].setCharacterSize(20);
	m_texts[0].setString("Deluxe!");
	m_texts[0].setFillColor({241,51,32});
	
	m_texts[2].setPosition(45,350);
	m_texts[2].setCharacterSize(18);
	m_texts[2].setString("<presione Enter para comenzar>");
	
	stringstream pts;
	pts << "HIGHSCORE: " << setw(8) << setfill('0') << j.VerHighscore();
	m_texts[3].setString(pts.str());
	m_texts[3].setCharacterSize(25);
	m_texts[3].setPosition(100,430);
	
	
}

void EscenaMenu::Actualizar () {
	int aux = m_clock.getElapsedTime().asSeconds()*2;
	float s = aux%2;
	m_texts[2].setScale({s,s});
}

void EscenaMenu::Dibujar (RenderWindow &w ) {
	for (Text &text : m_texts)
		w.draw(text);
}

void EscenaMenu::ProcesarEvento (Event & e) {
	if (e.type==Event::KeyPressed) {
		if (e.key.code==Keyboard::Escape) m_juego.Salir();
		if (e.key.code==Keyboard::Return) m_juego.cambiarEscena(new EscenaPartida(m_juego));
	}
}

