#include <iostream>
#include <fstream>
#include <string>
#include <wavecmp.hpp> 

double amplitude, period, phase, mean, resolution, comparison_value, interval_start, interval_end;
std::string comparison_type;
bool greater;

int main (int argc, char *argv[]) {

    std::string filepath ("");

    if (argc == 2) { // assuming we are seeing a valid file path
    // need to improve this later there are many things wrong with this input method

    filepath = std::string(argv[1]);

    } else {

        std::cout << "Enter file path: " << std::endl;
        std::cin >> filepath;

    }

    std::ifstream file_input (filepath);
    file_input >> amplitude >> period >> phase >> mean >> resolution >> comparison_value >> interval_start >> interval_end >> comparison_type;
    greater = comparison_type == "greater"; // another thing to fix
    wavecmp::func function(amplitude, period, phase, mean, resolution);

    std::cout << function.compare_wave(interval_start, interval_end, greater, comparison_value) << " units" << std::endl;

    return 0;

}