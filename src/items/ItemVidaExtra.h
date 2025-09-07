#ifndef ITEMVIDAEXTRA_H
#define ITEMVIDAEXTRA_H
#include "ItemBase.h"
#include "../entidades/jugador/Jugador.h"

class ItemVidaExtra : public ItemBase {
public:
	ItemVidaExtra(Texture &t, Vector2f pos);
	void EfectoAlRecoger (Jugador & j) override;
	void Actualizar ( ) override;
private:
};

#endif

