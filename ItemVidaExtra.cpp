#include "ItemVidaExtra.h"

ItemVidaExtra::ItemVidaExtra (Texture & t, Vector2f pos) : ItemBase(t, IntRect({64,0},{16,16}), pos) {
	
}

void ItemVidaExtra::EfectoAlRecoger (Jugador & j) {
	j.sumarVida();
}

void ItemVidaExtra::Actualizar ( ) {
	
}


