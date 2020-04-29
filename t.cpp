#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <cstdlib>

class Menu
{
public :
	Menu(int x, int y, int w, int h)
		: menu(new Fl_Menu_Bar(x, y, w, h))
	{
		menu->add("File/Quit", FL_CTRL+'q', quit_cb);
		menu->add("Edit/Change", FL_CTRL+'c', change_cb);
		menu->add("Edit/Submenu/Aaa");
		menu->add("Edit/Submenu/Bbb");
	}

private :
	Fl_Menu_Bar* menu;
	static void change_cb(Fl_Widget* w, void*)
	{
		Fl_Menu_Bar* menu = (Fl_Menu_Bar*)w;
		Fl_Menu_Item* p;


		if (p = (Fl_Menu_Item*)menu->find_item("Edit/Submenu"))
			p->label("New Submenu Name");

		if (p = (Fl_Menu_Item*)menu->find_item("Edit/New Submenu Name/Aaa"))
			p->label("New Aaa Name");
	}

	static void quit_cb(Fl_Widget*, void*)
	{
		exit(0);
	}
};

class Win : public Fl_Window
{
public :
	Win(int x, int y, int ww, int h, const char* title)
		: Fl_Window(x, y, ww, h, title),
		  m(0, 0, w(), 25)
	{
		show();
	}
private :
	Menu m;	
};

int main()
{
	Win w(0, 0, 400, 400, "change item menu");
	return Fl::run();
}