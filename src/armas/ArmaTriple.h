#ifndef ARMATRIPLE_H
#define ARMATRIPLE_H
#include "Arma.h"
#include "../proyectiles/DisparoTriple.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
using namespace std;

//un arma que dispara tres projectiles a la vez. tiene 3 vectores de balas para disparo triple.

class ArmaTriple : public Arma {
public:
	ArmaTriple();
	void Actualizar();
	void Dibujar(RenderWindow & w);
	void Disparar(Vector2f pos, float rotation);
	bool VerificarColision(FloatRect &hb) override;
protected:
	void destruirFueraDePantalla() override;
	void destruirInactivos() override;
private:
	vector<DisparoTriple> m_balas1; // balas en el medio
	vector<DisparoTriple> m_balas2; // balas a la izquierda
	vector<DisparoTriple> m_balas3; // balas a la derecha
};

#endif

