

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Publication.h"
#include "Lib.h"
using namespace sdds;
using namespace std;

namespace sdds {

	Publication::Publication(){}

	Publication::Publication(const Publication& pbc) {

		*this = pbc;

	};
	Publication& Publication::operator=(const Publication& pbc) {
		if (this != &pbc)
		{
			delete[] m_title;
			m_title = nullptr;

			if (pbc.m_title)
			{
				m_title = new char[Utils::strLen(pbc.m_title) + 1];
				Utils::Utils::strCpy(m_title, pbc.m_title);
			}


			Utils::Utils::strCpy(m_shelfId, pbc.m_shelfId);

			set(pbc.m_membership);
			setRef(pbc.m_libRef);
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
			os.width(SDDS_TITLE_WIDTH);
			os << m_title;
			os.unsetf(ios::left);
			os.fill(' ');
			os << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | ";
			os << m_date;
			os << " |";
		}
		else
		{
			os << type();
			os << "\t";
			os << m_libRef;
			os << "\t";
			os << m_shelfId;
			os << "\t";
			os << m_title;
			os << "\t";
			os << m_membership;
			os << "\t";
			os << m_date;
		}
		return os;
	};

	void Publication::setTodefaultValue() {
		delete[] m_title;
		m_title = nullptr;

		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
	};


	istream& Publication::read(istream& istr) {
		
		char* title = new char[SDDS_TITLE_WIDTH + 1];
		char shelfId[SDDS_SHELF_ID_LEN + 1] = { 0 };
		//char* shelfId = nullptr;
		int membership = 0;
		int libRef = -1;
		Date date;
		setTodefaultValue();

		if (conIO(istr))
		{
			cout << "Shelf No: ";
			//Utils::getCstr(istr, shelfId, SDDS_SHELF_ID_LEN + 1);
			//istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
			//shelfId = Utils::dynRead(istr, '\n');
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
			if (Utils::strLen(shelfId) != SDDS_SHELF_ID_LEN)
			{
				//istr.ignore(1000, '\n');
				istr.setstate(ios::failbit);

			}
			/*else {
				istr.ignore(1000, '\n');
			}*/

			cout << "Title: ";
			//Utils::getDynamicCstr(istr, title);
			//istr.get(title, Utils::strLen(title), '\n');
			//title = Utils::dynRead(istr, '\n');
			istr.getline(title, SDDS_TITLE_WIDTH + 1);
			if ( title == nullptr || Utils::strLen(title) > SDDS_TITLE_WIDTH)
			{
				istr.setstate(ios::failbit);
			}
			cout << "Date: ";
			//date.read(istr);
			
			
				istr >> date;
			

		}
		else
		{
			istr >> libRef;
			istr.ignore();          //Ignore TAB
			istr.get(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.ignore();          //Ignore TAB

			//istr.get(title, sizeof(title), '\t');
		/*	if (title)
			{
				
			}*/
			//istr.get(title, Utils::strLen(title), '\t');
			istr.get(title, Utils::strLen(title), '\t');
			istr.ignore();          //Ignore TAB
			istr >> membership;
			istr.ignore();          //Ignore TAB
			istr >> date;


		}

		if (!date)
			istr.setstate(ios::failbit);

		if (!istr.fail()) {
			delete[] m_title;
			m_title = new char[Utils::strLen(title) + 1];
			Utils::strCpy(m_title, title);
	
			Utils::strCpy(m_shelfId, shelfId);

			set(membership);

			m_date = date;

			setRef(libRef);
		}
		


		return istr;
	};

	Publication::operator bool() const {

		return(m_title || m_shelfId[0]);
	};

};

