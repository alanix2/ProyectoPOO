#include "src/core/Juego.h"
#include "src/escenas/EscenaMenu.h"
#include "src/escenas/Escena.h"

int main(int argc, char *argv[]){
	//iniciamos el juego con la escena del menu principal
	Juego j;
	Escena *e = new EscenaMenu(j);
	j.Jugar(e);
	return 0;
}

