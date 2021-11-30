
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Date.h"
#include "Publication.h"
#include "Utils.h"
#include "Lib.h"

namespace sdds {

	class Book :public Publication {

		char* m_authorName{};

	public:
		Book();
		Book(const Book& B);
		Book& operator=(const Book& B);
		~Book();

		char type()const;

		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);

		void set(int member_id);

		operator bool() const;

		//bool conIO(const std::ios& iosref)const;
	};


}
#endif