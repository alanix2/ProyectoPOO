#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Juego {
public:
	Juego();
	void Jugar(Escena *primera_escena);
	void ProcesarEventos();
	void Dibujar();
	void cambiarEscena(Escena *nueva_escena);
	void Salir();
	int VerHighscore() const;
	void Actualizar();
	void ActualizarScore(int nuevo_score);
	~Juego();
	
private:
	RenderWindow m_win;
	Escena *m_EscenaActual = nullptr, *m_ProximaEscena = nullptr; //Escena actual y proxima escena
	
	//mayor puntaje, esto se tendria que guardar y leer desde un archivo y poder mostrar los mejores puntajes.
	int m_highscore = 0;
};

#endif
