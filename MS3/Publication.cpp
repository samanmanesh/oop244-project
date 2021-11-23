

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
		char m_chelfId[5] = "\0";
		int m_membership = 0;
		int m_libRef = -1;
	}

	Publication::~Publication()
	{
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

