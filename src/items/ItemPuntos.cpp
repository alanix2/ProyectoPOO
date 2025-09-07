#include "ItemPuntos.h"
#include <SFML/Graphics/Rect.hpp>

ItemPuntos::ItemPuntos(Texture &t,  Vector2f pos) : ItemBase(t,IntRect({48,0},{16,16}),pos) {
	
}

void ItemPuntos::EfectoAlRecoger (Jugador & j) {
	j.sumarPuntos(500);
}


void ItemPuntos::Actualizar ( ) {
	//en actualizar se podria poner alguna animacion, como una moneda girando o brillando
}

