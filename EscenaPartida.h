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
	EnemigoBase m_enemigo;
	vector<Disparo> m_disparos;
	Texture m_bala_textura;
	int m_puntos = 0;
	Font m_font;
	Text m_text;
};

#endif

