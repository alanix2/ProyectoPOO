#ifndef DISPAROTRIPLE_H
#define DISPAROTRIPLE_H
#include "Disparo.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

/*
no es tan distinto al disparo normal, nomas tiene mas velocidad
y usa otra porcion de la textura de balas, asi que no se si es 
tan necesario.
*/

class DisparoTriple : public Disparo {
public:
	DisparoTriple(Texture &t, Vector2f pos, Vector2f dir);
	void Actualizar () override;
private:
};

#endif

