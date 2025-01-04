#ifndef ESCENARESULTADOS_H
#define ESCENARESULTADOS_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Escena.h"
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
using namespace sf;

class EscenaResultados : public Escena {
public:
	EscenaResultados(Juego &j, int puntos);
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void ProcesarEvento(Event &e) override;
private:
	Font m_font;
	Text m_text;
	Clock m_clock;
};

#endif

