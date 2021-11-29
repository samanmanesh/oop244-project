
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
		~Book();

	};

	Book::Book(){}

	Book::~Book()
	{
	}



}
#endif