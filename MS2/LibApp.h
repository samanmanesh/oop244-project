#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
	class LibApp {

		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		bool confirm(const char* message);


	public:

		LibApp();



	};

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
		returnedValue == 1 && (result = true);
		return result;
	};


}
#endif // !SDDS_LIBAPP_H



