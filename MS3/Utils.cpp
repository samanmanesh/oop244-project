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
#define _CRT_SECURE_NO_WARNINGS
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


	void Utils::getDynamicCstr(istream& istr, char* strToStore, const char delimiter ) {
		string tmp;
		getline(istr, tmp, delimiter);
		delete[] strToStore;
		strToStore = new char[strlen(tmp.c_str()) + 1];
		strcpy(strToStore, tmp.c_str());
	};

	void Utils::getCstr(istream& istr, char* strToStore, const int maxLen, const char delimiter ) {
		istr.getline(strToStore, maxLen, delimiter);
	};
}