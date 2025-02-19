#ifndef ARMATRIPLE_H
#define ARMATRIPLE_H
#include "Arma.h"
#include "DisparoNormal.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
using namespace std;

class ArmaTriple : public Arma {
public:
	ArmaTriple();
	void Actualizar ( );
	void Dibujar (RenderWindow & w);
	void Disparar (Vector2f pos, float rotation);
private:
	vector<DisparoNormal> m_balas1; // disparo en el medio
	vector<DisparoNormal> m_balas2; // disparo a la izquierda
	vector<DisparoNormal> m_balas3; // disparo a la derecha
};

#endif

