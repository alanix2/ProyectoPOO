#include "ItemArmaTriple.h"
#include "../armas/ArmaTriple.h"
#include <memory>
using namespace std;

ItemArmaTriple::ItemArmaTriple(Texture & t, Vector2f pos) : ItemBase(t, IntRect({0,0},{16,16}), pos) {
	
}

void ItemArmaTriple::EfectoAlRecoger (Jugador & j) {
	j.CambiarArma(make_unique<ArmaTriple>());
}

void ItemArmaTriple::Actualizar ( ) {
	
}

