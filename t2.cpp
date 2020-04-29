#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>

int set_menu_item_state(Fl_Menu_Bar* menubar, const char* name, int state)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)menubar->find_item(name);
	if (!m) return -1;
	if (state) m->set();
	else m->clear();
	return 0;
}

int main()
{
	Fl_Double_Window* win = new Fl_Double_Window(720, 486);
	Fl_Menu_Bar* menubar = new Fl_Menu_Bar(0, 0, 720, 25);
	menubar->add("Option/One", 0, 0, 0, FL_MENU_TOGGLE);
	menubar->add("Option/Two", 0, 0, 0, FL_MENU_TOGGLE);
	menubar->add("Option/Three", 0, 0, 0, FL_MENU_TOGGLE);
	win->end();
	win->show();

	if (set_menu_item_state(menubar, "Option/One", 0) < 0) printf("FAILED[0]\n");
	if (set_menu_item_state(menubar, "Option/Two", 1) < 0) printf("FAILED[1]\n");
	if (set_menu_item_state(menubar, "Option/Three", 1) < 0) printf("FAILED[2]\n");
	
	return Fl::run();
}

