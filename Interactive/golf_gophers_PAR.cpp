// CJ19/1A
// MIDDLE
// Interactive
// Probability/Chinese remainder/Prime

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

void ask(const vector<int> & guess, vector<int> & response){

    for(int i = 0; i < guess.size(); i++){
        cout << guess[i] << " ";
    }
    cout << endl;
    
    int r;
    for(int i = 0; i < response.size(); i++){
        cin >> r;
        //assert(r != -1);
        response[i] = r;
        cerr << r << " ";
    }
    cerr << endl;
}

int best_guess(const vector<int> & d){
    int guess = 0;
    for(int i = 0; i < 18; i++){
        guess += d[i];
    }
    return guess;
}

int main() {
    
    int T, N, M;
    cin >> T >> N >> M;
    cerr << T << " " << N << " " << M << endl;
        
    // Loop over test cases
    for(int t = 1; t <= T; ++t){
        std::cerr << "Test Case #" << t << std::endl;
        vector<int> blades(18, 18);
        vector<int> directions(18, 0);
        
        int guess = 1;
        int counter = 0;
        for(int n = 0; n < N; n++){
            ask(blades, directions);
            int new_guess = best_guess(directions);
            if(new_guess == guess){
                counter++;
                if(counter > 30){
                    break;
                }
            }
            else{
                counter = 0;
                guess = new_guess;
            }
        }
        
        cout << guess << endl;
        cerr << "GUESS " << guess << endl;
        int valid;
        cin >> valid;
        cerr << "valid " << valid << endl;
        //assert(valid != -1);
    }
    return 0;
}