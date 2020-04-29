// KS19/F
// HARD
// Complete search/Dynamic Programming

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

int max_beauty(const vector<int> & B, const vector< vector<int> > & C, const int N){

    // for(int i = 0; i < B.size(); i++){
    //     cerr << B[i] << " ";
    // }
    // cerr << endl;

    // for(int i = 0; i < C.size(); i++){
    //     cerr << i << " -> ";
    //     for(int j = 0; j < C[i].size(); j++){
    //         cerr << C[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    int max_beauty = 0;
    for(int comb = 0; comb < pow(2,N); comb++){
        set<int> villages;
        for(int i = 0; i < N; i++){
            if(comb & (1 << i)){
                villages.insert(i);
                for(auto neighbor: C[i]){
                    villages.insert(neighbor);
                }
            }
        }
        int beauty = 0;
        for(auto village: villages){
            beauty += B[village];
        }
        if(beauty > max_beauty){
            max_beauty = beauty;
            //cerr << comb << " " << max_beauty << endl;
        }
    }
    return max_beauty;
}

int main(){

    int T, N;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;

        vector<int> B;
        int b;
        for(int i = 0; i < N; i++){
            cin >> b;
            B.push_back(b);
        }

        vector< vector<int> > C(N);
        int s, e;
        for(int i = 0; i < N - 1; i++){
            cin >> s >> e;
            C[s-1].push_back(e-1);
            C[e-1].push_back(s-1);
        }
        time_t startt = clock();
        cout << "Case #" << t << ": " << max_beauty(B, C, N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}