/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
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

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LibApp.h"
#include"Utils.h"
#include <fstream>
using namespace std;
using namespace sdds;

namespace sdds {


	LibApp::LibApp(const char* fileName)
		:m_changed(false),
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_pubType("Choose the type of publication:") {

		if (fileName)
		{
			Utils::strCpy(m_fileName, fileName);
		}

		m_mainMenu << "Add New Publication"
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";

		m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu";

		m_pubType << "Book"
			<< "Publication";

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
		ifstream infile(m_fileName);
		char type{};
		int i;
		for (i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {
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
				if (*m_PPA[m_NOLP])
				{
					m_NOLP++;
				}
				else
					delete m_PPA[m_NOLP];
			}
			//infile.ignore(1000, '\n');
		}
		if (m_NOLP)
			m_LLRN = m_PPA[m_NOLP - 1]->getRef();
	};

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream onfile(m_fileName);
		int i;
		for (i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() != 0)
			{
				onfile << *m_PPA[i] << endl;;

			}
		}
		onfile.close();
	};

	int LibApp::search(int typeOfSearch) { // recive if all as(1), on loan as (2), not on loan as (3)

		PublicationSelector PBS("Select one of the following found matches:", 15);
		int selectedPubType = 0;
		char title[256]{};
		int libRef{};
		bool aborted = true;



		do
		{
			selectedPubType = m_pubType.run();
			if (selectedPubType == 0)
				break;
			cin.ignore(1000, '\n');

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
					aborted = false;
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
					aborted = false;
				}


			}
			else if (typeOfSearch == 2) {

				if (selectedPubType == 1)
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						const char taypeOfPPA = m_PPA[i]->type();
						int loanStatus = m_PPA[i]->onLoan();

						if (loanStatus && taypeOfPPA == 'B' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title)) {

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

						if (loanStatus && taypeOfPPA == 'P' && m_PPA[i]->getRef() && m_PPA[i]->operator==(title))
						{
							PBS << m_PPA[i];
						};
					}
					aborted = false;
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
					aborted = false;
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
					aborted = false;
				}
			}

			else if (selectedPubType == 0)
				aborted = false;

			if (selectedPubType != 0 && PBS) {
				PBS.sort();
				libRef = PBS.run();

				if (libRef > 0)
				{
					cout << *getPub(libRef) << endl;
					aborted = false;
				}
			}
			else
			{
				cout << "No matches found!" << endl;
			}

		} while (0);


		if (aborted)
			cout << "Aborted!" << endl;

		return libRef;
	};

	void LibApp::returnPub() {
		int libRef{};

		cout << "Return publication to the library" << endl;

		libRef = search(2); // search for on loan publication

		if (libRef && confirm("Return Publication?")) {

			Publication* pbs = getPub(libRef);

			int daysOnloan = Date() - pbs->checkoutDate();


			if (daysOnloan > SDDS_MAX_LOAN_DAYS) {

				int extraDays = daysOnloan - SDDS_MAX_LOAN_DAYS;
				double penalty = extraDays * 0.5;

				cout << "Please pay $";
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << penalty << " penalty for being " << extraDays << " days late!" << endl;
			}
			//m_PPA[libRef]->set(0);
			pbs->set(0);
			m_changed = true;
			cout << "Publication returned" << endl;
		}
	};

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {  //free the allocated memory
			
			delete m_PPA[i];
		}
	};

	void LibApp::newPublication() {
		if (m_NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
			
			return;
		}

		cout << "Adding new publication to the library" << endl;

		Publication* dynPublication{};
		int type = m_pubType.run();
		bool aborted = true;
		do
		{
			if (type == 0)
				break;

			if (type == 1)
				dynPublication = new Book;
			else if (type == 2)
				dynPublication = new Publication;
			cin.ignore(1000, '\n');
			cin >> *dynPublication;
			//dynPublication->read(cin);

			if (cin.fail())
			{
				cin.ignore(1000, '\n');
				cin.clear();
				break;
			}

			if (confirm("Add this publication to the library?")) {

				aborted = false;

				if (*dynPublication)
				{
					m_changed = true;
					m_LLRN++;
					m_PPA[m_NOLP] = dynPublication;
					m_NOLP++;
					dynPublication->setRef(m_LLRN);
					cout << "Publication added" << endl;
				}
				else
				{
					cout << "Failed to add publication!" << endl;
					delete dynPublication;
					//dynPublication = nullptr;
				}
				
			}
			else
				break;

		} while (0);

		if (aborted)
		{
			delete dynPublication;
			cout << "Aborted!" << endl;
		}
	};

	void LibApp::removePublication() {

		cout << "Removing publication from the library" << endl;


		int libRef = search(1); // search all publication
		

		if (libRef && confirm("Remove this publication from the library?")) {

			//m_PPA[libRef]->setRef(0); 
			getPub(libRef)->setRef(0);
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	};

	void LibApp::checkOutPub() {

		int membership{};
		int libRef{};
		cout << "Checkout publication from the library" << endl;
		libRef = search(3);// available publication only(not on loan)

		if (libRef && confirm("Check out publication?")) {

			cout << "Enter Membership number: ";
			membership = Utils::getInt(10000, 99999, "Invalid membership number, try again: ");

			//m_PPA[libRef]->set(membership);
			getPub(libRef)->set(membership);
			m_changed = true;

			cout << "Publication checked out" << endl;
		};
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

		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == libRef) return m_PPA[i];
		}
		return nullptr;
	}

}
