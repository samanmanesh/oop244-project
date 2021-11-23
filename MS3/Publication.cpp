

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


	bool Publication::conIO(ios& io)const {
		bool result = ((&io == &cin) || (&io == &cout)) ? true : false;
		return result;
	};


	ostream& Publication::write(ostream& os) const {

		if (conIO(os)) {
			os << "| ";
			os << m_shelfId;
			os << " | ";
			os.setf(ios::left);
			os.fill('.');
			os.width(40);
			os << m_title;
			os.unsetf(ios::left);
			os.fill(' ');
			os << "| ";
			(m_membership != 0) ? os << m_membership : os << "N/A";
			os << " | ";
			os << m_date;
			os << " |";
		}
		else
		{
			os.width(10);
			os << type();
			os.width(6);
			os << m_libRef;
			os.width(8);
			os << m_shelfId;
			os.width(23);
			os << m_title;
			os.width(7);
			os << m_membership;
			os << m_date;
		}
	};

	void Publication::setTodefaultValue() {
		char* m_title = nullptr;
		char m_shelfId[5] = "\0";
		int m_membership = 0;
		int m_libRef = -1;
	};


	istream& Publication::read(istream& istr) {

		char* title = nullptr;
		char shelfId[5] = "\0";
		int membersheip = 0;
		int libRef = -1;
		Date D;
		setTodefaultValue();
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			Utils::getChar(istr, shelfId, SDDS_SHELF_ID_LEN);
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN) istr.setstate(ios::failbit);
			cout << "Title: ";
			Utils::getDynamicChar(istr, title);
			cout << "Date: ";
			do {
				D.read(istr);      // get Date from console
			} while (!D && cout << D.dateStatus() << ", Please try again > ");  // if D is invalid, print error message and loop
			//istr >> D;

		}
		else
		{
			//std::ifstream("Periodicals.txt"); or
			std::fstream iofile("Periodicals.txt", ios::in);

			while (iofile)
			{
				iofile >> libRef;
				iofile.ignore();
				iofile >> shelfId;
				iofile.ignore();
				iofile >> title;
				iofile.ignore();
				iofile >> membersheip;
				iofile.ignore();
				iofile >> D;
			}

		}
		if (!D) istr.setstate(ios::failbit);

		if (!istr.fail()) {
			delete[] m_title;
			strcpy(m_title, title);

			strcpy(m_shelfId, shelfId);

			set(m_membership);
			m_date = D;
			setRef(libRef);
		}
		return istr;
	};

	Publication::operator bool() const {

		return(m_title == nullptr || m_shelfId == nullptr);
	};


	void Publication::resetDate() {


		// if useing m_date.setToToday() is private method
		m_date.setToToday();
	};


};

