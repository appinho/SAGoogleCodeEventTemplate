// CJ18/1A
// HARD
// Binary Search/Range query

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
#include <limits>
#include <algorithm>

using namespace std;

long long bitparty(vector<vector<long long>> & cash, int B, int R){

    long long min_t = 0;
    long long max_t = numeric_limits<long long>::max();
    // cerr << max_t << endl;
    long long mid_t;
    while(min_t <= max_t){
        mid_t = (min_t + max_t) / 2;
        // cerr << min_t << " " << max_t << "->" << mid_t << endl;
        vector<long long> cash_bits;
        for(int c = 0; c < int(cash.size()); c++){
            if(cash[c][2] > mid_t) continue;
            long long max_checkout = (mid_t - cash[c][2]) / cash[c][1];
            long long sum_bits = max(0ll, min (cash[c][0], max_checkout));
            cash_bits.push_back(sum_bits);
            // cerr << cash[c][0] << " or " << max_checkout << endl;
        }
        sort(cash_bits.rbegin(), cash_bits.rend());
        bool works = false;
        long long max_robot = 0;
        for(int c = 0; c < R && c < int(cash_bits.size()); c++){
            max_robot += cash_bits[c];
            if(max_robot>=B){
                works=true;
            }
        }
        // cerr << mid_t << " " << max_robot << ">" << B << endl;
        if(works){
            max_t = mid_t - 1;
        }
        else{
            min_t = mid_t + 1;
        }
    }
    // cerr << "FINAL " << min_t << " " << mid_t << " " << max_t << endl;

    return min_t;
}

int main(){

    int T, R, B, C;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> R >> B >> C;

        vector<vector<long long>> Cash(C,vector<long long>(3,0));
        long long c;
        for(int i = 0; i < C; i++){
            for(int j = 0; j < 3; j++){
                cin >> c;
                Cash[i][j] = c;
            }
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << bitparty(Cash, B, R) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
