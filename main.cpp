#include <iostream>
#include "Fraction.h"

using namespace std;
int main() {
    Fraction ratio_of_turtles;
    Fraction ratio_of_eggs;
    int nestsMade, nestsLeft, eggsLaid, eggsHatched;

    // Some futzing around to demonstrate div/multip...
    cout << "The value of 0 * anything is: " << ratio_of_turtles * 5 << "\n";
    cout << "the value of 0 / anything is: " << ratio_of_turtles / 1 << "\n"; 

    // A cool idea to make a FDC app
    cout << "Welcome to Turtle Field Data Capture Survey\n";
    cout << "Please enter how many turtles were observed making nests.\n";
    cin >> nestsMade;
    cout << "Please enter how many nests survived\n";
    cin >> nestsLeft;

    // You have to set Numerator here first because
    // the simplification is done after the denominator is set.
    ratio_of_turtles.setNumer(nestsLeft);
    ratio_of_turtles.setDenom(nestsMade);

    cout << "How many eggs hatched from the nest?\n";
    cin >> eggsHatched;
    cout << "How many eggs were laid?\n";
    cin >> eggsLaid;
    cout << endl;
    // I set this one up more logically though normally you count the whole
    // before the fraction. Possibly wise to check for ratios greater than 1.
    ratio_of_eggs.setNumer(eggsHatched);
    ratio_of_eggs.setDenom(eggsLaid);
    cout << "The number of eggs hatched to eggs laid is: ";
    cout << ratio_of_eggs << endl;

    // Finally just playing around with the addition and subtraction operators. 
    cout << "The fraction of nests that survived plus eggs hatched is: "
         << ratio_of_turtles + ratio_of_eggs << endl;
    cout << "The fraction of eggs hatched minus nests that survived is: "
         << ratio_of_eggs - ratio_of_turtles << endl;
    cout << "The fraction of nests multiplied by eggs hatched is: " 
        << ratio_of_turtles * ratio_of_eggs << endl;
    cout << "The fraction of eggs divided by the number of nests is: "
        << ratio_of_eggs * ratio_of_turtles << endl;
    cout << "The decimal form of nests that survived to nests made is: "
        << ratio_of_turtles.displayFloat() << endl;
    cout << "The decimal form of eggs laid vs egss that survived is: "
        << ratio_of_eggs.displayFloat() << endl;
    return 0;
}
