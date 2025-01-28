#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "EnemigoBase.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;
using namespace std;

class Zombie : public EnemigoBase {
public:
	Zombie(Texture &t, Vector2f pos);
	void Actualizar() override;
	void Actualizar (Vector2f pos_jugador);
	void AtacarJugador (Vector2f pos_jugador) override;
	FloatRect verHitbox() override;
private:
};

#endif

