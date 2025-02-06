#ifndef ENTIDADDIBUJABLE_H
#define ENTIDADDIBUJABLE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

using namespace sf;
using namespace std;

class EntidadDibujable {
public:
	EntidadDibujable();
	EntidadDibujable(Texture &t);
	EntidadDibujable(Texture &t, IntRect TexturePortion);
	virtual void Actualizar() = 0;
	void Dibujar(RenderWindow &w);
	virtual FloatRect verHitbox();
	Vector2f verPosicion();
	virtual ~EntidadDibujable(){}
protected:
	Sprite m_sprite;
private: 
	
};

#endif

