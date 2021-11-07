#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	class Menu;

	class MenuItem
	{
	private:
		
		char* m_contentOfMenu{};

		MenuItem(const char* content);
		MenuItem(const MenuItem& MI) = delete;
		void operator= (const MenuItem& MI) = delete;
		~MenuItem();
		
		void setEmpty();
		
		operator bool() const;
		
		operator const char*() const;

		friend class Menu;
	};


}
#endif