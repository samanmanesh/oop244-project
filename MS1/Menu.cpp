#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"Menu.h"
using namespace std;
using namespace sdds;

namespace sdds {

	MenuItem::MenuItem() {
		m_contentOfMenu = nullptr;
	};


	MenuItem::MenuItem(const char* content) {

		/*if (content && content[0])
		{
			m_contentOfMenu = new char[strlen(content) + 1];
			strcpy(m_contentOfMenu, content);
		}
		else
		{
			setEmpty();
		}*/
		setContent(content);
	}

	void MenuItem::setContent(const char* content) {

		if (content && content[0])
		{
			m_contentOfMenu = new char[strlen(content) + 1];
			strcpy(m_contentOfMenu, content);
		}
		else
		{
			setEmpty();
		}

	}

	void MenuItem::setEmpty() {
		m_contentOfMenu = nullptr;
	}

	MenuItem::~MenuItem() {

		delete[]m_contentOfMenu;
	};

	MenuItem::operator bool() const {
		return  (m_contentOfMenu && m_contentOfMenu[0]);
	};

	MenuItem::operator const char* () const {

		return m_contentOfMenu;
	};

	ostream& MenuItem::display(ostream& ostr) {

		if (*this)
		{
			ostr << m_contentOfMenu;
		}
		return ostr;
	};


	Menu::Menu() {
		m_noMenuPointers = 0;
	};

	Menu::Menu(const char* title):m_menuItemTitle(title) {

		//m_menuItemTitle.setContent(title);
	};


	Menu::~Menu() {

		for (int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			//check  Am not sure
			delete[] m_arrOfMenuPointers[i];
		}

	};

	void Menu::displayTitleMenu() {

		if (m_menuItemTitle)
		{
			m_menuItemTitle.display();
		}

	};


	ostream& Menu::displayMenu(ostream& ostr) {

		if (m_menuItemTitle)
		{
			m_menuItemTitle.display();
			ostr << ":" << endl;
		}
		for (int i = 0; i < m_noMenuPointers; i++)
		{
			ostr.width(2);
			ostr.setf(ios::right);
			ostr << i + 1 << "- ";
			ostr.unsetf(ios::right);
			ostr << m_arrOfMenuPointers[i];
		}
		ostr << " 0- Exit" << endl;
		ostr << "> ";

		return ostr;
	}

	// the fuction shoud move to Util when it works properly 
	int Menu::getInt(int minRange, int maxRange, const char* errorMessage) {
		int selectedItem = 0;
		bool trueInt = false;
		while (!trueInt)
		{
			cin >> selectedItem;
			if (!cin.fail())
			{
				if (selectedItem > minRange && selectedItem < maxRange)
				{
					trueInt = true;
				}
				else
				{
					cout << errorMessage;
				}
			}
			else
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		return selectedItem;
	};

	int Menu::run() {
		
		unsigned int selectedItem;
		
		displayMenu();
		
		selectedItem = getInt(0, MAX_MENU_ITEMS, "Invalid Selection, try again: ");

		return selectedItem;
	}
	/*
	XXXXXXOOOOOOOOOOOO
	01234567890123456
	
	
	*/
	int Menu::operator~() {
	
		int selectedItem;

		displayMenu();

		selectedItem = getInt(0, MAX_MENU_ITEMS, "Invalid Selection, try again: ");

		return selectedItem;
	};

	Menu& Menu::operator<<(const char* menuitemConent) {
	
		if (m_noMenuPointers < MAX_MENU_ITEMS)
		{
			MenuItem* newMenuItem =  new MenuItem(menuitemConent);
		
			m_arrOfMenuPointers[m_noMenuPointers] = newMenuItem ;

			m_noMenuPointers++;
		}
		
		return *this;
	};

	Menu::operator int() {
	
		return m_noMenuPointers;
	};

	Menu::operator unsigned int() {

		return m_noMenuPointers;
	};

	Menu::operator bool() {
	
		return(m_noMenuPointers);
	}

	// to be checked
	ostream& Menu::operator<<(ostream& ostr) {
		 m_menuItemTitle.display();
		return ostr;
	};
	
	const char* Menu:: operator[](int index) const{
		
		if (index > m_noMenuPointers)
		{
			return;
		}

		return(m_arrOfMenuPointers[index]->m_contentOfMenu);
	
	}

}