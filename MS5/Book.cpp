/* Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.cpp
Version 1.0
// Student Name  : Mohammadhossein Sobhanmanesh
// Student ID    : 116523200
// Student Email : msobhanmanesh@myseneca.ca
// Date          : 2021-11-30
// Course Section: OOP244-NAA
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
#include <cstring>
#include "Book.h"
#include "Lib.h"
using namespace sdds;
using namespace std;

namespace sdds {

	Book::Book() :Publication() {
	}

	Book::Book(const Book& B)  {

		*this = B;
	};

	Book& Book::operator=(const Book& B) {
		if (this != &B)
		{
			//call copy assignment of Publication
			//this form=> (Person&)*this = src;
			//(Publication&)*this = B;
			//or this form=>  Base::operator=(identifier);
			Publication::operator=(B);
			
			delete[]m_authorName;
			m_authorName = nullptr;

			if (B.m_authorName)
			{
				m_authorName = new char[Utils::strLen(B.m_authorName) + 1];
				Utils::strCpy(m_authorName, B.m_authorName);
			}
		}

		return *this;
	};

	Book::~Book()
	{
		delete[] m_authorName;
	}

	char Book::type()const {
		return 'B';
	};

	ostream& Book::write(ostream& os) const {
		Publication::write(os);
		if (conIO(os)) {

			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };

			std::strncpy(author, m_authorName, SDDS_AUTHOR_WIDTH);
			os.setf(ios::left);
			os << " ";
			os.width(SDDS_AUTHOR_WIDTH);
			os<< author<< " |";
			os.unsetf(ios::left);
		}
		else {
			os << "\t"<< m_authorName;
		}
		return os;
	}

	istream& Book::read(std::istream& is) {
		
		char authorName[256] = { 0 };

		Publication::read(is);                           

		delete[] m_authorName;                                 
		m_authorName = nullptr;

		if (Publication::conIO(is)) {
			is.ignore();                                 //ignore '\n'
			std::cout << "Author: ";
			is.get(authorName, sizeof(authorName), '\n');
		}
		else {
			is.ignore();                                //ingnore '\t'    
			is.get(authorName, sizeof(authorName), '\n');
		}

		if (is.good()) {         
			Utils::delAlloCopy(m_authorName, authorName);
			/*m_authorName = new char[Utils::strLen(author) + 1];
			Utils::strCpy(m_authorName, author);*/
		}

		return is;
	};

	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	};

	Book::operator bool() const {
	
		return m_authorName && m_authorName[0] && Publication::operator bool();

	};

	
}