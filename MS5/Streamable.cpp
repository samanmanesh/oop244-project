/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streambable.cpp
Version 1.0
// Student Name  : Mohammadhossein Sobhanmanesh
// Student ID    : 116523200
// Student Email : msobhanmanesh@myseneca.ca
// Date          : 2021-11-30
// Course Section: OOP244-NAA
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/13  Preliminary release
2020/11/30  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"
using namespace sdds;
using namespace std;
namespace sdds {

	Streamable::~Streamable(){}

	ostream& operator<<(ostream& ostr, const Streamable& RO) {
		RO && RO.write(ostr);
		return ostr;
	};

	istream& operator>>(istream& istr, Streamable& RO) {
		return(RO.read(istr));
	};

}
