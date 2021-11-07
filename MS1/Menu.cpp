#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"Menu.h"
using namespace std;
using namespace sdds;

namespace sdds {

	MenuItem::MenuItem(const char* content) {

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

}