#ifndef ESCENAMENU_H
#define ESCENAMENU_H
#include "Escena.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include "Juego.h"
using namespace sf;

class EscenaMenu : public Escena {
public:
	EscenaMenu(Juego &j);
	virtual void Actualizar() override;
	virtual void Dibujar(RenderWindow &w) override;
	virtual void ProcesarEvento(Event &e) override;
private:
	Font m_font;
	Clock m_clock;
	Text m_texts[5];
};

#endif

