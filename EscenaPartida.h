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
#include "FondoHabitacion.h"

/*
ALGO QUE CAPAZ ME OLVIDE DE EXPLICAR
si notan en vez de punteros comunes (con el *)
puse un tipo de puntero llamado unique_ptr<>.
esto lo puse porque lei que es mejor que un puntero común (ya que te gestiona automaticamente cosas como el delete).
podría cambiarlo a un puntero comun (porque no tengo ni idea si nos piden eso si o si), 
pero me llevaria tiempo reescribir algunas partes y que queden funcionando.
*/

using namespace sf;
using namespace std;

class EscenaPartida : public Escena {
public:
	EscenaPartida(Juego &j);
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void ProcesarEvento (Event &e) override;
private:
	Jugador m_jugador; //bastante obvio
	/*
	Esto es para probar el fondo de la habitación
	Faltaria hacer un nivel completo con puertas y varias habitaciones.
	*/
	FondoHabitacion maptest;
	
	// fuente y texto para ver score y vidas
	void actualizarTexto();
	Font m_font;
	Text m_text[2];
	
	//metodos y variables de enemigos
	//podria colocar esto en una funcion llamada gestorEnemigos
	void generarZombies(); //temporal
	void comprobarAtaqueEnemigo(); //para chequear si el enemigo atacó al jugador. podria ser mejor.
	void comprobarAtacarEnemigos();//para chequear si el jugador atacó al enemigo. igualmente podria ser mejor.
	void eliminarEnemigosMuertos();
	Texture m_enemigo_textura; //la textura de los enemigos. hasta ahora solo hay uno.
	vector<unique_ptr<EnemigoBase>> m_enemigos; //vector con los enemigos.
	Clock m_zombie_spawn_clock; //temporal para hacer aparecer enemigos.
	
	//metodos y variables de los power ups. podria poner esto en una clase aparte tambien
	void comprobarRecogerItem(); //para chequear si el jugador agarro algun power up u objeto.
	Texture m_item_textura; //la textura con los power ups
	vector<unique_ptr<ItemBase>> m_items; 
	
	void Perder(); //este tambien lo puse de forma temporal y es malísimo, pero es mas o menos para simular como sería perder
};

#endif

