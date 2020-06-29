#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>
#include <wavecmp.hpp> 

int main (int argc, char *argv[]) {

    Glib::RefPtr<Gtk::Application> a = Gtk::Application::create(argc, argv, "io.github.nsdrozario");
    Glib::RefPtr<Gtk::Builder> glade_ui = Gtk::Builder::create_from_file("wavecmp.glade");
    Gtk::Window *w = nullptr;

    glade_ui->get_widget("window1", w);

    return app->run(w);

}