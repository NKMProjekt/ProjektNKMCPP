#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class PlanszaGryTetris : public Gtk::DrawingArea
{
	public:
	  PlanszaGryTetris();
	  virtual ~PlanszaGryTetris();

	protected:
		
	  //Override default signal handler:
	  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

	  Glib::RefPtr<Gdk::Pixbuf> m_image;
};
