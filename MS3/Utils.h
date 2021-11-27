/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 2
// Date	2020/11/26
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

		void static getDynamicCstr(std::istream& istr, char* strToStore, const char delimiter ='\n');

		void static getCstr(std::istream& istr, char* strToStore, const int maxLen , const char delimiter = '\n');

		int static strLen(const char* str);
		void static strCpy(char* des, const char* src);
		void static strCat(char* des, const char* src);
		void static delAlloCopy(char*& des, const char* src);
		static char* dynRead(std::istream& istr, char delimeter = '\n');
	};
}
#endif // SDDS_UTILS_H__
