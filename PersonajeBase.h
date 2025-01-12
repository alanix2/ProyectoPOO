#ifndef PERSONAJEBASE_H
#define PERSONAJEBASE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
using namespace std;
using namespace sf;

class PersonajeBase {
public:
	PersonajeBase(string t, float vel);
	void Dibujar(RenderWindow &w);
	Vector2f verPosicion();
	float verVel();
private:
	float m_vel;
protected:
	Texture m_texture;
	Sprite m_spr;
};

#endif

