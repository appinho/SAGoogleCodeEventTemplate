// KS20/A
// EASY
// Greedy
// Sorting

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

int sum(vector<int> & v, int B){

    sort(v.begin(), v.end());
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        B -= v[i];
        if(B >= 0) sum++;
        else break;
    }
    return sum;
}

int main(){

    int T, N, B;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> B;

        vector<int> C;
        int c;
        for(int i = 0; i < N; i++){
            cin >> c;
            C.push_back(c);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << sum(C, B) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
