// KS19/E
// MEDIUM
// Divisor/Odd Even/Sieve of Eratosthenes

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// Function to print the divisors 
int street_checkers(const pair<int,int> & p, map<int, int> & interesting){

    int L = p.first;
    int R = p.second; 
    // Note that this loop runs till square root 
    int interesting_games = 0;
    for (int i = L; i <= R; i++){
        int alice = 0;
        int bob = 0;
        if(interesting.find(i) != interesting.end()){
            interesting_games += interesting[i];
        }
        else{
            for (int j = 1; j <= sqrt(i); j++){
                if (i%j == 0){
                    if (i/j == j){
                        if(j % 2){
                            bob++;
                        }
                        else{
                            alice++;
                        }
                    }
                    else{
                        if(j % 2){
                            bob++;
                        }
                        else{
                            alice++;
                        }
                        if(i/j % 2){
                            bob++;
                        }
                        else{
                            alice++;
                        }
                    }
                } 
            }
            //cerr << i << " " << alice << " " << bob << endl;
            if(abs(alice-bob) <= 2){
                interesting_games++;
                interesting[i] = 1;
            }
            else{
                interesting[i] = 0;
            }
        }
    }
    return interesting_games;
}

int main() {
    
    // Declare variables
    int T, L, R;
    int max_R = 0;

    // Read number of test cases
    cin >> T;
    vector< pair<int,int> > cases(T);
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> L >> R;
        cases[t-1].first = L;
        cases[t-1].second = R;
        if(R>max_R){
            max_R = R;
        }
    }
    cerr << max_R << endl;
    map<int, int> interesting;

    for(int t = 1; t <= T; ++t){
        time_t startt = clock();
        cout << "Case #" << t << ": " << street_checkers(cases[t-1], interesting) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}