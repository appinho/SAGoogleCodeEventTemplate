// KS19/G
// MEDIUM
// Precomputation/Harmonic Number

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int T, N, M, Q;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> M >> Q;

        // vector<bool> pages(N);
        vector<int> f;
        for(int i = 0; i < N; i++){
            f.push_back(N / (i+1));
        }
        int h;

        for(int i = 0; i < M; i++){
            cin >> h;
            for (int j=1; j<=sqrt(h); j++) 
            { 
                if (h%j == 0) 
                {
                    if(h/j==j)
                        f[j-1]--;
                    else{
                        f[j-1]--;
                        f[h/j-1]--;
                    }


                    // for(int i = 0; i < N; i++){
                    //     cerr << f[i] << " ";
                    // }
                    // cerr << endl;
                }
            }
        }
        long long sum = 0;
        for(int i = 0; i < Q; i++){
            cin >> h;
            sum += f[h-1];
        }


        time_t startt = clock();
        cout << "Case #" << t << ": " << sum << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}