#ifndef ENTIDADDIBUJABLE_H
#define ENTIDADDIBUJABLE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
//esta es la clase base para cualquier elemento dibujable
//ya sea jugador, enemigos, power ups, o cualquier otra cosa.

using namespace sf;
using namespace std;

class EntidadDibujable {
public:
	EntidadDibujable(); //tiene varios constructores, dependiendo del caso se usa uno u otro.
	EntidadDibujable(Texture &t);
	EntidadDibujable(Texture &t, IntRect TexturePortion);
	virtual void Actualizar() = 0;
	virtual void Dibujar(RenderWindow &w);
	virtual FloatRect verHitbox(); //para ver el rectangulo que rodea el Sprite
	Vector2f verPosicion(); //para ver la posición donde está el Sprite
	virtual ~EntidadDibujable(){}
protected:
	Sprite m_sprite;
private: 
	
};

#endif

