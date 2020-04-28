// KS20/B
// EASY
// Counting peaks

// g++ main.cpp -o app -std=c++14
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

int bike_tour(const vector<int> & v){

    int sum = 0;
    for(int i = 1; i < v.size() - 1; i++){
        if(v[i-1] < v[i] && v[i] > v[i+1])
            sum++;
    }
    return sum;
}

int main(){

    int T, N;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;

        vector<int> C;
        int c;
        for(int i = 0; i < N; i++){
            cin >> c;
            C.push_back(c);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << bike_tour(C) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
