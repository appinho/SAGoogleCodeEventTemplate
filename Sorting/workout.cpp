// KS20/A
// MEDIUM
// Binary Search/Range query

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int workout_par(const vector<int> & S, int N, int K){

    vector<int> diff;
    for(int i = 0; i < N - 1; i++){
        int d = S[i+1] - S[i]; 
        diff.push_back(d);
    }
    sort(diff.begin(), diff.end());
    int split = (diff[N - 2] + 1) / 2;
    int m = max(split, diff[N-3]);
    return m;
}

int workout(const vector<int> & S, int N, int K){

    vector<int> diff;
    for(int i = 0; i < N - 1; i++){
        int d = S[i+1] - S[i]; 
        diff.push_back(d);
    }
    // Find d optimal in range 1 - max(diff)
    int l = 1;
    int r = *std::max_element(diff.begin(), diff.end()) ;
    // cerr << "Start " << l << " " << r << endl;
    // int dopt = 0;
    while(l <= r){
        int m = (l+r) / 2;
        int k = 0;
        // cerr << l << " " << r << "->" << m << endl;
        for(int i = 0; i < int(diff.size()); i++){
            k += (diff[i] - 1) / m;
        }
        if(k <= K){
            r = m - 1;
            // dopt = max(dopt,m);
        }
        else{
            l = m + 1;
        }
        // cerr << " " << k << "<" << K << endl;
    }
    return l;
}

int main(){

    // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }

    int T, N, K;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> K;

        vector<int> S;
        int c;
        for(int i = 0; i < N; i++){
            cin >> c;
            S.push_back(c);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << workout(S, N, K) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
