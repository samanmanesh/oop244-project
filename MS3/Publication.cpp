/* Citation and Sources...
Final Project Milestone 2
Module: Publication 
Filename: Publication.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Lib.h"
using namespace sdds;
using namespace std;

namespace sdds {

	Publication::Publication() {}

	Publication::Publication(const Publication& pbc) {

		*this = pbc;

	};
	Publication& Publication::operator=(const Publication& pbc) {
		if (this != &pbc)
		{
			if (m_title)
			{
				delete[] m_title;
				m_title = nullptr;
			}

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
		return 'P';
	};

	bool Publication::onLoan()const {
		return m_membership != 0;
	};

	Date Publication::checkoutDate()const {
		return m_date;
	};

	bool Publication::operator==(const char* title)const {

		return strstr(m_title, title) != nullptr;
	};


	Publication::operator const char* ()const {
		return m_title;
	};

	int Publication::getRef()const {
		return m_libRef;
	};


	bool Publication::conIO(const ios& iosref)const {
		return &iosref == &std::cin || &iosref == &std::cout;
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


	//istream& Publication::read(istream& istr) {

	//	//char* title = new char[SDDS_TITLE_WIDTH + 1];
	//	//char shelfId[SDDS_SHELF_ID_LEN + 1] = { 0 };
	//	////char* shelfId = nullptr;
	//	//int membership = 0;
	//	//int libRef = -1;
	//	//Date date;
	//	//setTodefaultValue();

	//	//if (conIO(istr))
	//	//{
	//	//	cout << "Shelf No: ";
	//	//	//shelfId = Utils::dynRead(istr, '\n');
	//	//	istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
	//	//	if (Utils::strLen(shelfId) != SDDS_SHELF_ID_LEN)
	//	//	{
	//	//		istr.setstate(ios::failbit);
	//	//	}


	//	//	cout << "Title: ";
	//	//	//title = Utils::dynRead(istr, '\n');
	//	//	istr.getline(title, SDDS_TITLE_WIDTH + 1);
	//	//	if (title == nullptr || Utils::strLen(title) > SDDS_TITLE_WIDTH)
	//	//	{
	//	//		istr.setstate(ios::failbit);
	//	//	}
	//	//	cout << "Date: ";
	//	//	//date.read(istr);
	//	//	istr >> date;


	//	//}
	//	char shelfid[SDDS_SHELF_ID_LEN + 2] = { 0 },
	//		title[256] = { 0 };

	//	int libref = -1, membership = 0;

	//	Date date;

	//	if (m_title) {
	//		delete[] m_title;
	//		m_title = nullptr;
	//	}

	//	m_membership = 0;
	//	m_libRef = -1;
	//	m_shelfId[0] = 0;

	//	if (conIO(istr)) {
	//		std::cout << "Shelf No: ";
	//		istr.get(shelfid, SDDS_SHELF_ID_LEN + 2);
	//		if (istr.gcount() != SDDS_SHELF_ID_LEN) {
	//			istr.setstate(std::ios_base::failbit);        //Set to invalid state
	//		}
	//		else {
	//			istr.ignore(1000, '\n');
	//		}

	//		std::cout << "Title: ";
	//		istr.get(title, sizeof(title), '\n');
	//		std::cout << "Date: ";
	//		istr >> date;
	//	}
	//	else
	//	{
	//		istr >> libref;
	//		istr.ignore();
	//		istr.getline(shelfid, SDDS_SHELF_ID_LEN + 1, '\t');
	//		//istr.ignore();
	//		istr.getline(title, Utils::strLen(title), '\t');
	//		//istr.ignore();
	//		istr >> membership;
	//		istr.ignore();
	//		istr >> date;


	//	}
	//	if (!date) {
	//		istr.setstate(std::ios_base::failbit);        //Set to invalid state
	//	}

	//	if (istr.good()) {                               //Fill attributes
	//		m_title = new char[std::strlen(title) + 1];
	//		std::strcpy(m_title, title);

	//		std::strcpy(m_shelfId, shelfid);

	//		m_membership = membership;

	//		m_date = date;

	//		m_libRef = libref;
	//	}
	//	//if (!date)
	//	//	istr.setstate(ios::failbit);

	//	//if (istr.good()) {
	//	//	//delete[] m_title;
	//	//	m_title = new char[Utils::strLen(title) + 1];
	//	//	Utils::strCpy(m_title, title);

	//	//	Utils::strCpy(m_shelfId, shelfid);

	//	//	set(membership);

	//	//	m_date = date;

	//	//	setRef(libref);
	//	//}

	//	return istr;
	//};

	Publication::operator bool() const {

		return m_title && m_shelfId[0];
	};



	 std::istream & Publication::read  ( std::istream &is ){
        char shelfid[SDDS_SHELF_ID_LEN+2] = {0},
             title[256] = {0};

        int libref = -1, membership = 0;

        Date date;

        if ( m_title ){
            delete [] m_title;
            m_title = nullptr;
        }

        m_membership = 0;
        m_libRef     = -1;
        m_shelfId[0] = 0;

        if ( conIO(is) ){
            std::cout << "Shelf No: ";
            is.get(shelfid, SDDS_SHELF_ID_LEN+2);
            if ( is.gcount() != SDDS_SHELF_ID_LEN ){
                is.setstate(std::ios_base::failbit);        
            }
            else{
                is.ignore(1000,'\n');
            }

            std::cout << "Title: ";
            is.get(title,sizeof(title),'\n');
            std::cout << "Date: ";
            is  >> date;
        }
        else{
            is >> libref;
            is.ignore();         
            is.get(shelfid,SDDS_SHELF_ID_LEN+1,'\t');
            is.ignore();         
            is.get(title,sizeof(title),'\t');
            is.ignore();          
            is >> membership;
            is.ignore();          
            is >> date;
        }

        if ( !date ){
            is.setstate(std::ios_base::failbit);        
        }

        if ( is.good() ){                               
            m_title = new char[std::strlen(title)+1];
            std::strcpy ( m_title, title );

            std::strcpy ( m_shelfId, shelfid );

            m_membership = membership;

            m_date = date;

            m_libRef = libref;



        }

        return is;
    }

};

