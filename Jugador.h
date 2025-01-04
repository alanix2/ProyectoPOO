#ifndef JUGADOR_H
#define JUGADOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Disparo.h"
#include "PersonajeBase.h"
using namespace sf;

class Jugador : public PersonajeBase {
	Clock m_clock;
	Keyboard::Key m_arr,m_aba,m_izq,m_der,m_disp;
	Keyboard::Key m_disp_arr, m_disp_aba, m_disp_izq, m_disp_der;
public:
	Jugador();
	void Actualizar() override;
	bool debeDisparar();
 	Disparo generarDisparo(Texture &text);
	
};

#endif

