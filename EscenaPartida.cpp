#include "EscenaPartida.h"
#include <cmath>
#include <iostream>
#include "Juego.h"
#include "EscenaResultados.h"
#include "EscenaMenu.h"
#include <sstream>
#include <iomanip>
using namespace std;

EscenaPartida::EscenaPartida(Juego &j) : Escena(j) {
	m_zombie_textura.loadFromFile("assets/player/Jugador1.png");
	m_zombies.push_back(Zombie(m_zombie_textura, Vector2f(100, 100)));
	m_zombies.push_back(Zombie(m_zombie_textura, Vector2f(200, 500)));
	m_zombies.push_back(Zombie(m_zombie_textura, Vector2f(600, 400)));
	m_bala_textura.loadFromFile("assets/player/bullet.png");
	m_font.loadFromFile("assets/fonts/asap.ttf");
	m_text.setFont(m_font);
	m_text.setFillColor({255,255,255});
	m_text.setOutlineColor({0,0,0});
	m_text.setOutlineThickness(2);
	m_text.setCharacterSize(20);
	m_text.setPosition(10,5);
	m_text.setString("SCORE: 00000000");
}
//<- FUNCIONES AUXILIARES

bool fuera_de_la_pantalla(Disparo &d) {
	Vector2f p = d.verPosicion();
	if (p.x<0 or p.x>640) return true;
	if (p.y<0 or p.y>480) return true;
	return false;
}

//void atacarJugador(vector<Zombie> &vz, Jugador &j){
//	for(Zombie &z : m_zombies){
//		if(z.Colisiona(m_Jugador.verPosicion())){
//		//que pase algo como pausarse unos segundos, perder una vida, o morir
//		}
//	}
//}

void atacarEnemigos(vector<Disparo> &vd, vector<Zombie> &vz, Jugador &j){
	//si un disparo colisiona con un enemigo, los dos se eliminan
	for(size_t d = 0; d < vd.size();++d) {
		auto it = vd.begin() + d;
		for(size_t z = 0; z < vz.size();++z) {
			auto zit = vz.begin() + z;
			if (vd[d].Colisiona(vz[z].verPosicion())) {
				j.sumarPuntos(vz[z].verPuntos());
				vd.erase(it);
				vz.erase(zit);
			}
		}
		
	}
}	
	
void actualizarTexto(Jugador &j, Text &t){
	//aqui luego se tendria que poner para actualizar las vidas
	stringstream pts;
	pts << "SCORE: " << setw(8) << setfill('0') << j.verPuntos();
	t.setString(pts.str());
}

// FIN FUNCIONES AUXILIARES ->
	
void EscenaPartida::Actualizar () {
	
	m_Jugador.Actualizar();
	if (m_Jugador.debeDisparar())
		m_disparos.push_back(m_Jugador.generarDisparo(m_bala_textura));
	
	for(Disparo &d : m_disparos)
		d.Actualizar();
	
	for(Zombie &z : m_zombies)
		z.Actualizar(m_Jugador.verPosicion());
	
	atacarEnemigos(m_disparos, m_zombies, m_Jugador);
	
	// Para remover disparos fuera de la pantalla
	auto it = remove_if(m_disparos.begin(),m_disparos.end(),fuera_de_la_pantalla);
	m_disparos.erase(it,m_disparos.end());
	
	
	//auxiliar, ya que aun no se han implementado niveles.
	if(m_Jugador.verPuntos() >= 999999){
		m_juego.ActualizarScore(m_Jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaResultados(m_juego, m_Jugador.verPuntos()));
	}
	
	actualizarTexto(m_Jugador, m_text);
	//actualizar puntos
	
}

void EscenaPartida::Dibujar (RenderWindow & w) {
	w.clear(Color(220,220,180,255));
	m_Jugador.Dibujar(w);
	
	for(Disparo &d : m_disparos)
		d.Dibujar(w);

	for(Zombie &z : m_zombies)
		z.Dibujar(w);
	
	w.draw(m_text);
	
}

void EscenaPartida::ProcesarEvento (Event &e) {
	if (e.type==Event::KeyPressed and e.key.code==Keyboard::Escape){
		m_juego.ActualizarScore(m_Jugador.verPuntos());
		m_juego.cambiarEscena(new EscenaMenu(m_juego));
	}
}

