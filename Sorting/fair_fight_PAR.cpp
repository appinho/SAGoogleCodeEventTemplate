#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int number_of_fair_fights_bf(const vector<int> & C, const vector<int> & D, const int K, const int N){

    int count = 0;
    for(int l = 0; l < N; l++){
        for(int r = l; r < N; r++){
            int maxc = 0;
            int maxd = 0;
            for(int n = l; n <= r; n++){
                if(C[n] > maxc){
                    maxc = C[n];
                }
                if(D[n] > maxd){
                    maxd = D[n];
                }
            }
            if(abs(maxc-maxd) <= K){
                count++;
            }
        }   
    }

    return count;
}

int number_of_fair_fights(const vector<int> & C, const vector<int> & D, const int K, const int N){

    vector<int> pc(N,1);
    vector<int> pd(N,1);

    int maxc = C[0];
    int maxd = D[0];
    int count = 0;
    if(maxc == maxd){
        count = 1;
    }

    for(int n = 1; n < N; n++){
    
        if(C[n] > maxc){
            maxc = C[n];
            pc[n] = 1;
        }
        else if(C[n] == maxc){
            pc[n] = pc[n-1] + 1;
        }
        else{
            pc[n] = pc[n-1];
        }
        if(D[n] > maxd){
            maxd = D[n];
            pd[n] = 1;
        }
        else if(D[n] == maxd){
            pd[n] = pd[n-1] + 1;
        }
        else{
            pd[n] = pd[n-1];
        }

        if(abs(maxc-maxd) <= K){
            count += min(pc[n],pd[n]);
            cout << n << " " << pc[n] << " " << pd[n] << " " << count << endl;
        }
    }

    return count;
}

int main() {

    int T, N, K;
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> N >> K;

        vector<int> C(N);
        vector<int> D(N);

        for(int n = 0; n < N; n++){
            cin >> C[n];
        }
        for(int n = 0; n < N; n++){
            cin >> D[n];
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << number_of_fair_fights_bf(C, D, K, N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}