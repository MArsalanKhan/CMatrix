// main.cpp

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>				// Header f�r die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>

using namespace std;			// erspart, den scope vor Objekte der C++-Standard-Bibliothek zu schreiben
								// z.B. statt "std::cout" kann man "cout" schreiben
#include "CMatrix.h"

////////////////////////////////////////////////////////////////////////////////
// Funktionen oder Klassen


////////////////////////////////////////////////////////////////////////////////
// Hauptprogramm 
int* gp;

int main (void)
{

	//The matrix program

	CMatrix a(4,4,INIT_UNIT) ;	//Define some objects
	CMatrix b(4,4,INIT_INDEX) ;
	CMatrix c(3,2,INIT_ZEROS) ;
	CMatrix d(2,2) ;
	CMatrix e(6) ;

	a.print() ;					//Show them

	a.add(b) ;					// A += B, if possible
	a.print() ;

	return EXIT_SUCCESS;		
}
