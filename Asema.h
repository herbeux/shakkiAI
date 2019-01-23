#pragma once
#include <iostream>
#include <string>
#include "Nappula.h"
using namespace std;




class Asema {

private:
_VK = unicode L"\u2654	
_VD = unicode L"\u2655	
_VT = unicode L"\u2656	 
_VL,= unicode L"\u2657	
_VR,= unicode L"\u2658	
_VS,= unicode L"\u2659"
_MK,= unicode L"\u265A	
_MD,=unicode L"\u265B
_MT,=unicode L"\u265C”
_ML,= unicode L"\u265D"
_MR,= unicode L"\u265E"
_MS,= unicode L"\u265F"


public:
	//Konstruktori luo alkuaseman laudalle
	Asema();
	Nappula* lauta[8][8];
};


class Kayttoliittyma{

public:
	Kayttoliittyma(Asema* asema);
	Asema* asema;
	void piirraLauta();
};
