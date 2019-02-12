class Kuningatar: virtual public Torni : virtual public Lahetti
{
	virtual void annaSiirrot(
		list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		// Nykyiset koordinaatit
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		
		{
			// uudet koordinatit
			int new_y = y + dy;

			// mennäänkö yli laudan reunasta?
			if (new_y > 7)
				break;

			// mitä tutkittavassa ruudussa (x, new_y) on?
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
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			}

			break;
		}
