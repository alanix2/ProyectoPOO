#ifndef ESCENAPARTIDA_H
#define ESCENAPARTIDA_H
#include "Jugador.h"
#include "Disparo.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include <SFML/Window/Event.hpp>
#include "Juego.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "EnemigoBase.h"
#include <SFML/Graphics/Texture.hpp>
#include "ItemBase.h"
using namespace sf;
using namespace std;

class EscenaPartida : public Escena {
public:
	EscenaPartida(Juego &j);
	void Actualizar() override;
	void Dibujar(RenderWindow &w) override;
	void ProcesarEvento (Event &e) override;
private:
	Jugador m_Jugador_p1;
	ItemBase PowerUpTest;
	//la idea es que tambien haya un vector de enemigos
	//o que haya alguna manera de hacer que aparezcan muchos
	EnemigoBase m_enemigo;
	//Vector de disparos y su textura
	vector<Disparo> m_disparos;
	Texture m_bala_textura;
	
	Font m_font;
	Text m_text;
};

#endif

