#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <thread>
#include <gtkmm.h>
#include <wavecmp.hpp> 

// GTK widgets
Gtk::Window *w = nullptr;
Gtk::Button *submit = nullptr;
Gtk::SpinButton *amplitude = nullptr;
Gtk::SpinButton *period = nullptr;
Gtk::SpinButton *phase = nullptr;
Gtk::SpinButton *mean = nullptr;
Gtk::SpinButton *resolution = nullptr;
Gtk::SpinButton *interval_start = nullptr;
Gtk::SpinButton *interval_end = nullptr;
Gtk::SpinButton *comparison_value;
Gtk::ComboBox *comparator = nullptr;
Gtk::Label *answer = nullptr;
Gtk::Label *loading_text = nullptr;
Gtk::Spinner *loading = nullptr;

// global variables
std::string calc_answer;

// helper methods and event handlers
static void calculate_answer() {
    double a,b,c,d,res,int_start,int_end,val;
    double ans;
    //TreeModel::Iterator it;
    a = amplitude->get_value();
    b = period->get_value();
    c = phase->get_value();
    d = mean->get_value();
    res = resolution->get_value();
    int_start = interval_start->get_value();
    int_end = interval_end->get_value();
    val = comparison_value->get_value();
    //it = comparator.get_active();
    wavecmp::func function(a,b,c,d,res);
    function.set_resolution(res);
    ans = function.compare_wave(int_start, int_end, true, val); // not going to worry about the comparator bit right now I want to see if this builds first
    std::stringstream ans2;
    ans2 << "Answer: " << ans;
    calc_answer = ans2.str();
}

static void run_calculation() {
    std::thread calc_thread(calculate_answer); // this should be thread safe because the main thread and the worker thread are not accessing the same variables at the same time
    loading->start();
    loading_text->show();
    submit->set_sensitive(false);
    calc_thread.join();
    answer->set_text(calc_answer);
    loading->stop();
    loading_text->hide();
    submit->set_sensitive(true);

}


int main (int argc, char **argv) {

    auto application = Gtk::Application::create(argc, argv, "io.github.nsdrozario.wavecmp");
    auto builder = Gtk::Builder::create_from_file("gui/wavecmp2.glade");

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
   // builder->get_widget("comparator", comparator);
    builder->get_widget("comparison_value", comparison_value);
    builder->get_widget("answer_string", answer);
    builder->get_widget("loading_text", loading_text);
    builder->get_widget("loading_spinner", loading);

   submit->signal_clicked().connect(sigc::ptr_fun(&run_calculation));
    application->run(*w);
    
    delete w;

    return 0;

}