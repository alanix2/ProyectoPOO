#ifndef ESCENAPARTIDA_H
#define ESCENAPARTIDA_H
#include "Disparo.h"
#include "Escena.h"
#include "Juego.h"
#include "EnemigoBase.h"
#include "Jugador.h"
#include "ItemBase.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <memory>

using namespace sf;
using namespace std;

class EscenaPartida : public Escena {
public:
	EscenaPartida(Juego &j);
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void ProcesarEvento (Event &e) override;
private:
	void comprobarAtaqueEnemigo();
	void comprobarAtacarEnemigos();
	void comprobarRecogerItem();
	void actualizarTexto();
	
	//temporal
	void generarZombies();
	
	void Perder();
	
	Jugador m_jugador;
	
	//textura de los items
	Texture m_item_textura;
	vector<unique_ptr<ItemBase>> m_items;
	
	//textura de zombies, vector con zombies, y el reloj para generarlos
	Texture m_enemigo_textura;
	vector<unique_ptr<EnemigoBase>> m_enemigos;
	Clock m_zombie_spawn_clock;
		
	// fuente y texto para ver score y vidas
	Font m_font;
	Text m_text[2];
};

#endif

