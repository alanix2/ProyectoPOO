#ifndef ESCENAPARTIDA_H
#define ESCENAPARTIDA_H
#include "Disparo.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include <SFML/Window/Event.hpp>
#include "Juego.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Zombie.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include "Jugador.h"
#include "ItemPuntos.h"

using namespace sf;
using namespace std;

class EscenaPartida : public Escena {
public:
	EscenaPartida(Juego &j);
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void ProcesarEvento (Event &e) override;
private:
	Jugador m_jugador;
	
	//textura de los items
	Texture m_item_textura;
	vector <ItemPuntos> test;
	
	//textura de zombies, vector con zombies, y el reloj para generarlos
	Texture m_zombie_textura;
	vector<Zombie> m_zombies;
	Clock m_zclock;
	
	//Vector de disparos y su textura
	vector<Disparo> m_disparos;
	Texture m_bala_textura;
	
	// fuente y texto para ver score y vidas
	Font m_font;
	Text m_text[2];
	
	void comprobarAtaqueEnemigo();
	void comprobarAtacarEnemigos();
	void comprobarRecogerItem();
	void actualizarTexto();
	void generarZombies();
	void Perder();
};

#endif

