// KS19/F
// HARD
// Combinatorics/Range query/Binary search

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

int flatten(const vector<int> & H, const int N, const int K){

    // for(auto h: H){
    //     cerr << h << " ";
    // }
    // cerr << endl;
    int min_removals = N;
    for(int comb = 1; comb < pow(2,N); comb++){
        int le = -1;
        int nh = 0;
        int hd = -1;
        for(int i = 0; i < N; i++){
            if(comb & (1 << i)){
                if(le != H[i]){
                    hd++;
                }
                le = H[i];
                nh++;
            }
        }
        //cerr << comb << " " << hd << "  " << nh << endl;

        if(hd <= K){
            // for(int i = 0; i < NH.size(); i++){
            //     cerr << NH[i] << " ";
            // }
            // cerr << " --> " << hd << endl;
            int removals = N - nh;
            if(removals < min_removals){
                min_removals = removals;
                // cerr << comb << " " << removals << endl;
            }
        }
    }
    return min_removals;
}

int main(){

    int T, N, K;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> K;

        vector<int> H;
        int h;
        for(int i = 0; i < N; i++){
            cin >> h;
            H.push_back(h);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << flatten(H, N, K) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}