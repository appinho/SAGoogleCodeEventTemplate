// CJ19/1C
// EASY
// Rock Papers Scissors

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

int L = 501;

string solve(const vector<string> & P, const int A){

    string sol;
    vector<bool> beaten(A, false);
    for(int l = 0; l < L; l++){
        set<char> cache;
        for(int i = 0; i < A; i++){
            if(!beaten[i]){
                cache.insert(P[i][l % P[i].size()]);
            }
        }
        //cerr << "Found: ";
        //for(auto c : cache) {
        //    cerr << c << " ";
        //}
        //cerr << endl;
        if(cache.size() == 3){
            return "IMPOSSIBLE";
        }
        else if(cache.size() == 2){
            if(cache.find('R') == cache.end()){
                sol += "S";
                for(int i = 0; i < A; i++){
                    if(!beaten[i] && P[i][l % P[i].size()] == 'P'){
                        beaten[i] = true;
                    }
                }
            }
            else if(cache.find('P') == cache.end()){
                sol += "R";
                for(int i = 0; i < A; i++){
                    if(!beaten[i] && P[i][l % P[i].size()] == 'S'){
                        beaten[i] = true;
                    }
                }
            }
            else{
                sol += "P";
                for(int i = 0; i < A; i++){
                    if(!beaten[i] && P[i][l % P[i].size()] == 'R'){
                        beaten[i] = true;
                    }
                }
            }
        }
        else{
            if(cache.find('R') != cache.end()){
                return sol + "P";
            }
            else if(cache.find('P') != cache.end()){
                return sol + "S";
            }
            else{
                return sol + "R";
            }
        }
    }
    cerr << "TRIED HARD: " << sol << endl;
	return "IMPOSSIBLE";
}

int main() {
    

    // Read in number of test cases
    int T;
    cin >> T;

    // Add other help variables
    int A;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

    	// Read input
    	cin >> A;

        vector<string> programs(A);
        for(int a = 0; a < A; a++){
            cin >> programs[a];
        }

    	// Time and perform
        time_t startt = clock();
        cout << "Case #" << t << ": " << solve(programs, A) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    
    return 0;
}