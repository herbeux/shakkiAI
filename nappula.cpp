#include <list>
#include <string>
#include "asema.h"
#include "nappula.h"
using namespace std;


Nappula::Nappula(wstring unicode, int vari, int koodi)
{
	_unicode = unicode;
	_vari = vari;
	_koodi = koodi;
}


// virtual jotta myöhäinen sidonta käytössä
virtual void annaSiirrot(
list<Siirto>& lista,
Ruutu* ruutu,
Asema* asema,
int vari
) = 0;

