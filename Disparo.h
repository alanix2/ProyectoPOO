#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;

/*En cuanto al disparo, este es el disparo basico, 
Despues se tendria que hacer una version polimorfica y hacer varios disparos
(como uno triple o de distinta forma)
*/
class Disparo {
public:
	Disparo(Texture &text, Vector2f pos, Vector2f dir);
	void Actualizar();
	void Dibujar(RenderWindow &w);
	bool Colisiona(Vector2f pos);
	Vector2f verPosicion();
private:
	Sprite m_sprite;
	Vector2f m_vel;
};

#endif

