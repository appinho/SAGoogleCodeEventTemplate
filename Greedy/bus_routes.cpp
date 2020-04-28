// KS20/B
// EASY
// Long long/Reverse

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

long long bus_routes(const vector<long long> & v, const long long D){

    long long start = D;
    for(long long i = v.size() - 1; i >=0; i--){
        long long div = start / v[i];
        start = div * v[i];
        // cerr << start << " " << v[i] << " " << div << " " << start << endl;
    }
    return start;
}

int main(){
    
    int T, N;
    long long D;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> D;

        vector<long long> C;
        long long c;
        for(int i = 0; i < N; i++){
            cin >> c;
            C.push_back(c);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << bus_routes(C, D) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
