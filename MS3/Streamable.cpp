
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Streamable.h"
using namespace sdds;
using namespace std;
namespace sdds {

	Streamable::~Streamable(){}

	ostream& operator<<(ostream& ostr, const Streamable& RO) {
		return (RO.write(ostr));
	};

	istream& operator>>(istream& istr, Streamable& RO) {
		return(RO.read(istr));
	};

}
