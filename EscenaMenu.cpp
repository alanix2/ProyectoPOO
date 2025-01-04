#include "EscenaMenu.h"
#include <SFML/Window/Keyboard.hpp>
#include "EscenaPartida.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"

using namespace sf;

EscenaMenu::EscenaMenu(Juego &j) : Escena(j) {
	m_font.loadFromFile("asap.ttf");
	for (Text &text : m_texts) {
		text.setFont(m_font);
		text.setFillColor({255,255,255});
		text.setOutlineColor({0,0,0});
		text.setOutlineThickness(1);
		m_texts[3].setCharacterSize(30);
	}
	m_texts[1].setPosition(90,150);
	m_texts[1].setCharacterSize(80);
	m_texts[1].setString("Super Shooter");
	m_texts[1].setOutlineThickness(2);
	m_texts[1].setFillColor({241,214,32});
	
	m_texts[0].setPosition(420,250);
	m_texts[0].setRotation(-20);
	m_texts[0].setCharacterSize(40);
	m_texts[0].setString("Deluxe!");
	m_texts[0].setFillColor({241,51,32});
	
	m_texts[2].setPosition(90,350);
	m_texts[2].setString("<presione Enter para comenzar>");
	
	m_texts[3].setPosition(230,430);
	m_texts[3].setString("Highscore: " + to_string(j.VerHighscore()));
	
	m_texts[4].setPosition(0,440);
	m_texts[4].setString("Hola");
	
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

