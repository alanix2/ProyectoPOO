#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;

class Juego {
public:
	Juego();
	void Jugar(Escena *primera_escena);
	void cambiarEscena(Escena *nueva_escena);
	void Salir();
	int VerHighscore() const;
	void ActualizarScore(int nuevo_score);
	~Juego();
	
private:
	void Actualizar();
	void Dibujar();
	void ProcesarEventos();
	void leerHighscore(); //leer el archivo con los highscores al iniciar
	void guardarHighscore(); //guardar el score en un archivo
	RenderWindow m_win; //la ventana xd
	Escena *m_EscenaActual = nullptr, *m_ProximaEscena = nullptr; //Escena actual y proxima escena
	
	int highscore = 0; //de momento solo puse un int, pero luego deberiamos poner un vector
	string filename; //nombre del archivo para guardar los scores
};

#endif
