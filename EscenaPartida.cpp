#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <SFML/Graphics/Rect.hpp>
#include "EscenaPartida.h"
#include "Juego.h"
#include "EscenaResultados.h"
#include "EscenaMenu.h"
#include "ItemPuntos.h"
#include "Zombie.h"
using namespace std;
using namespace sf;

EscenaPartida::EscenaPartida(Juego &j) : Escena(j){
	m_enemigo_textura.loadFromFile("assets/enemy/zombiebasic.png");
	m_bala_textura.loadFromFile("assets/player/bullet.png");
	m_font.loadFromFile("assets/fonts/asap.ttf");
	m_item_textura.loadFromFile("assets/item/Items.png");
	m_items.push_back(make_unique<ItemPuntos>(m_item_textura, Vector2f(300,200)));
	
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

bool fuera_de_la_pantalla(unique_ptr<Disparo> &d) {
	Vector2f p = d->verPosicion();
	if (p.x<0 or p.x>640) return true;
	if (p.y<0 or p.y>480) return true;
	return false;
}
// ->

bool colisiona(FloatRect h1, FloatRect h2){
	return (h1.intersects(h2));
}

// FIN FUNCIONES AUXILIARES ->
	
void EscenaPartida::Actualizar () {
	
	generarZombies();
	
	m_jugador.Actualizar();
	
	//para generar disparos
	if (m_jugador.debeDisparar()){
		m_disparos.push_back(m_jugador.generarDisparo(m_bala_textura));
		m_jugador.ReestablecerTemporizadorDisparo();
	}
	
	for(auto &d : m_disparos){
		if(d)
			d->Actualizar();
	}

	for(auto &i : m_items)
		i->Actualizar();
	
	for(auto &e : m_enemigos)
		e->Actualizar(m_jugador.verPosicion());
	
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
	
	
	for(auto &d : m_disparos)
		if(d)
			d->Dibujar(w);

	for(auto &i : m_items)
		i->Dibujar(w);
	
	for(auto &e : m_enemigos)
		e->Dibujar(w);
	
	
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
	for(auto &e : m_enemigos){
		if(e->lograAtacarJugador(m_jugador.verPosicion())){
			Perder();
		}
	}
}
	
void EscenaPartida::comprobarAtacarEnemigos() {
	// Iteramos DISPAROS desde el último al primero (evita problemas de índices al borrar)
	for(int d = m_disparos.size()-1; d >= 0; --d) {
		// Iteramos ZOMBIES desde el último al primero
		for(int e = m_enemigos.size()-1; e >= 0; --e) {
			
			if(m_disparos[d]->Colisiona(m_enemigos[e]->verPosicion())) {
				// ------ LÓGICA DE RECOMPENSAS ------
				m_jugador.sumarPuntos(m_enemigos[e]->verPuntos());
				m_items.emplace_back(m_enemigos[e]->GenerarItem(m_enemigo_textura));
				
				// ------ BORRADO SEGURO CON ÍNDICES ------
				// Borramos usando begin() + posición 
				m_disparos.erase(m_disparos.begin() + d);
				m_enemigos.erase(m_enemigos.begin() + e);
				break; // Rompemos el loop de zombies, el disparo ya fue borrado
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
		m_enemigos.emplace_back(make_unique<Zombie>(m_enemigo_textura, Vector2f(32,200)));
		m_zclock.restart(); // Reinicia el reloj
	}
}


void EscenaPartida::comprobarRecogerItem ( ) {
	for(size_t i = 0; i < m_items.size();++i) {
		auto it = m_items.begin() + i;
		if (colisiona(m_jugador.verHitbox(), m_items[i]->verHitbox())) {
			m_items[i]->EfectoAlRecoger(m_jugador);
			it = m_items.erase(it);
		}
	}
}

void EscenaPartida::Perder ( ) {
	//podria ser mejor
	m_jugador.restarVida();
	m_enemigos.clear();
	m_disparos.clear();
	m_items.clear();
}
