#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
#include "Date.h"
namespace sdds {

	class Publication {

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


		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"

		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)

		Date checkoutDate()const;
		//Returns the date attribute

		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)

		operator const char* ()const;
		//Returns the title attribute

		int getRef()const;
		//Returns the libRef attirbute. 


	};



	void Publication::resetDate() {

		// if useing m_date.setToToday() is private method

	};



	
};
#endif
