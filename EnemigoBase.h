#ifndef ENEMIGOBASE_H
#define ENEMIGOBASE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class EnemigoBase {
public:
	EnemigoBase(sf::Texture &t, sf::Vector2f pos, float vel, int puntos);
	virtual void Actualizar(sf::Vector2f pos_jugador);
	void Dibujar(sf::RenderWindow &w);
	virtual void AtacarJugador(sf::Vector2f pos_jugador) = 0;
	sf::Vector2f verPosicion();
	int verPuntos();
	float verVelocidad();
	//faltaria algo para hacer que al morir genere un item pero eso no se si iria aqui o en otro lugar
	
protected:
	sf::Sprite m_sprite;
	float m_velocidad;
	int m_puntos;
};

#endif

