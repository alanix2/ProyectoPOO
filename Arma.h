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
	Arma(float delayDisparos);
	virtual void Actualizar() = 0;
	virtual void Dibujar(RenderWindow &w) = 0;
	virtual void Disparar(Vector2f pos, float rotation) = 0;
	bool debeDisparar();
	
protected:
	static bool fuera_de_la_pantalla(Disparo &d);
	float m_delayDisparos;
	Texture m_bala_textura;
	Clock m_temporizadorDisparo;
	Time m_intervaloDisparo = milliseconds(m_delayDisparos);
private: 
	
};

#endif

