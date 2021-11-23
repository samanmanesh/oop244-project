

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
using namespace sdds;
using namespace std;

namespace sdds {
		
	Publication::Publication()
	{
		// just to make sure both works but dont need this
		char* m_title = nullptr;
		char m_shelfId[5] = "\0";
		int m_membership = 0;
		int m_libRef = -1;
	}

	Publication::Publication(const Publication& pbc) {
	
		if (pbc.m_title && pbc.m_shelfId)
		{
			delete[] m_title;
			m_shelfId[0]='\0';
			m_title = new char[strlen(pbc.m_title) + 1];
			strcpy(m_title, pbc.m_title);
			strcpy(m_shelfId, pbc.m_shelfId);
			m_membership = pbc.m_membership;
			m_libRef = pbc.m_libRef;
			m_date = pbc.m_date;
		}
	
	};
	Publication& Publication::operator=(const Publication& pbc) {
		if (this != &pbc)
		{
			delete[] m_title;
			m_shelfId[0] = '\0';
			m_title = new char[strlen(pbc.m_title) + 1];
			strcpy(m_title, pbc.m_title);
			strcpy(m_shelfId, pbc.m_shelfId);
			m_membership = pbc.m_membership;
			m_libRef = pbc.m_libRef;
			m_date = pbc.m_date;

		}
		return *this;
	};

	Publication::~Publication()
	{	
		delete[] m_title;
		delete[] m_shelfId;
	}

	void Publication::set(int member_id) {
		m_membership = member_id;
	};

	void Publication::setRef(int value) {
		m_libRef = value;
	};


	char Publication::type()const {
		return ('P');
	};

	bool Publication::onLoan()const {
		return(m_membership != 0);
	};

	Date Publication::checkoutDate()const {
		return m_date;
	};

	bool Publication::operator==(const char* title)const {

		return(strstr(m_title, title));
	};


	Publication::operator const char* ()const {
		return m_title;
	};

	int Publication::getRef()const {
		return m_libRef;
	};

};

