#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "EnemigoBase.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Zombie : public EnemigoBase {
public:
	Zombie(sf::Texture &t, sf::Vector2f pos);
	void Actualizar (sf::Vector2f pos_jugador) override;
	void AtacarJugador (sf::Vector2f pos_jugador) override;
private:
};

#endif

