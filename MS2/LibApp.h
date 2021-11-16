#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
	class LibApp {

		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

	public:

		LibApp();



	};

	LibApp::LibApp() :m_changed(false), m_mainMenu("Seneca Libray Application"
	) {
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

	};


}
#endif // !SDDS_LIBAPP_H



