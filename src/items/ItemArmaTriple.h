#ifndef ITEMARMATRIPLE_H
#define ITEMARMATRIPLE_H
#include "ItemBase.h"
#include "../entidades/jugador/Jugador.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class ItemArmaTriple : public ItemBase {
public:
	ItemArmaTriple(Texture & t, Vector2f pos);
	void EfectoAlRecoger (Jugador & j);
	void Actualizar() override;
private:
};

#endif

