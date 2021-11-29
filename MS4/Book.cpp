
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

	Book::Book(const Book& B) : Publication(B) {

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
		Publication::~Publication();
		delete[] m_authorName;
	}

	char Book::type()const {
		return 'B';
	};

}