#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	class Menu;
	const int  MAX_MENU_ITEMS = 20;

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
		
		operator const char*() const;

		std::ostream& display(std::ostream& ostr = std::cout);

		friend class Menu;
	};

	class Menu {

		MenuItem m_menuItemTitle;

		MenuItem* m_arrOfMenuPointers{};

		int m_noMenuPointers;
		
	public:

		Menu();

		Menu(const char* title);

		Menu(const Menu& M) = delete;

		void operator= (const Menu& M) = delete;

		~Menu();

		//std::ostream&
		//void displayTitleMenu( std::ostream& ostr = std::cout);
		
		void displayTitleMenu();

		std::ostream& displayMenu(std::ostream& ostr = std::cout);

	};

}
#endif