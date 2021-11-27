/* Citation and Sources...
Final Project Milestone 2
Module: Streamable
Filename: Streambable.h
Version 1.0
Author	Mohammadhossein Sobhanmanesh
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/13  Preliminary release
2020/11/26  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds {

	class Streamable
	{
	public:
		
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		
		virtual std::istream& read(std::istream& istr) = 0;

		virtual bool conIO(std::ios& iosref)const = 0;
		
		virtual operator bool() const = 0;

		virtual ~Streamable();

	};


	std::ostream& operator<<(std::ostream& ostr, const Streamable& RO);

	std::istream& operator>>(std::istream& istr, Streamable& RO);

}
#endif


