#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <gtkmm.h>
#include <wavecmp.hpp> 

// GTK widgets
// These already can only be accessed by the main thread, so no mutex allowed
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
Gtk::ComboBoxText *comparator = nullptr;
Gtk::Label *answer = nullptr;
Gtk::Label *loading_text = nullptr;
Gtk::Spinner *loading = nullptr;

// global variables
std::string calc_answer;
std::mutex calc_answer_mutex;

double val_amplitude, val_period, val_phase, val_mean, val_resolution, val_lower_bound, val_upper_bound, val_to_compare = 0.0L;
bool check_if_greater = false;
std::mutex params_mutex;

std::thread calc_thread;

// helper methods and event handlers
static void calculate_answer() {
    
    params_mutex.lock();

    wavecmp::func function(val_amplitude, val_period, val_phase, val_mean);
    function.set_resolution(val_resolution);
    double ans = function.compare_wave(val_lower_bound, val_upper_bound, check_if_greater, val_to_compare); // not going to worry about the comparator bit right now I want to see if this builds first
    
    params_mutex.unlock();

    calc_answer_mutex.lock();

    std::stringstream ans2;
    ans2 << "Answer: " << ans;
    calc_answer = ans2.str();

    calc_answer_mutex.unlock();

}

void update_params() {

    params_mutex.lock();

    val_amplitude = amplitude->get_value();
    val_period = period->get_value();
    val_phase = phase->get_value();
    val_mean = mean->get_value();
    val_resolution = resolution->get_value();
    val_to_compare = comparison_value->get_value();
    val_lower_bound = interval_start->get_value();
    val_upper_bound = interval_end->get_value();
    check_if_greater = comparator->get_active_text() == "Above";

    params_mutex.unlock();

}

static void run_calculation() {

    update_params();
    std::cout << "updated parameters" << std::endl;
    loading->start();
    loading_text->show();
    submit->set_sensitive(false);
    calc_thread = std::thread(calculate_answer); // this should be thread safe because the main thread and the worker thread are not accessing the same variables at the same time
    
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
    builder->get_widget("comparator", comparator);
    builder->get_widget("comparison_value", comparison_value);
    builder->get_widget("answer_string", answer);
    builder->get_widget("loading_text", loading_text);
    builder->get_widget("loading_spinner", loading);

    loading->stop();
    loading_text->hide();

    submit->signal_clicked().connect(sigc::ptr_fun(&run_calculation));
    application->run(*w);
    
    // these are still C structs under the hood 
    delete w;
    delete submit;
    delete amplitude;
    delete period;
    delete phase;
    delete mean;
    delete resolution;
    delete interval_start;
    delete interval_end;
    delete comparator;
    delete comparison_value;
    delete answer; 
    delete loading_text;
    delete loading;

    return 0;

}