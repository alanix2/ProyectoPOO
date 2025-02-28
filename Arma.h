#ifndef ARMA_H
#define ARMA_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Disparo.h"
using namespace sf;
using namespace std;

class Arma {
public:
	Arma(int danio, float delayDisparos);
	virtual void Actualizar() = 0;
	virtual void Dibujar(RenderWindow &w) = 0;
	//funciona pero, como se haria para, por ejemplo, un arma con misiles perseguidores?
	virtual void Disparar(Vector2f pos, float rotation) = 0;
	//el arma realiza la verificacion de colision ya que esta es la que contiene los proyectiles
	virtual bool VerificarColision(FloatRect &hb) = 0;
	int verDanio();
	
protected:
	virtual void destruirFueraDePantalla() = 0;
	virtual void destruirInactivos() = 0;
	bool debeDisparar();
	static bool fuera_de_la_pantalla(Disparo &d);
	static bool esta_destruido(Disparo &d);
	float m_delayDisparos;
	int m_danio;
	Texture m_bala_textura;
	Clock m_temporizadorDisparo;
	Time m_intervaloDisparo = milliseconds(m_delayDisparos);
private: 
	
};

#endif

