#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>
#include <wavecmp.hpp> 

int main (int argc, char *argv[]) {

   Gtk::Main m(argc, argv);
   Glib::RefPtr<Gtk::Builder> b = Gtk::Builder::create_from_file("gui/wavecmp.glade");
   Gtk::Window *w = 0;
   b->get_widget("window1", w);
   Gtk::Main::run(*w);

    return 0;

}