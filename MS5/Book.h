/* Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.h
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Date.h"
#include "Publication.h"
#include "Utils.h"
#include "Lib.h"

namespace sdds {

	class Book :public Publication {

		char* m_authorName{};

	public:
		Book();
		Book(const Book& B);
		Book& operator=(const Book& B);
		~Book();

		char type()const;

		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);

		void set(int member_id);

		operator bool() const;

		//bool conIO(const std::ios& iosref)const;
	};


}
#endif