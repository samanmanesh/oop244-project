#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LibApp.h"
using namespace std;
using namespace sdds;

namespace sdds {
   

	LibApp::LibApp() :m_changed(false), m_mainMenu("Seneca Libray Application"
	) {
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

	};

	bool LibApp::confirm(const char* message) {
		bool result = false;
		int returnedValue = 0;

		Menu confirmMenu(message);
		confirmMenu << "yes";

		returnedValue = confirmMenu.run();

		result = (returnedValue == 1) ? true : false;

		return result;
	};

	void LibApp::load() {
		cout << "Loading Data" << endl;
	};

	void LibApp::save() {
		cout << "Saving Data"  <<endl;
	};  

	void LibApp::search() {
		cout << "Searching for publication" << endl;
	};  

	void LibApp:: returnPub() {
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
		if (confirm("Check out publication ? ")) {

			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	};


}
