#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
#include "Date.h"
namespace sdds {

	class Publication{	
		
		//char* m_title[255]{};
		char* m_title{};
		char m_chelfId[5]{};
		int m_membership = 0;
		int m_libRef = -1;
		Date m_date;

	public:
		Publication();
		~Publication();

		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		
		void setRef(int value);
		// Sets the **libRef** attribute value
		
		void resetDate();
		// Sets the date to the current date of the system.


	};

	Publication::Publication()
	{
		// just to make sure both works but dont need this
		char* m_title= nullptr;
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
	
	void Publication::resetDate() {
		
		// if useing m_date.setToToday() is private method
		
	};
};
#endif
