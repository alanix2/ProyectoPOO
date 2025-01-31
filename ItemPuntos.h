#ifndef ITEMPUNTOS_H
#define ITEMPUNTOS_H
#include "ItemBase.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include "Jugador.h"

using namespace sf;
using namespace std;

class ItemPuntos : public ItemBase {
public:
	ItemPuntos(Texture &t, Vector2f pos);
	void EfectoAlRecoger (Jugador &j) override;
	void Actualizar() override;
private:
	
};

#endif
