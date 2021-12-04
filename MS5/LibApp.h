/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.
Version 1.0
Author	Mohammadhossein Sobhanmanesh
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/16  Preliminary release
2020/11/16  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
namespace sdds {
	class LibApp {

		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		char pubDataFileName[256]{};
		
		char* m_PPA{}; //Publication Pointers Array "PPA"
		
		int m_NOLP{}; // We will call this attribute "NOLP" for short, from now on.
		int m_LLRN{}; //We will call this attribute "LLRN" for short, from now on.

		Menu m_pubType;

		bool confirm(const char* message);

		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		void search();  // prints: "Searching for publication"<NEWLINE>

		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
		void newPublication();

		void removePublication();

		void checkOutPub();

	public:

		LibApp();
		~LibApp();
		void run();
	};

}
#endif // !SDDS_LIBAPP_H



