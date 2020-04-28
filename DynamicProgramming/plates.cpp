// KS20/A
// MEDIUM
// 0-1 Knapsack Problem 

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
#include <algorithm>

using namespace std;

int dp[51][1501];
int N, K, P;

int plates(vector<vector<int>> & buffer){

    // for(auto pla: buffer){
    //     for(auto p: pla){
    //         cerr << p << " ";
    //     }
    //     cerr << endl;
    // }

    for(int i = 0; i <= P; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= P; j++){
            dp[i][j] = 0;
            for(int k = 0; k < min(K+1,j+1); k++){
                // cerr << i << " " << j << " " << k << " " << buffer[i-1][k]
                // << "+" << dp[i-1][j-k] << ">" << dp[i][j] << endl;
                dp[i][j] = max(dp[i][j], buffer[i-1][k] + dp[i-1][j-k]);
            }
            // for(int i = 0; i <= N; i++){
            //     for(int j = 0; j <= P; j++){
            //         cerr << dp[i][j] << " ";
            //     }
            //     cerr << endl;
            // }
        }
    }

    return dp[N][P];
}

int main(){

    // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }


    int T;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> K >> P;

        int p;
        vector<vector<int>> buffer(N,vector<int>(K+1,0));
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int k = 0; k < K; k++){
                cin >> p;
                sum += p;
                buffer[i][k+1] = sum;
            }    
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << plates(buffer) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
