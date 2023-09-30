#include <iostream>
#include <vector>
#include <cmath>

// we could use std in the namespace to turn commands like std:cout into just cout
// using namespace std;

/**
* fibonacci program
* that does some additional stuff so we can explore c++ 
*/

// define your functions output type
int main() {
    // that's nice; a bunch of ints initialized on one line, but it may not be best practice?
    int n = 15, nextTerm = 0;
    // we make t1 a double so we can get a ratio that is a double; int/int gives truncated int division
    // we make t2 also a double so we can swap variables in one line of code using swap()
    double ratio = 1.5, inverse_ratio = 0.66, t1 = 0, t2 = 1; 
    const double golden_ratio = 1.618034; // approximated; it's a constant so we can't change it
    double ratio_of_ratios = 1;

    int test1 = 0;
    int y = test1++; // y=0 and then test1 is incremented to 1 afterwards
    // one way to get a new line is std::endl
    std::cout << y << std::endl;
    int z = ++test1; // test1 is incremented to 2 before z is assigned
    // another way to get a new line, like in python, is \n
    std::cout << z << "\n";

    // looks like javascript
    for (int i = 1; i <= n; ++i) {
        // print the first two terms and jump to the next item in the for loop
        // alternative to the if-elif-else pattern in Python which I like better
        if(i == 1) {
            // std is standard library; cout is printing character out
            std::cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            std::cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        // int/int gives truncated int
        ratio = t2 / t1;
        // sure, we could just do inverse_ratio = t1 / t2, but we wanted to try swap
        std::swap(t1, t2);
        inverse_ratio = t2 / t1;
        std::swap(t1, t2);
        ratio_of_ratios = golden_ratio / ratio;

        std::cout << "(" << ratio << ", " << inverse_ratio << ", " << ratio_of_ratios << ")";
        std::cout << nextTerm << ", ";
    }

    std::cout << std::endl << "Enter two integers: ";
    int input_value1;
    int input_value2;
    // compile and run you program from the terminal; you can't just use the Output panel in VSCode like you can with cout
    // clang++ main.cpp -o myprogram
    // ./myprogram
    std::cin >> input_value1 >> input_value2;
    std::cout << input_value1 * input_value2 * golden_ratio;

    // if the computer returns something other than 0, you have a problem
    return 0;
}