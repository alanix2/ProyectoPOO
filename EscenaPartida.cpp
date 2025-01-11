#include "EscenaPartida.h"
#include <cmath>
#include <iostream>
#include "Juego.h"
#include "EscenaResultados.h"
#include "EscenaMenu.h"
using namespace std;

EscenaPartida::EscenaPartida(Juego &j) : Escena(j) {
	m_bala_textura.loadFromFile("assets/player/bullet.png");
	m_font.loadFromFile("assets/fonts/asap.ttf");
	m_text.setFont(m_font);
	m_text.setFillColor({255,255,255});
	m_text.setOutlineColor({0,0,0});
	m_text.setOutlineThickness(2);
	m_text.setCharacterSize(40);
	m_text.setPosition(10,0);
	m_text.setString("Score: " + std::to_string(m_puntos));
}

bool colisiona(Disparo &d, PersonajeBase &t) {
	Vector2f pd = d.verPosicion();
	Vector2f pt = t.verPosicion();
	Vector2f v = pd-pt;
	return sqrt(v.x*v.x+v.y*v.y)<25;
}

bool toca_item(ItemBase &d, Jugador &t) {
	Vector2f pd = d.verPosicion();
	Vector2f pt = t.verPosicion();
	Vector2f v = pd-pt;
	return sqrt(v.x*v.x+v.y*v.y)<10;
}

bool fuera_de_la_pantalla(Disparo &d) {
	Vector2f p = d.verPosicion();
	if (p.x<0 or p.x>800) return true;
	if (p.y<0 or p.y>600) return true;
	return false;
}

void EscenaPartida::Actualizar () {
	m_Jugador_p1.Actualizar();
	m_enemigo.Actualizar();
	
	if(toca_item(PowerUpTest, m_Jugador_p1))
		PowerUpTest.RecogerItem(m_Jugador_p1);
	
	if (m_Jugador_p1.debeDisparar())
		m_disparos.push_back(m_Jugador_p1.generarDisparo(m_bala_textura));
	for(Disparo &d : m_disparos)
		d.Actualizar();
	
	for(size_t d = 0; d < m_disparos.size();++d) {
		auto it = m_disparos.begin() + d;
		if (colisiona(m_disparos[d],m_enemigo)) {
			m_disparos.erase(it);
			m_Jugador_p1.sumarPuntos(1);
			m_text.setString("Score: " + std::to_string(m_Jugador_p1.verPuntos()));
		}
	}

	auto it = remove_if(m_disparos.begin(),m_disparos.end(),fuera_de_la_pantalla);
	m_disparos.erase(it,m_disparos.end());
	
	
	if(m_puntos == 10){
		m_juego.ActualizarScore(m_puntos);
		m_juego.cambiarEscena(new EscenaResultados(m_juego, m_puntos));
	}
}

void EscenaPartida::Dibujar (RenderWindow & w) {
	w.clear(Color(220,220,180,255));
	m_Jugador_p1.Dibujar(w);
	m_enemigo.Dibujar(w);
	PowerUpTest.Dibujar(w);
	for(Disparo &d : m_disparos)
		d.Dibujar(w);
	w.draw(m_text);
}

void EscenaPartida::ProcesarEvento (Event &e) {
	if (e.type==Event::KeyPressed and e.key.code==Keyboard::Escape){
		m_juego.ActualizarScore(m_puntos);
		m_juego.cambiarEscena(new EscenaMenu(m_juego));
	}
}

