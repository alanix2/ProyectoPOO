#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "EnemigoBase.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include "ItemBase.h"

using namespace sf;
using namespace std;

class Zombie : public EnemigoBase {
public:
	Zombie(Texture &t, Vector2f pos);
	void Actualizar (Vector2f pos_jugador) override;
	unique_ptr<ItemBase> GenerarItem(Texture &t) override;
protected:
	void AtacarJugador (Vector2f pos_jugador) override;
private:
};

#endif

