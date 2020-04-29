// KS19/G
// MEDIUM
// XOR/Greedy

#include <bits/stdc++.h>
using namespace std;

int goodUniverse(const int N, const int M, const vector<int> & nums){

    for(int k = 127; k >= 0; k--){
        int sum = 0;
        for(int n = 0; n < N; n++){
            int s = nums[n] ^ k;
            sum += s;
        }
        // cerr << k << " " << sum << endl;
        if(sum <= M){
            // cerr << "NEW MAX " << k << " "  << sum << endl;
            return k;
        }
    }

    return -1;
}

int main(){
    
    int T, N, M;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> M;
        vector<int> nums(N);
        for(int n = 0; n < N; n++){
            cin >> nums[n];
        }
        
        time_t startt = clock();
        cout << "Case #" << t << ": " << goodUniverse(N, M, nums) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}