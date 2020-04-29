#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <stdio.h>
#include <time.h>

class DropShadowBox : public Fl_Box
{
    int level;
    void draw() 
    {
	Fl_Box::draw_box();
	if (label())
	{
	    fl_font(labelfont(), labelsize());
	    int xx = x() + Fl::box_dx(box());
	    int yy = y() + Fl::box_dy(box());
	    for (int i=level; i>0; --i) 
	    {
		fl_color(fl_color_average(color(), labelcolor(), (i / (float)level)));
		fl_draw(label(), xx+i, yy+i, w(), h(), align());
	    }
	}
    }
public :
    DropShadowBox(int x, int y, int w, int h, const char*l=0)
	  : level(5), Fl_Box(x, y, w, h, l)
	  {
	  }
	  void levels(int val) { level = val; }
	  int levels() const { return level; }
};

void update_cb(void* userdata)
{
    DropShadowBox* box = (DropShadowBox*)userdata;
    time_t lt = time(NULL);
    box->label(ctime(&lt));
    Fl::repeat_timeout(5.0, update_cb, (void*)box);
}

int main()
{
    Fl_Double_Window* win = new Fl_Double_Window(400, 100, "Drop shadow clock");
    DropShadowBox* box = new DropShadowBox(10, 10, win->w()-20,
					   win->h()-20);
    box->labelsize(28);
    box->levels(8);
    Fl::add_timeout(5.0, update_cb, (void*)box);
    win->show();
    update_cb((void*)box);
    
    return Fl::run();
}
