

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds {

	class Streamable
	{
	public:
	
		virtual ostream& write(ostream& ostr) = 0;
		
		virtual istream& read(istream& istr) = 0;


		
		virtual ~Streamable();

	};

	

	Streamable::~Streamable()
	{
	}

	std::ostream& operator<<(std::ostream& ostr, const Streamable& RO);

	std::istream& operator>>(std::istream& istr, Streamable& RO);

}
#endif


