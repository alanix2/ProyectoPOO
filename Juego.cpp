#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;

Juego::Juego () : m_win(VideoMode(640,480),"Super Shooter Deluxe", Style::Titlebar | Style::Close) {
	leerHighscore();
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
	return highscore;
}

void Juego::leerHighscore ( ) {
	ifstream inFile(filename, std::ios::binary);
	if (inFile) {
		inFile.read(reinterpret_cast<char*>(&highscore), sizeof(highscore));
		if (!inFile) {
			cerr << "Error leyendo el highscore del archivo.\n";
			highscore = 0;
		}
	} else {
		// Si el archivo no existe, crear uno con highscore de 0
		highscore = 0;
		guardarHighscore();
	}
	inFile.close();
}

void Juego::guardarHighscore ( ) {
	std::ofstream outFile(filename, std::ios::binary);
	if (outFile) {
		outFile.write(reinterpret_cast<const char*>(&highscore), sizeof(highscore));
		if (!outFile) {
			std::cerr << "Error escribiendo el highscore en el archivo.\n";
		}
	}
	outFile.close();
}

void Juego::ActualizarScore (int nuevo_score) {
	//Aca se tendria que guardar en un archivo
	if (nuevo_score>highscore){
		highscore = nuevo_score;
		guardarHighscore();
	}
}

Juego::~Juego ( ) {
	delete m_EscenaActual;
}
