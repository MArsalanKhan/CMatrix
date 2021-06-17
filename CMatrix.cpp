// GIT-Labor
// CMatrix.cpp

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <stdlib.h>
#include "CMatrix.h"
#include <iostream>
#include <iomanip>
using namespace std;
	
	// TODO: ggf. Einf�gen weiterer Header-Dateien

////////////////////////////////////////////////////////////////////////////////
// Funktionen oder Klassen

// Konstruktor
CMatrix::CMatrix(int rows, int columns, int ini_mode)
{
	//Normal member variables
	m_rows = rows ;
    m_columns = columns;
    m_size = m_rows*m_columns ;


	//Allocate memory for the matrix
    m_p_array = new double[m_size];

	//Temporary pointer for iterating through the array
	//Note: Never change the variable containing the start adress
	double* p=m_p_array ;

	//Initialize the matrix
    switch (ini_mode)
    {
        case INIT_ZEROS:
			for (int k=0 ; k<m_size; k++)  *p++ = 0.0;
			break ;
        case INIT_UNIT:
			for (int k=0; k<m_size; k++)  *p++ = 0.0;	// fill with zeroes
			//This one only works with quadratic matrices
			if (m_rows == m_columns)
			{
			    for (int k=0; k<m_rows; k++)
					*(m_p_array+k*m_rows+k) = 1.0 ;		// fill the main diagonal with ones
			}
			break ;
        case INIT_INDEX:
			for (int k=0 ; k<m_size; k++)  *p++ = k ;	// fill it with the index
			break ;
        default:	
			break ;
    }

	cout << "Construktor " << " @ " << this << " dimension x=" << rows << ", y=" << columns<< endl ;
}

// Destructor
CMatrix::~CMatrix()
{
	cout << "Destructor " << endl ;
	//One element less
	delete[] m_p_array ; 	// free allocated memory
}

// Print the matrix
void CMatrix::print()
{

	for (int k=0; k<m_rows; k++)
	{
		for (int j=0; j<m_columns; j++)
		{
			cout << setw(8) << right << *(m_p_array+k*m_columns+j) ;
			// cout << setw(8) << right << m_p_array[j][k]; // this one does not work, 
															// because the arrays has been generated as a 
															// sequence without dimensions
		}
		cout << endl ;
	}
	cout << endl ;
}


// void CMatrix::Madd(CMatrix& b)		// a += b , by reference
void CMatrix::add(const CMatrix& b)		// a += b , by value
{
	if ((m_rows == b.m_rows) && (m_columns == b.m_columns))
	{
		for (int k=0; k<m_rows; k++)
		{
			for (int j=0; j<m_columns; j++)
			{
				*(m_p_array+k*m_columns+j) += *(b.m_p_array+k*m_columns+j) ;
			}
		}

	}
	else
	{
		warning(2,"CMatrix::add(): Dimensions do not fit");
	}
}

void CMatrix::message(string s)
{
	cout << s << endl;
}

void CMatrix::warning(int level, string s)
{
	cout << "WARNING: " << s << endl;
	if (level == 2)
	{
		system("pause");
	}
}

