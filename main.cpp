#include "Juego.h"
#include "EscenaMenu.h"
#include "Escena.h"

int main(int argc, char *argv[]){
//	Juego j(new EscenaMenu);
//	j.Jugar();
	Juego j;
	Escena *e = new EscenaMenu(j);
	j.Jugar(e);
	return 0;
}

