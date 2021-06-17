/////////////////////////////////////////////////////////////////////////////
// CMatrix.h
//
#ifndef CMatrix_H	
#define CMatrix_H

#include <iostream>
#include <string>
using namespace std;

enum ini_mode {INIT_ZEROS, INIT_UNIT, INIT_INDEX} ;	// Initmode

//A little bit oversized, but good programming practice
//define the constants which may be changed by the user here
//Mandatory if the constants
#define	DEF_ROWS	1
#define	DEF_COLUMNS	1
#define	DEF_INIT	INIT_ZEROS

class CMatrix
{
public:
	//Constructor, Copy Constructor, Destructor
	CMatrix(int rows=DEF_ROWS, int columns=DEF_COLUMNS, int inimode=DEF_INIT);
	~CMatrix();							

	//Some simple methods
	void add(const CMatrix& c) ;					
	void print() ;						

private:
	int m_rows;				
	int m_columns;			
	int m_size ;	//optional
	double* m_p_array;		

private:
	void warning(int level, string s);
	void message(string s);

    /** @link dependency */
    /*# ini_mode lnkini_mode; */
} ;

#endif
