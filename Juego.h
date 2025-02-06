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
	void leerHighscore();
	void guardarHighscore();
	RenderWindow m_win;
	Escena *m_EscenaActual = nullptr, *m_ProximaEscena = nullptr; //Escena actual y proxima escena
	
	float deltaTime;
	Clock reloj;
	
	//luego habria que poner los 10 mayores puntajes junto a las primeras 3 iniciales.
	int highscore = 0;
	string filename = "savedata.bin";
};

#endif
