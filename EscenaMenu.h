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
	Font m_font; //la fuente con la cual se muestran los textos, hasta ahora hay solo una, podriamos poner mas.
	Clock m_clock; //el reloj para el texto que titila.
	Text m_texts[4]; //vector con los textos
};

#endif

