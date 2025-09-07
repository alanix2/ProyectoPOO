#ifndef ARMANORMAL_H
#define ARMANORMAL_H
#include "Arma.h"
#include "../proyectiles/DisparoNormal.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
using namespace std;
using namespace sf;
//el arma con la que empieza el jugador, y que se le asgina cada vez que pierde una vida.
class ArmaNormal : public Arma {
public:
	ArmaNormal();
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void Disparar(Vector2f pos, float rotation) override;
	bool VerificarColision(FloatRect &hb) override;
protected:
	void destruirFueraDePantalla() override;
	void destruirInactivos() override;
private:	
	vector<DisparoNormal> m_balas; //el vector con las balas
	
};

#endif

