#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>
#include "Date.h"
#include "Streamable.h"
namespace sdds {

	class Publication : public Streamable {

		//char* m_title[255]{};
		char* m_title{};
		char m_shelfId[5]{};
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

		bool conIO(std::ios& io)const;

		std::ostream& write(std::ostream& os) const;
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
			os << m_membership;
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

	void Publication::resetDate() {

		// if useing m_date.setToToday() is private method

	};



	
};
#endif
