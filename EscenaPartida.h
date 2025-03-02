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
#include "Map.h"

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
	Map maptest;
	
	// fuente y texto para ver score y vidas
	void actualizarTexto();
	Font m_font;
	Text m_text[2];
	
	//metodos y variables de enemigos
	//podria colocar esto en una funcion llamada gestorEnemigos
	void generarZombies(); //temporal
	void comprobarAtaqueEnemigo();
	void comprobarAtacarEnemigos();
	void eliminarEnemigosMuertos();
	Texture m_enemigo_textura;
	vector<unique_ptr<EnemigoBase>> m_enemigos;
	Clock m_zombie_spawn_clock;
	
	//metodos y variables de los power ups. podria poner esto en una clase tambien
	void generarItemRandom(Vector2f pos);
	void comprobarRecogerItem();
	Texture m_item_textura;
	vector<unique_ptr<ItemBase>> m_items;
	
	void Perder();
};

#endif

