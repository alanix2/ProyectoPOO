#ifndef DISPARONORMAL_H
#define DISPARONORMAL_H
#include "Disparo.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

class DisparoNormal : public Disparo {
public:
	DisparoNormal(Texture &t, Vector2f pos, Vector2f dir, float vel = 3.f);
	void Actualizar () override;
	bool Colisiona (Vector2f pos) override;
private:
};

#endif

