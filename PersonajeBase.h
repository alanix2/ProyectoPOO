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
	bool Colisiona(Vector2f pos);
private:
	float m_vel;
protected:
	Texture m_texture;
	Sprite m_sprite;
};

//estaba pensando en hacer que PersonajeBase, EnemigoBase, Disparo y cualquier otra clase sobre algo en el juego,
//sean todos una subclase de una clase llamada Entidad. ya que todas comparten
// dibujar, verPosicion, Colisiono, etcetera.

#endif

