#pragma once

#include <list>
#include <string>
#include "asema.h"


// Vakioarvot nappulatyypeille.
enum
{
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};


// Yliluokka shakkinappuloille.
class Nappula
{

private:
	std::wstring	_unicode;	// nappulaa vastaava unicode-merkki
	int				_vari;		// valkea = 0, musta = 1
	int				_koodi;		// VT, VR, MT tms.

public:
	Nappula(std::wstring, int, int);
	Nappula() {}

	// virtual jotta myöhäinen sidonta käytössä
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	) = 0;

	void setUnicode(std::wstring unicode) { _unicode = unicode; }
	std::wstring getUnicode() { return _unicode; }
	void setVari(int vari) { _vari = vari; }
	int getVari() { return _vari; }
	int getKoodi() { return _koodi; }
	void setKoodi(int koodi) { _koodi = koodi; }
};


class Torni : virtual public Nappula
{
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		// Nykyiset koordinaatit
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		// "oikealle" (dx = "delta x", eli x:n muutos)
		for (int dx = 1; dx <= 7; dx++)
		{
			// uudet koordinatit
			int new_x = x + dx;

			// mennäänkö yli laudan reunasta?
			if (new_x > 7)
				break;

			// mitä tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[new_x][y];

			// onko tyhjä ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
			}

			break;
		}












	}

};
