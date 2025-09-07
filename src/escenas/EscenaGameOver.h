#ifndef ESCENAGAMEOVER_H
#define ESCENAGAMEOVER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include "Escena.h"

//esto es para el game over, muestra los puntos que obtuvo el jugador.
//se podria hacer una distinta cuando el jugador gane el juego?
using namespace sf;

class EscenaGameOver : public Escena {
public:
	EscenaGameOver(Juego &j, int puntos);
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void ProcesarEvento(Event &e) override;
private:
	Font m_font;
	Text m_text;
	Clock m_clock; //para cuando titila el texto xd
};

#endif
