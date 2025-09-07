#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;
//esta es la clase base/prototipo para las escenas
//el juego tiene varias escenas, como el menu, la partida, los resultados o game over, etc
//de momento solo hay 3 escenas, pero podriamos hacer mas.
class Juego;

class Escena {
public:
	Escena(Juego &j) : m_juego(j){}
	virtual void Actualizar() = 0;
	virtual void Dibujar(RenderWindow &w) = 0;
	virtual void ProcesarEvento(Event &e){}
	virtual ~Escena() {}
protected:
	Juego &m_juego;

};

#endif
