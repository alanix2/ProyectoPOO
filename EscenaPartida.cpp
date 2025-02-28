#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include "EscenaPartida.h"
#include "Juego.h"
#include "EscenaResultados.h"
#include "EscenaMenu.h"
#include "ItemPuntos.h"
#include "Zombie.h"
#include "ArmaBase.h"
#include "ItemArmaTriple.h"
#include "EnemigoBase.h"
using namespace std;
using namespace sf;

EscenaPartida::EscenaPartida(Juego &j) : Escena(j){
	m_enemigo_textura.loadFromFile("assets/enemy/zombiebasic.png");
	m_font.loadFromFile("assets/fonts/asap.ttf");
	m_item_textura.loadFromFile("assets/item/Items.png");
	m_items.push_back(make_unique<ItemArmaTriple>(m_item_textura, Vector2f(300,200))); //test
	
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

//<-funciones auxiliares de colisión

//colision entre dos hitboxes
bool colisiona(FloatRect h1, FloatRect h2){
	return (h1.intersects(h2));
}

//colision verificando si un punto esta en el area de la hitbox
bool colisiona(FloatRect hb, Vector2f pos){
	return (hb.contains(pos));
}

//colision mediante la formula de distancia entre dos puntos
bool colisiona(Vector2f pos1, Vector2f pos2, float distancia){
	Vector2f v = pos1-pos2;
	return sqrt((v.x*v.x)+(v.y*v.y))<distancia;
}	
//->	
	
bool esta_muerto(const unique_ptr<EnemigoBase> &e){
	return e->verEstado();
}
	
void EscenaPartida::Actualizar () {
	actualizarTexto();
	m_jugador.Actualizar();
	
	generarZombies();
	for(auto &e : m_enemigos)
		e->Actualizar(m_jugador.verPosicion());
	comprobarAtacarEnemigos();
	comprobarAtaqueEnemigo();
	eliminarEnemigosMuertos();

	for(auto &i : m_items)
		i->Actualizar();
	comprobarRecogerItem();
	
	//si pierde todas las vidas, se termina el juego (se podria extraer a una funcion privada)
	if(m_jugador.verVidas() <= 0){
		m_juego.ActualizarScore(m_jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaResultados(m_juego, m_jugador.verPuntos()));
	}
}

void EscenaPartida::Dibujar (RenderWindow & w) {
	w.clear(Color(0,0,0,255));
	for(Text &t : m_text)
		w.draw(t);
	
	for(auto &i : m_items)
		i->Dibujar(w);
	
	for(auto &e : m_enemigos)
		e->Dibujar(w);
	
	
	
	m_jugador.Dibujar(w);
}

void EscenaPartida::ProcesarEvento (Event &e) {
	if (e.type==Event::KeyPressed and e.key.code==Keyboard::Escape){
		m_juego.ActualizarScore(m_jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaMenu(m_juego));
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
	if (m_zombie_spawn_clock.getElapsedTime().asSeconds() >=0.5f) {
		// Genera un zombie desde la posición de la puerta
		m_enemigos.emplace_back(make_unique<Zombie>(m_enemigo_textura, Vector2f(50,300)));
		m_enemigos.emplace_back(make_unique<Zombie>(m_enemigo_textura, Vector2f(32,200)));
		m_enemigos.emplace_back(make_unique<Zombie>(m_enemigo_textura, Vector2f(15,100)));
		
		m_zombie_spawn_clock.restart(); // Reinicia el reloj
	}
}

void EscenaPartida::comprobarAtacarEnemigos ( ) {
	for (auto &e : m_enemigos){
		if(m_jugador.lograAtacar(e->verHitbox())){
			e->recibirDanio(m_jugador.verDanioArma());
		}
	}
}

void EscenaPartida::comprobarAtaqueEnemigo(){
	for(auto &e : m_enemigos){
		if(colisiona(e->verHitbox(), m_jugador.verHitbox())){
			Perder();
		}
	}
}

void EscenaPartida::eliminarEnemigosMuertos ( ) {
	for(auto &e : m_enemigos){
		if(esta_muerto(e)){
			m_jugador.sumarPuntos(e->verPuntos());
			m_items.push_back(e->GenerarItem(m_item_textura));
		}
	}
	auto it = remove_if(m_enemigos.begin(), m_enemigos.end(), esta_muerto);
	m_enemigos.erase(it, m_enemigos.end());
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
	//temporal, deberia de haber alguna manera de que se reinicie el nivel restandole una vida y un par de puntos al jugador.
	m_enemigos.clear();
	m_items.clear();
	m_jugador.moverPosicion(Vector2f(320,240));
	m_jugador.restarVida();
	m_jugador.CambiarArma(make_unique<ArmaBase>());
}
