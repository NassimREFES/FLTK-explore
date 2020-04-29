#include <iostream>
#include <cstring>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>

using namespace std;

class Menu
{
	Fl_Window* win;
	Fl_Menu_Bar* menu;

	static void menu_cb(Fl_Widget* w, void* data)
	{
		Menu* o = (Menu*)data;
		o->menu_cb2();
	}

	void menu_cb2()
	{
		char picked[80];
		menu->item_pathname(picked, sizeof(picked)-1);
		cout << "CALLBACK: You picked " << picked << '\n';
		if (strcmp(picked, "File/Quit") == 0) exit(0);
		if (strcmp(picked, "Help/Help") == 0) cout << "help goes here\n";
	}
public :
	Menu()
	{
		win = new Fl_Window(720, 486);
		menu = new Fl_Menu_Bar(0, 0, win->w(), 25);
		menu->add("File/Open", 0, menu_cb, (void*)this);
		menu->add("File/Quit", 0, menu_cb, (void*)this);
		menu->add("Help/Help", 0, menu_cb, (void*)this);
		win->end();
		win->show();
	}
};

int main()
{
	Menu m;
	return Fl::run();
}