/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
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

#include <iostream>
#include <cstring>
#include <string>
#include "Utils.h"
using namespace std;
using namespace sdds;
namespace sdds {
		
	
	int Utils::getInt(int minRange, int maxRange, const char* errorMessage) {
		int selectedItem = 0;
		bool trueInt = false;
		while (trueInt == false)
		{
			cin >> selectedItem;
			if (cin.fail() || selectedItem < minRange || selectedItem > maxRange)
			{
				cout << errorMessage;
				cin.clear();
				cin.ignore(1000, '\n');
				trueInt = false;
			}
			else
			{
				trueInt = true;
			}

		}
		return selectedItem;
	};


	void Utils::getDynamicChar(istream& istr, char* charToStore, const char delimiter ) {
		
		string tmp;
		getline(istr, tmp, delimiter);

		delete[] charToStore;
		charToStore = new char[strlen(tmp.c_str()) + 1];
		strcpy(charToStore, tmp.c_str());
	
	};

	void Utils::getChar(istream& istr, char* charToStore, const int maxLen, const char delimiter ) {
		
		char tmp[128];
		istr.getline(tmp, maxLen, delimiter);
		
	};
}