/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
Version 1.0
// Student Name  : Mohammadhossein Sobhanmanesh
// Student ID    : 116523200
// Student Email : msobhanmanesh@myseneca.ca
// Date          : 2021-12-5
// Course Section: OOP244-NAA
Revision History
-----------------------------------------------------------
Date      Reason
2020/12/5  Preliminary release
2020/12/5  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"
namespace sdds {
	class LibApp {

		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		char m_fileName[256]{};
		
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{}; //Publication Pointers Array "PPA"
		
		int m_NOLP{}; // Number Of Loaded Publications  "NOLP" for short
		int m_LLRN{}; //Last Library Reference Number "LLRN" for short

		Menu m_pubType;

		bool confirm(const char* message);

		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		//void search();  // prints: "Searching for publication"<NEWLINE>
		int search(int typeOfSearch); // recive if all as(1), onloan as (2), notOnloan as (3)
		
		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
		void newPublication();

		void removePublication();

		void checkOutPub();

	public:

		LibApp(const char* fileName);
		~LibApp();
		void run();

		Publication* getPub(int libRef);

		
	};

}
#endif // !SDDS_LIBAPP_H



