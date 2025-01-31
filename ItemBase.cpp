#include "ItemBase.h"

ItemBase::ItemBase (Texture &t, IntRect rect, Vector2f pos) : EntidadDibujable(t, rect) {
	m_sprite.setPosition(pos);
}
