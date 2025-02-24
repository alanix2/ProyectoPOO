#ifndef ENEMIGOBASE_H
#define ENEMIGOBASE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "EntidadDibujable.h"
#include "ItemBase.h"

using namespace sf;
using namespace std;

class EnemigoBase : public EntidadDibujable{
public:
	EnemigoBase(Texture &t, Vector2f pos, float vel, int puntos);
	virtual void Actualizar(Vector2f pos) = 0;
	virtual void AtacarJugador(Vector2f pos_jugador) = 0;
	//al morir genera un item pero eso no se si iria aqui o en otro lugar
	virtual unique_ptr<ItemBase> GenerarItem(Texture &t) = 0;
	int verPuntos();
	float verVelocidad();
	virtual ~EnemigoBase(){}
	
protected:
	float m_velocidad;
	int m_puntos;
};

#endif

