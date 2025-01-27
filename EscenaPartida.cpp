#include "EscenaPartida.h"
#include <cmath>
#include <iostream>
#include "Juego.h"
#include "EscenaResultados.h"
#include "EscenaMenu.h"
#include <sstream>
#include <iomanip>
using namespace std;
using namespace sf;

EscenaPartida::EscenaPartida(Juego &j) : Escena(j) {
	m_zombie_textura.loadFromFile("assets/enemy/zombiebasic.png");
	m_bala_textura.loadFromFile("assets/player/bullet.png");
	m_font.loadFromFile("assets/fonts/asap.ttf");
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
	m_text[1].setString("VIDAS: " + to_string(m_Jugador.verVidas()));
}
//<- FUNCIONES AUXILIARES

bool fuera_de_la_pantalla(Disparo &d) {
	Vector2f p = d.verPosicion();
	if (p.x<0 or p.x>640) return true;
	if (p.y<0 or p.y>480) return true;
	return false;
}

// FIN FUNCIONES AUXILIARES ->
	
void EscenaPartida::Actualizar () {
	generarZombies();
	
	m_Jugador.Actualizar();
	
	//para generar disparos
	if (m_Jugador.debeDisparar())
		m_disparos.push_back(m_Jugador.generarDisparo(m_bala_textura));
	
	for(Disparo &d : m_disparos)
		d.Actualizar();
	
	for(Zombie &z : m_zombies)
		z.Actualizar(m_Jugador.verPosicion());
	
	atacarEnemigos();
	atacarJugador();
	
	// Para remover disparos fuera de la pantalla
	auto it = remove_if(m_disparos.begin(),m_disparos.end(),fuera_de_la_pantalla);
	m_disparos.erase(it,m_disparos.end());
	
	//si pierde todas las vidas, se termina el juego
	if(m_Jugador.verVidas() == 0){
		m_juego.ActualizarScore(m_Jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaResultados(m_juego, m_Jugador.verPuntos()));
	}
	
	//para actualizar el texto con los puntos y vidas
	actualizarTexto();
}

void EscenaPartida::Dibujar (RenderWindow & w) {
	w.clear(Color(0,0,0,255));
	m_Jugador.Dibujar(w);
	
	for(Disparo &d : m_disparos)
		d.Dibujar(w);

	for(Zombie &z : m_zombies)
		z.Dibujar(w);
	
	
	for(Text &t : m_text)
		w.draw(t);
	
}

void EscenaPartida::ProcesarEvento (Event &e) {
	if (e.type==Event::KeyPressed and e.key.code==Keyboard::Escape){
		m_juego.ActualizarScore(m_Jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaMenu(m_juego));
	}
}


void EscenaPartida::atacarJugador(){
	for(Zombie &z : m_zombies){
		if(z.Colisiona(m_Jugador.verPosicion())){
			m_Jugador.restarVida();
			m_zombies.clear();
		}
	}
}
	
void EscenaPartida::atacarEnemigos(){
		//si un disparo colisiona con un enemigo, los dos se eliminan
		for(size_t d = 0; d < m_disparos.size();++d) {
			auto disparo_actual = m_disparos.begin() + d;
			
			for(size_t z = 0; z < m_zombies.size();++z) {
				auto zombie_actual = m_zombies.begin() + z;
				
				if (m_disparos[d].Colisiona(m_zombies[z].verPosicion())) {
					m_Jugador.sumarPuntos(m_zombies[z].verPuntos());
					m_disparos.erase(disparo_actual);
					m_zombies.erase(zombie_actual);
				}
			}
		}
	}	
		
void EscenaPartida::actualizarTexto(){
			//aqui luego se tendria que poner para actualizar las vidas
			stringstream pts;
			pts << "SCORE: " << setw(8) << setfill('0') << m_Jugador.verPuntos();
			m_text[0].setString(pts.str());
			m_text[1].setString("VIDAS :" + to_string(m_Jugador.verVidas()));
}

void EscenaPartida::generarZombies ( ) {
	if (m_zclock.getElapsedTime().asSeconds() >= 1.0f) {
		// Genera un zombie desde la posici�n de la puerta
		m_zombies.emplace_back(m_zombie_textura, Vector2f(32,240));
		m_zombies.emplace_back(m_zombie_textura, Vector2f(608,240));
		m_zombies.emplace_back(m_zombie_textura, Vector2f(320,32));
		m_zclock.restart(); // Reinicia el reloj
	}
}

