#ifndef JUGADOR_H
#define JUGADOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Disparo.h"
#include "PersonajeBase.h"
#include <string>
using namespace sf;
using namespace std;
class Jugador : public PersonajeBase {
	Clock m_clock;
	//opcional? luego podriamos poner controles con joystick
	Keyboard::Key m_arr,m_aba,m_izq,m_der; //controles de movimiento
	Keyboard::Key m_disp_arr, m_disp_aba, m_disp_izq, m_disp_der; //controles de disparo
	bool sePresionoDisparo();
	void mover();
	void rotarSprite();
	int PuntajeActual = 0;
public:
	Jugador();
	void Actualizar();
	bool debeDisparar();
 	Disparo generarDisparo(Texture &text);
	void ConfigurarControles();
	int verPuntos();
	void sumarPuntos(int n);
	
};

#endif

