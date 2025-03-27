#ifndef JUGADOR_H
#define JUGADOR_H
#include "EntidadDibujable.h"
#include "Disparo.h"
#include "ArmaNormal.h"
#include "ArmaTriple.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include <memory>

//la clase jugador, el juego está pensado para un solo jugador, pero luego podríamos modificar para que se pueda 
//jugar de a dos.

using namespace sf;
using namespace std;

class Jugador : public EntidadDibujable {
public:
	Jugador();
	void Actualizar() override;	
	void Dibujar(RenderWindow &w) override;
	void moverPosicion(Vector2f pos); //para mover/teletransportar al jugador a otra posición
	void CambiarArma(unique_ptr<Arma> nuevaArma); //para cambiar el arma (se podria modificar para usar punteros normales
	bool lograAtacar(FloatRect hb); //le pide al arma equipada si alguna de las balas colisiona con algo.
	int verDanioArma(); //para ver cuanto daño hace el arma equipada.
	void restarVida(); //para quitarle una vida al Jugador
	void sumarVida(); //para cuando el jugador obtiene una vida ItemVidaExtra
	int verVidas();
	
	void sumarPuntos(int n);
	int verPuntos();
private:
	Texture m_texture;
	void ConfigurarControles();
	void mover(); //mover al jugador
	void rotarSprite(); //rota el sprite dependiendo de que botón se presionó, se podria cambiar 
	bool sePresionoDisparo();
	unique_ptr<Arma>m_armaEquipada; //un puntero al arma equipada, se podria reemplazar por un puntero comun.
	
	//opcional? luego podriamos poner controles con joystick
	Keyboard::Key m_arr,m_aba,m_izq,m_der; //controles de movimiento
	Keyboard::Key m_disp_arr, m_disp_aba, m_disp_izq, m_disp_der; //controles de disparo
	
	//los puntos y las vidas se podrian mover a otra clase, para que se gestionen mejor.
	int m_puntajeActual = 0;
	int m_vidas = 3;
	
	float m_velocidad = 2.0f; //la velocidad a la que se mueve el personaje. 
};

#endif

