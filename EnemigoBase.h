#ifndef ENEMIGOBASE_H
#define ENEMIGOBASE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

class EnemigoBase {
public:
	EnemigoBase(Texture &t, Vector2f pos, float vel, int puntos);
	void Actualizar(Vector2f pos_jugador);
	virtual void AtacarJugador(Vector2f pos_jugador) = 0;
	
private:
	Sprite m_sprite;
	float m_velocidad;
	int m_puntos;
};

#endif

