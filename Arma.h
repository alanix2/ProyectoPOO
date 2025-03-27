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

//la clase base para el arma. la idea es que haya varias armas de distinto tipo
//como balas, laser, lanzallamas, granadas, etc etc.

//al momento de escribir esto solo hay dos armas.

class Arma {
public:
	Arma(int danio, float delayDisparos); //cada arma necesita el daño que hace y cuanto tiempo hay entre un disparo y otro (no sabria como hacer para armas que no necesiten un delay de disparos).
	virtual void Actualizar() = 0;
	virtual void Dibujar(RenderWindow &w) = 0;
	//funciona pero, como se haria para, por ejemplo, un arma con misiles perseguidores?
	virtual void Disparar(Vector2f pos, float rotation) = 0;
	
	virtual bool VerificarColision(FloatRect &hb) = 0;
	int verDanio();
	
protected:	
	bool debeDisparar(); //para chequear si paso el tiempo suficiente para generar otro disparo
	//fuera de la pantalla y destruirInactivos son para armas que contengan misiles, balas o cualquier tipo de proyectil.
	virtual void destruirFueraDePantalla() = 0; 
	virtual void destruirInactivos() = 0;
	static bool fuera_de_la_pantalla(Disparo &d); //para chequear si un proyectil está fuera de la pantalla
	static bool esta_destruido(Disparo &d); //para chequear si un proyectil se destruyó (para armas cuyas balas se destruyan al colisionar).
	float m_delayDisparos; //cuanto tiempo hay entre un disparo y otro. no todas las armas necesitarian esto.
	Time m_intervaloDisparo = milliseconds(m_delayDisparos); //pasa el float del delay de disparos a milisegundos.
	Clock m_temporizadorDisparo; //para manejar el delay de disparos.
	
	int m_danio;
	Texture m_bala_textura; //la textura con todas las balas. cada arma utilizaría una porcion distinta de la textura.
private: 
	
};

#endif

