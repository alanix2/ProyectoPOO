#ifndef DISPARONORMAL_H
#define DISPARONORMAL_H
#include "Disparo.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

class DisparoNormal : public Disparo {
public:
	DisparoNormal(Texture &t, Vector2f pos, Vector2f dir);
	void Actualizar () override;
private:
};

#endif

