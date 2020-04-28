// KS18/A
// EASY
// Digit Traversal/Long long/Odd Even

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

long long make_it_even(const long long number){
    
    long long buffer = number;
    int digits = log10(buffer) + 1;
    int eight_counter = 0;

    // Check until end is reached
    while(digits > 0){
        digits--;
        long long divider = pow(10,digits);

        // Obtain current digit
        int digit = buffer / divider;
        buffer = buffer % divider;

        // If current digit is odd
        if(digit % 2 == 1){

            // If there are following digits
            if(digits > 0){
                long long m, p;
                m = buffer + 1 + pow(10, digits - 1) * 10 / 9;
                if(digit == 9){
                    long long divider2 = pow(10, digits + eight_counter + 1);
                    p = 2 * pow(10, digits + eight_counter + 1) - number % divider2;
                }
                else{
                    p = pow(10,digits) - buffer;
                }
                return min(p, m);
            }
            else{
                return 1;
            }
        }
        if(digit == 8){
            eight_counter++;
        }
        else{
            eight_counter = 0;
        }
    }
    return 0;
}

int main(){

    // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }

    int num_test_cases;
    cin >> num_test_cases;

    for(int i = 0; i < num_test_cases; i++){
        long long number;
        cin >> number;
        long long switches = make_it_even(number);
        cout << "Case #" << i+1 << ": " << switches << endl;
    }

    return 0;
}