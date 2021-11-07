#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {

	class MenuItem
	{
	private:
		
		char* m_contentOfMenu{};

		MenuItem(const char* content);
		
		~MenuItem();
		
		void setEmpty();
		
		operator bool() const;

		friend class Menu;
	};
}
#endif