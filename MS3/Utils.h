/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 1
// Date	2020/11/16
// Author	Mohammadhossein Sobhanmanesh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {

	class Utils
	{
	public:

		int static getInt(int minRange, int maxRange, const char* errorMessage);

		void static getDynamicChar(std::istream& istr, char* charToStore, const char delimiter ='\n');

		void static getChar(std::istream& istr, char* charToStore, const int maxLen , const char delimiter = '\n');
	};
}
#endif // SDDS_UTILS_H__
