
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
		//Publication::~Publication();
		delete[] m_authorName;
	}

	char Book::type()const {
		return 'B';
	};

	ostream& Book::write(ostream& os) const {
		Publication::write(os);
		// or I shouod overload conIO for Book too
		//if (conIO(os)) {
		//	
		//	os << " ";
		//	
		//	if (Utils::strLen(m_authorName) > SDDS_AUTHOR_WIDTH) {
		//		//os.width(SDDS_AUTHOR_WIDTH);
		//		for (int i = 0; i <SDDS_AUTHOR_WIDTH; i++)
		//		{
		//			os << m_authorName[i];
		//		}
		//	}
		//	else

		//		os << m_authorName;
		//	os << " |";
		//}
		//else
		//{
		//	os << '\t' << m_authorName;
		//}
		if (conIO(os)) {

			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };

			std::strncpy(author, m_authorName, SDDS_AUTHOR_WIDTH);

			os << " ";
			os.width(SDDS_AUTHOR_WIDTH);
			os<< author<< " |";
		}
		else {
			os << "\t"<< m_authorName;
		}
		return os;
	}

	istream& Book::read(std::istream& is) {
		/*Publication::read(is);
		char* authorName{};
		
		
		delete[] m_authorName;
		m_authorName = nullptr;
		
		if (conIO(is))
		{
			is.ignore();
			cout << "Author: ";
			authorName = Utils::dynRead(is);
		}
		else
		{
			is.ignore();
			authorName = Utils::dynRead(is);
		}

		if (is.good())
		{
			Utils::delAlloCopy(m_authorName, authorName);
		}*/
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
		resetDate();
	};

	Book::operator bool() const {
	
		return m_authorName && m_authorName[0] && Publication::operator bool();

	};

	
}