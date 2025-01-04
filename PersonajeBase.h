#ifndef PERSONAJEBASE_H
#define PERSONAJEBASE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;

class PersonajeBase {
public:
	PersonajeBase(std::string NombreTextura);
	virtual void Actualizar() = 0;
	void Dibujar(RenderWindow &w);
	Vector2f verPosicion();
private:
	
protected:
	Texture m_tex;
	Sprite m_spr;
};

#endif

