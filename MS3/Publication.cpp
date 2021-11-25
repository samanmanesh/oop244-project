

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Lib.h"
using namespace sdds;
using namespace std;

namespace sdds {

	Publication::Publication()
	{
	}

	Publication::Publication(const Publication& pbc) {

		*this = pbc;
		/*if (pbc.m_title && pbc.m_shelfId)
		{
			delete[] m_title;
			m_shelfId[0]='\0';
			m_title = new char[strlen(pbc.m_title) + 1];
			strcpy(m_title, pbc.m_title);
			strcpy(m_shelfId, pbc.m_shelfId);
			m_membership = pbc.m_membership;
			m_libRef = pbc.m_libRef;
			m_date = pbc.m_date;
		}*/

	};
	Publication& Publication::operator=(const Publication& pbc) {
		if (this != &pbc)
		{
			delete[] m_title;
			m_title = nullptr;

			if (pbc.m_title)
			{
				m_title = new char[strlen(pbc.m_title) + 1];
				strcpy(m_title, pbc.m_title);
			}

			//m_shelfId[0] = '\0';
			strcpy(m_shelfId, pbc.m_shelfId);
			//m_membership = pbc.m_membership;
			set(pbc.m_membership);
			setRef(pbc.m_libRef);
			//m_libRef = pbc.m_libRef;
			m_date = pbc.m_date;

		}
		return *this;
	};

	Publication::~Publication()
	{
		delete[] m_title;
	}

	void Publication::set(int member_id) {
		m_membership = member_id;
	};

	void Publication::setRef(int value) {
		m_libRef = value;
	};

	void Publication::resetDate() {
		m_date = Date();
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

		return(strstr(m_title, title) != nullptr);
	};


	Publication::operator const char* ()const {
		return m_title;
	};

	int Publication::getRef()const {
		return m_libRef;
	};


	bool Publication::conIO(ios& iosref)const {
		bool result = ((&iosref == &cin) || (&iosref == &cout)) ? true : false;
		return result;
	};


	ostream& Publication::write(ostream& os) const {

		if (conIO(os)) {
			os << "| ";
			os << m_shelfId;
			os << " | ";
			os.setf(ios::left);
			os.fill('.');
			//os.width(40);
			os.width(SDDS_TITLE_WIDTH);
			os << m_title;
			os.unsetf(ios::left);
			os.fill(' ');
			os << "| ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | ";
			os << m_date;
			os << " |";
		}
		else
		{
			//os.width(10);
			os << type();
			//os.width(6);
			os << "\t";
			os << m_libRef;
			//os.width(8);
			os << "\t";
			os << m_shelfId;
			//os.width(23);
			os << "\t";
			os << m_title;
			//os.width(7);
			os << "\t";
			os << m_membership;
			os << "\t";
			os << m_date;
		}
		return os;
	};

	void Publication::setTodefaultValue() {
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
	};


	istream& Publication::read(istream& istr) {
		char title[256] = { 0 };
		//char* title = nullptr;
		//char* shelfId = new char[SDDS_SHELF_ID_LEN + 1];
		char shelfId[SDDS_SHELF_ID_LEN + 2] = { 0 };
		int membership = 0;
		int libRef = -1;
		Date D;
		setTodefaultValue();

		if (conIO(istr))
		{
			cout << "Shelf No: ";
			//Utils::getCstr(istr, shelfId, SDDS_SHELF_ID_LEN + 1);
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);

			if (strlen(shelfId) != SDDS_SHELF_ID_LEN)
			{
				istr.setstate(ios_base::failbit);
			//	cout << "read here" << endl;
			}

			cout << "Title: ";
			//Utils::getDynamicCstr(istr, title);
			istr.get(title, strlen(title), '\n');

			cout << "Date: ";
			D.read(istr);
			//istr >> D;

		}
		else
		{
			istr >> libRef;
			istr.ignore();          //Ignore TAB
			istr.get(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.ignore();          //Ignore TAB

			//istr.get(title, sizeof(title), '\t');
			if (title)
			{
				istr.get(title, strlen(title), '\t');
			}
			//istr.get(title, strlen(title), '\t');

			istr.ignore();          //Ignore TAB
			istr >> membership;
			istr.ignore();          //Ignore TAB
			istr >> D;


		}
		if (!D) 
			istr.setstate(ios_base::failbit);

		if (!istr.fail()) {
			//delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		else
		{
			m_title = nullptr;
		}

		strcpy(m_shelfId, shelfId);

		set(m_membership);

		m_date = D;

		setRef(libRef);

		return istr;
	};

	Publication::operator bool() const {

		return(m_title || m_shelfId[0]);
	};

};

