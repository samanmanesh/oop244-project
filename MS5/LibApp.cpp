/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
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
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LibApp.h"
#include"Utils.h"
#include <fstream>
using namespace std;
using namespace sdds;

namespace sdds {


	LibApp::LibApp() :m_changed(false), m_mainMenu("Seneca Library Application"
	), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubType("Choose the type of publication:") {

		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		;
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

		m_pubType << "Book" << "Publication";

		load();
	};

	bool LibApp::confirm(const char* message) {
		bool result = false;
		int returnedValue = 0;

		Menu confirmMenu(message);
		confirmMenu << "Yes";

		returnedValue = confirmMenu.run();

		result = (returnedValue == 1) ? true : false;

		return result;
	};

	void LibApp::load() {
		cout << "Loading Data" << endl;
		ifstream infile("LibRecs.txt");
		char type{};
		int i;
		for (i = 0; infile && SDDS_LIBRARY_CAPACITY; i++) {
			infile >> type;
			infile.ignore();

			if (infile) {
				if (type == 'P')
					m_PPA[i] = new Publication;

				else if (type == 'B')
					m_PPA[i] = new Book;
			}

			if (m_PPA[i])
			{
				infile >> *m_PPA[i];
				m_NOLP++;
				//m_LLRN = m_PPA[i]->getRef();
			}
		}
		m_LLRN = m_PPA[m_NOLP]->getRef();
	};

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream onfile("LibRecs.txt");
		int i;
		for ( i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() != 0)
			{
				onfile << *m_PPA[i];
				//onfile << m_PPA[i];
			}
		}

	};

	void LibApp::search() {
		cout << "Searching for publication" << endl;
	};

	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	};

	LibApp::~LibApp() {};

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;

		if (confirm("Add this publication to library?"))
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}
	};

	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();

		if (confirm("Remove this publication from the library?")) {

			m_changed = true;
			cout << "Publication removed" << endl;
		}
	};

	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?")) {

			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	};


	void LibApp::run() {
		unsigned int returnedValue = 1;

		while (returnedValue != 0)
		{
			returnedValue = m_mainMenu.run();
			if (returnedValue == 1)
			{
				newPublication();
			}
			else if (returnedValue == 2) {

				removePublication();
			}
			else if (returnedValue == 3)
			{
				checkOutPub();
			}
			else if (returnedValue == 4)
			{
				returnPub();
			}


			//for exitMenu when user select 0 in mainMenu 
			if (returnedValue == 0 && m_changed == true)
			{
				int result = 0;
				result = m_exitMenu.run();
				if (result == 1)
				{
					save();
				}
				else if (result == 2) {


					returnedValue = 1; // to return to main menu again
				}
				else if (result == 0)
				{
					if (confirm("This will discard all the changes are you sure?")) {

						m_changed = false;

					}
				}
			}
			cout << endl;
		}
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;

	};


}
