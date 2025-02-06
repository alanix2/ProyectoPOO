#ifndef ITEMBASE_H
#define ITEMBASE_H
#include "EntidadDibujable.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include "Jugador.h"

using namespace sf;
using namespace std;


class ItemBase : public EntidadDibujable {
public:
	ItemBase(Texture &t, IntRect rect, Vector2f pos);
	virtual void EfectoAlRecoger(Jugador &j) = 0;
	virtual ~ItemBase() {}
	
private:
	
};

#endif

