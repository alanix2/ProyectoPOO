#ifndef JUGADOR_H
#define JUGADOR_H
#include "EntidadDibujable.h"
#include "Disparo.h"
#include "Enums.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <string>
#include <memory>
#include "ArmaBase.h"

using namespace sf;
using namespace std;

class Jugador : public EntidadDibujable {
public:
	Jugador();
	void Actualizar() override;	
	void Dibujar(RenderWindow &w) override;
	void CambiarArma(int TipoArma);
	
	void restarVida();
	void sumarVida();
	int verVidas();
	
	void sumarPuntos(int n);
	int verPuntos();
private:
	Texture m_texture;
	void ConfigurarControles();
	void mover();
	void rotarSprite();
	bool sePresionoDisparo();
	unique_ptr<Arma>m_armaEquipada;
	//opcional? luego podriamos poner controles con joystick
	Keyboard::Key m_arr,m_aba,m_izq,m_der; //controles de movimiento
	Keyboard::Key m_disp_arr, m_disp_aba, m_disp_izq, m_disp_der; //controles de disparo
	
	int PuntajeActual = 0;
	int m_vidas = 3;
	float m_velocidad = 2.0f;
};

#endif

