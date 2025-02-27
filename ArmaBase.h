#ifndef ARMABASE_H
#define ARMABASE_H
#include "Arma.h"
#include "DisparoNormal.h"
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;

class ArmaBase : public Arma {
public:
	ArmaBase();
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void Disparar(Vector2f pos, float rotation) override;
private:
	vector<DisparoNormal> m_balas;
	
};

#endif

