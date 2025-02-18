#ifndef ITEMARMA_H
#define ITEMARMA_H
#include "ItemBase.h"
#include "Jugador.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

using namespace std;
using namespace sf;

class ItemArma : public ItemBase {
public:
	ItemArma(Texture &t, Vector2f pos);
	void EfectoAlRecoger (Jugador & j);
	void Actualizar ( ) override ;
private:
	//int m_TipoArma;
};

#endif

