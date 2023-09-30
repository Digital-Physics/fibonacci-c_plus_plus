#include <iostream>
#include <vector>
#include <cmath> // we use pow()
#include <cstdlib> // re use rand()
#include <ctime> // used as seed for srand() and rand()

// we could use std in the namespace to turn commands like std:cout into just cout
// using namespace std;

/**
* fibonacci program
* that does some additional stuff so we can explore c++ 
*/

// define your functions output type
int main() {
    // that's nice; a bunch of ints initialized on one line, but it may not be best practice
    // alternative types for holding positive and negative integers (bytes): short (2), int (4), long (4), long long (8)
    // alternative ways to initialize a variable: int n {15} or int n{15} or int n{previous_var}
    int n = 15, nextTerm = 0;
    // we make t1 a double so we can get a ratio that is a double; int/int gives truncated int division
    // we make t2 also a double so we can swap variables in one line of code using swap()
    // alternative types for holding floating (bytes): float (4), double (8), long double (8)
    double ratio = 1.5, inverse_ratio = 0.66, t1 = 0, t2 = 1; 
    const double golden_ratio = 1.618034; // approximated; it's a constant so we can't change it
    double ratio_of_ratios = 1;

    // unnecessary code done for experimentation
    int test1 = 0;
    int y = test1++; // y=0 and then test1 is incremented to 1 afterwards
    // one way to get a new line is std::endl
    std::cout << y << std::endl;
    int z = ++test1; // test1 is incremented to 2 before z is assigned
    // another way to get a new line, like in python, is \n
    std::cout << z << "\n";

    // unnecessary code for type experimentation
    double price = 123.45;
    // auto is helpful when working with more complex types
    // the L forces the long; if not treated as in if you use auto
    // auto file_size = 90000L; // auto does type inference
    long file_size = 90000L;
    // the f forces the float if you use auto; if not it assumes the type is double
    float interest_rate = 3.75f;
    char letter = 'j';
    bool truth = false;
    int power = pow(2, 4);
    int binary = 0b11111111;
    int hexi = 0xff;
    long elapsed_secs = time(nullptr); // time(0) also works to give the number of seconds since 1/1/1970
    srand(elapsed_secs); // seed the random number
    short random1 = (rand() % 6) + 1; // randomn int is seeded with the seconds and mod with % to give us value 1-6
    short random2 = (rand() % 6) + 1; 
    std::cout << truth << ", " << power << "\n";
    std::cout << price << ", " << file_size << ", " << interest_rate << "\n";
    std::cout << letter << ", " << binary << ", " << hexi << "\n";
    std::cout << "dice roll: " << random1 << ", " << random2 << "\n";

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