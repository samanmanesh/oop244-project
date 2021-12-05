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
		for (i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() != 0)
			{
				onfile << *m_PPA[i];
				//onfile << m_PPA[i];
			}
		}

	};

	int LibApp::search(int typeOfSearch) { // recive if all as(1), on loan as (2), not on loan as (3)
		cout << "Searching for publication" << endl;
		PublicationSelector PBS("Select one of the following found matches:", 15);
		int selectedPubType = 0;
		char title[256]{};
		int libRef{};
		//switch (typeOfSearch)
		//{
		//case 1:
		//	//search all
		//	selectedPubType = m_pubType.run();
		//	break;
		//case 2:
		//	//search on loan
		//	selectedPubType = m_pubType.run();
		//	
		//	break;
		//case 3:
		//	//search not on loan
		//	selectedPubType = m_pubType.run();


		//	break;
		//default :
		//	break;
		//}

		selectedPubType = m_pubType.run();

		if (selectedPubType != 0)
		{
			cout << "Publication Title: ";
			cin.getline(title, 256);

			if (typeOfSearch == 1)
			{
				if (selectedPubType == 1)
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						const char taypeOfPPA = m_PPA[i]->type();

						if (taypeOfPPA == 'B' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title)) {

							PBS << m_PPA[i];
						}

					}

				}
				else if (selectedPubType == 2)
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						const char taypeOfPPA = m_PPA[i]->type();

						if (taypeOfPPA == 'P' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title))
						{
							PBS << m_PPA[i];
						};
					}
				}
				else if (selectedPubType == 0)
				{
					cout << "Aborted!" << endl;
				}

			}
			else if (typeOfSearch == 2) {

				if (selectedPubType == 1)
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						const char taypeOfPPA = m_PPA[i]->type();
						int loanStatus = m_PPA[i]->onLoan();

						if (!loanStatus && taypeOfPPA == 'B' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title)) {

							PBS << m_PPA[i];
						}
					}
				}
				else if (selectedPubType == 2)
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						const char taypeOfPPA = m_PPA[i]->type();
						int loanStatus = m_PPA[i]->onLoan();

						if (!loanStatus && taypeOfPPA == 'P' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title))
						{
							PBS << m_PPA[i];
						};
					}
				}
				else if (selectedPubType == 0)
				{
					cout << "Aborted!" << endl;
				}

			}
			else if (typeOfSearch == 3) {

				if (selectedPubType == 1)
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						const char taypeOfPPA = m_PPA[i]->type();
						int loanStatus = m_PPA[i]->onLoan();

						if (!loanStatus && taypeOfPPA == 'B' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title)) {

							PBS << m_PPA[i];
						}
					}
				}
				else if (selectedPubType == 2)
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						const char taypeOfPPA = m_PPA[i]->type();
						int loanStatus = m_PPA[i]->onLoan();

						if (!loanStatus && taypeOfPPA == 'P' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title))
						{
							PBS << m_PPA[i];
						};
					}
				}
				else if (selectedPubType == 0)
				{
					cout << "Aborted!" << endl;
				}
			}
		}
		else if (selectedPubType == 0) cout << "Aborted!" << endl;

		if (selectedPubType != 0 && PBS) // matches is found
		{
			PBS.sort();
			libRef = PBS.run();
		}
		else
		{
			cout << "No matches found!" << endl;
		}
		return libRef;
	};

	void LibApp::returnPub() {
		search(1);
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	};

	LibApp::~LibApp() {
		delete[] m_PPA;
	};

	void LibApp::newPublication() {
		/*cout << "Adding new publication to library" << endl;

		if (confirm("Add this publication to library?"))
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}*/

		int type = 0;
		Publication* dynPublication{};

		if (m_NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			cout << "Adding new publication to the library" << endl;
			type = m_pubType.run();

			if (type == 1)
			{
				dynPublication = new Book;
				dynPublication->read(cin);
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!";
				}
			}
			else if (type == 2)
			{
				dynPublication = new Publication;
				dynPublication->read(cin);
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!";
				}
			}
			if (cin)
			{
				//cout << "Add this publication to the library?" << endl;
				if (confirm("Add this publication to the library?")) {
					if (dynPublication)
					{
						m_LLRN++;
						m_PPA[m_NOLP]->setRef(m_LLRN);
						m_PPA[m_NOLP] = dynPublication;
						m_NOLP++;
						m_changed = true;
						cout << "Publication added" << endl;
					}
					else
					{
						cout << "Failed to add publication!" << endl;
						delete[] dynPublication;
					}
							
				}
				else
				{
					cout << "Aborted!";
					//maybe not required
					delete[] dynPublication;
				};
			}
			
		}
		//maybe not required
		delete[] dynPublication;
	};

	void LibApp::removePublication() {
		int libRef{};
		cout << "Removing publication from library" << endl;
		libRef=search(1); // search all publication

		if (libRef && confirm("Remove this publication from the library?")) {
			
			m_PPA[libRef]->setRef(0); // not sure how shoud put the selected one to zero
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	};

	void LibApp::checkOutPub() {
		search(1);
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
	Publication* LibApp::getPub(int libRef) {
		Publication* result = nullptr;
		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == libRef) result = m_PPA[i];
		}
		return result;
	}
	/*void LibApp::newPublication() {
		char type{};

		if (m_NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			cout << "Adding new publication to the library" << endl;

		}

	};*/
}
