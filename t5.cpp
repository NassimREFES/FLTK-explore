#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>

int main()
{
	Fl_Text_Display::Style_Table_Entry stables[] = {
		// font color, font face, font size
		{ FL_RED, FL_COURIER, 18},
		{ FL_DARK_YELLOW, FL_COURIER, 18},
		{ FL_DARK_GREEN, FL_COURIER, 18},
		{ FL_BLUE, FL_COURIER, 18}
	};

	Fl_Window* win = new Fl_Window(640, 480);
	Fl_Text_Display* disp = new Fl_Text_Display(20, 20, 600, 440, "Display");
	Fl_Text_Buffer* tbuff = new Fl_Text_Buffer(); // text buffer
	Fl_Text_Buffer* sbuff = new Fl_Text_Buffer(); // style buffer
	disp->buffer(tbuff);
	int stable_size = sizeof(stables)/sizeof(stables[0]);
	disp->highlight_data(sbuff, stables, stable_size, 'A', 0, 0);
	tbuff->text("Red Line 1\nYel Line 2\nGrn Line 3\nBlu Line 4\n"
                 "Red Line 5\nYel Line 6\nGrn Line 7\nBlu Line 8\n");
	sbuff->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n"
                 "AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp);
	win->show();
	return Fl::run();
}