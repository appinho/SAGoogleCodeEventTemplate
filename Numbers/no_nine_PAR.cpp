// KS18/B
// HARD
// Digit traversal


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

bool check_number(int num){

    if(num % 9 == 0)
        return false;
    while(num >= 1){
        int digit = num % 10;
        if(digit == 9)
            return false;
        num /= 10;
    }
    return true;
}

int no_nine(const int F, const int L){

    int total = 0;

    if(L < 0)
        return 0;
    int start = F;
    if(F < 0)
        int start = 0;

    for(int i = start; i <= L; i++){
        if(check_number(i)){
            total++;
        }
    }
    return total;
}

int main() {
    
    // Declare variables
    int T, F, L;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> F >> L;
        
        time_t startt = clock();
        cout << "Case #" << t << ": " << no_nine(F, L) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}