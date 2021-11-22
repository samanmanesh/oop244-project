
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Streamable.h"
using namespace sdds;
using namespace std;
namespace sdds {





	ostream& operator<<(ostream& ostr, const Streamable& RO) {
	
		return ostr;
	};

	istream& operator>>(istream& istr, Streamable& RO) {
		//RO.readShape(istr);
		return istr;
	};

}
