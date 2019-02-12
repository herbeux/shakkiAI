#pragma once

#include <list>
#include <string>
#include "asema.h"
#include "nappula.h"



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


// "ylös" (dy = "delta y", eli y:n muutos)
		for (int dy = 1; dy <= 7; dy++)
		{
			// uudet koordinatit
			int new_y = x + dy;

			// mennäänkö yli laudan reunasta?
			if (new_y > 7)
				break;

			// mitä tutkittavassa ruudussa (new_y, x) on?
			Nappula* n = asema->_lauta[x][new_y];

			// onko tyhjä ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x,new_y)));
			}

			break;
		}









	}

};
