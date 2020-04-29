#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>

int main()
{
	Fl_Window* win(new Fl_Window(640, 480));
	Fl_Text_Buffer* buff = new Fl_Text_Buffer();
	Fl_Text_Display* disp = new Fl_Text_Display(20, 20, win->w()-40, win->h()-40);
	disp->buffer(buff);
	win->resizable(*disp);
	win->show();
	buff->text("line 0\nline 1\n line 2\n"
		"line 3\nline 4\n line 5\n"
		"line 6\nline 7\n line 8\n"
		"line 9\nline 10\n line 11\n"
		"line 12\nline 13\n line 14\n");

	return Fl::run();
}