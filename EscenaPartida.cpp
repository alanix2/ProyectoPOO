#include "EscenaPartida.h"
#include <cmath>
#include <iostream>
#include "Juego.h"
#include "EscenaResultados.h"
#include "EscenaMenu.h"
#include <sstream>
#include <iomanip>
#include <SFML/Graphics/Rect.hpp>
using namespace std;
using namespace sf;

EscenaPartida::EscenaPartida(Juego &j) : Escena(j){
	m_zombie_textura.loadFromFile("assets/enemy/zombiebasic.png");
	m_bala_textura.loadFromFile("assets/player/bullet.png");
	m_font.loadFromFile("assets/fonts/asap.ttf");
	m_item_textura.loadFromFile("assets/item/Items.png");
	test.push_back(ItemPuntos(m_item_textura, Vector2f(300,200)));
	
	for(Text &t : m_text){
		t.setFont(m_font);
		t.setFillColor({255,255,255});
		t.setOutlineColor({0,0,0});
		t.setOutlineThickness(2);
		t.setCharacterSize(20);
	}

	m_text[0].setPosition(10,5);
	m_text[0].setString("SCORE: 00000000");
	m_text[1].setPosition(450,5);
	m_text[1].setString("VIDAS: " + to_string(m_jugador.verVidas()));
	
}
//<- FUNCIONES AUXILIARES

bool fuera_de_la_pantalla(Disparo &d) {
	Vector2f p = d.verPosicion();
	if (p.x<0 or p.x>640) return true;
	if (p.y<0 or p.y>480) return true;
	return false;
}

bool colisiona(FloatRect h1, FloatRect h2){
	return (h1.intersects(h2));
}

// FIN FUNCIONES AUXILIARES ->
	
void EscenaPartida::Actualizar () {
	generarZombies();
	
	m_jugador.Actualizar();
	
	//para generar disparos
	if (m_jugador.debeDisparar())
		m_disparos.push_back(m_jugador.generarDisparo(m_bala_textura));
	
	for(ItemPuntos &i : test)
		i.Actualizar();
	
	for(Disparo &d : m_disparos)
		d.Actualizar();
	
	for(Zombie &z : m_zombies)
		z.Actualizar(m_jugador.verPosicion());
	
	comprobarAtacarEnemigos();
	comprobarAtaqueEnemigo();
	comprobarRecogerItem();
	
	// Para remover disparos fuera de la pantalla
	auto it = remove_if(m_disparos.begin(),m_disparos.end(),fuera_de_la_pantalla);
	m_disparos.erase(it,m_disparos.end());
	
	//si pierde todas las vidas, se termina el juego
	if(m_jugador.verVidas() == 0){
		m_juego.ActualizarScore(m_jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaResultados(m_juego, m_jugador.verPuntos()));
	}
	
	
	//para actualizar el texto con los puntos y vidas
	actualizarTexto();
}

void EscenaPartida::Dibujar (RenderWindow & w) {
	w.clear(Color(0,0,0,255));
	
	for(Disparo &d : m_disparos)
		d.Dibujar(w);

	for(ItemPuntos &i : test)
		i.Dibujar(w);
	
	for(Zombie &z : m_zombies)
		z.Dibujar(w);
	
	
	for(Text &t : m_text)
		w.draw(t);
	
	m_jugador.Dibujar(w);
}

void EscenaPartida::ProcesarEvento (Event &e) {
	if (e.type==Event::KeyPressed and e.key.code==Keyboard::Escape){
		m_juego.ActualizarScore(m_jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaMenu(m_juego));
	}
}


void EscenaPartida::comprobarAtaqueEnemigo(){
	for(Zombie &z : m_zombies){
		if(colisiona(z.verHitbox(), m_jugador.verHitbox())){
			Perder();
		}
	}
}
	
void EscenaPartida::comprobarAtacarEnemigos(){
		//si un disparo colisiona con un enemigo, los dos se eliminan
		for(size_t d = 0; d < m_disparos.size();++d) {
			auto disparo_actual = m_disparos.begin() + d;
			for(size_t z = 0; z < m_zombies.size();++z) {
				auto zombie_actual = m_zombies.begin() + z;
				if (m_disparos[d].Colisiona(m_zombies[z].verPosicion())) {
					m_jugador.sumarPuntos(m_zombies[z].verPuntos());
					
					test.push_back(ItemPuntos(m_item_textura,m_zombies[z].verPosicion()));
					
					m_disparos.erase(disparo_actual);
					m_zombies.erase(zombie_actual);
				}
			}
		}
	}

void EscenaPartida::actualizarTexto(){
			//aqui luego se tendria que poner para actualizar las vidas
			stringstream pts;
			pts << "SCORE: " << setw(8) << setfill('0') << m_jugador.verPuntos();
			m_text[0].setString(pts.str());
			m_text[1].setString("VIDAS :" + to_string(m_jugador.verVidas()));
}

void EscenaPartida::generarZombies ( ) {
	if (m_zclock.getElapsedTime().asSeconds() >=1.2f) {
		// Genera un zombie desde la posición de la puerta
		m_zombies.emplace_back(m_zombie_textura, Vector2f(32,240));
		m_zombies.emplace_back(m_zombie_textura, Vector2f(608,240));
		m_zombies.emplace_back(m_zombie_textura, Vector2f(320,32));
		m_zclock.restart(); // Reinicia el reloj
	}
}


void EscenaPartida::comprobarRecogerItem ( ) {
	for(size_t i = 0; i < test.size();++i) {
		auto it = test.begin() + i;
		if (colisiona(m_jugador.verHitbox(), test[i].verHitbox())) {
			test[i].EfectoAlRecoger(m_jugador);
			it = test.erase(it);
		}
	}
}

void EscenaPartida::Perder ( ) {
	//podria ser mejor
	m_jugador.restarVida();
	m_zombies.clear();
	m_disparos.clear();
	test.clear();
}

