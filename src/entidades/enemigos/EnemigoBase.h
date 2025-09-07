#ifndef ENEMIGOBASE_H
#define ENEMIGOBASE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../core/EntidadDibujable.h"
#include "../../items/ItemBase.h"

using namespace sf;
using namespace std;

//la base para cualquier enemigo o jefe. hasta ahora solo hay uno (zombie).

class EnemigoBase : public EntidadDibujable {
public:
	EnemigoBase(Texture &t, Vector2f pos, float vel, int puntos, int vida);
	virtual void Actualizar(Vector2f pos) = 0;
	virtual void Actualizar();
	//al morir genera un item pero eso no se si iria aqui o en otro lugar
	virtual unique_ptr<ItemBase> GenerarItem(Texture &t) = 0;
	void Morir(); 
	bool verEstado();
	void recibirDanio(int danio); //cuando el jugador le dispara con el arma.
	int verVida();
	int verPuntos();
	float verVelocidad();
	virtual ~EnemigoBase(){}
	
protected:
	virtual void AtacarJugador(Vector2f pos_jugador) = 0;
	bool m_muerto = false; 
	float m_velocidad;
	int m_puntos; //cuantos puntos da al morir
	int m_vida;
};

#endif
