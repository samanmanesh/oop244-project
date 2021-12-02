/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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




#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	class Menu;
	const unsigned int  MAX_MENU_ITEMS = 20;


	class MenuItem
	{

		char* m_contentOfMenu{};

		MenuItem();

		MenuItem(const char* content);

		MenuItem(const MenuItem& MI) = delete;

		void operator= (const MenuItem& MI) = delete;

		~MenuItem();

		void setContent(const char* content);

		void setEmpty();

		operator bool() const;

		operator const char* () const;

		std::ostream& display(std::ostream& ostr = std::cout);

		friend class Menu;
	};

	class Menu {

		MenuItem m_menuItemTitle;

		MenuItem* m_arrOfMenuPointers[MAX_MENU_ITEMS]{ };

		unsigned int m_noMenuPointers{};

	public:

		Menu();

		Menu(const char* title);

		Menu(const Menu& M) = delete;

		void operator= (const Menu& M) = delete;

		~Menu();

		std::ostream& displayTitleMenu(std::ostream& ostr);

		std::ostream& displayMenu(std::ostream& ostr = std::cout);

		int run();

		int operator~();

		Menu& operator<<(const char* menuitemConent);

		operator int();
		operator unsigned int();

		operator bool();

		const char* operator[](unsigned int index) const;
	};
	std::ostream& operator<<(std::ostream& ostr, Menu& RO);
}
#endif