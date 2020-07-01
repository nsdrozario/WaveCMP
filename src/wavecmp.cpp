#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>
#include <wavecmp.hpp> 

Gtk::Window *w = 0;
Gtk::Button *submit = 0;
Gtk::SpinButton *amplitude = 0;
Gtk::SpinButton *period = 0;
Gtk::SpinButton *phase = 0;
Gtk::SpinButton *mean = 0;
Gtk::SpinButton *resolution = 0;
Gtk::SpinButton *interval_start = 0;
Gtk::SpinButton *interval_end = 0;
Gtk::SpinButton *comparison_value;
Gtk::ComboBox *comparator = 0;
Gtk::Label *answer = 0;

double calculate_answer() {

    double a,b,c,d,res,int_start,int_end,val;
    a = amplitude.get_value();
    b = period.get_value();
    c = phase.get_value();
    d = mean.get_value();
    res = resolution.get_value();
    int_start = interval_start.get_value();
    int_end = interval_end.get_value();
    val = comparison_value.get_value();

    


}

int main (int argc, char *argv[]) {

    auto application = Gtk::Application::create(argc, argv, "io.github.nsdrozario.wavecmp");
    auto builder = Gtk::Builder::create();

    try {

        builder->add_from_file("wavecmp2.glade");

    } catch (const Glib::FileError &gtkmm_error) {

        std::cerr << "gtkmm file error: " << gtkmm_error.what() << std::endl;

    } catch (const Glib::BuilderError &gtkmm_error) {

        std::cerr << "gtkmm builder error: " << gtkmm_error.what() << std::endl;
        
    }

    // if anyone knows a better way please educate me
    builder->get_widget("window1", w);
    builder->get_widget("StartButton", submit);
    builder->get_widget("amplitude", amplitude);
    builder->get_widget("period", period);
    builder->get_widget("phase", phase);
    builder->get_widget("mean", mean);
    builder->get_widget("resolution", resolution);
    builder->get_widget("interval_start", interval_start);
    builder->get_widget("interval_end", interval_end);
    builder->get_widget("comparator", comparator);
    builder->get_widget("comparison_value", comparison_value);
    builder->get_widget("answer_string", answer);
    
    submit.signal_clicked().connect(sigc::ptr_fun(&calculate_answer));
    application->run(w);
    
    delete w;

    return 0;

}