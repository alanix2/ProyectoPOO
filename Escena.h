#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;

class Juego;

class Escena {
public:
	Escena(Juego &j) : m_juego(j){}
	virtual void Actualizar() = 0;
	virtual void Dibujar(RenderWindow &w) = 0;
	virtual void ProcesarEvento(Event &e){}
protected:
	Juego &m_juego;

};

#endif
