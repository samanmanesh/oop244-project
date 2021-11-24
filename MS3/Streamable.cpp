
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
