// KS18/A
// EASY
// Expected value/Probability/Precision

// g++ main.cpp -o app -std=c++14
#include <bits/stdc++.h>

using namespace std;

double lucky_dip(const vector<double> & V, const int K, int N){

    double average = 0;
    double last_average = 0;
    for(int k = 0; k <= K; k++){
        average = 0;
        for(int i = 0; i < N; i++){
            average += max(V[i], last_average) / N;
        }
        cerr << k << " " << average << endl;
        last_average = average;
    }
    // over_average /= N;
    return average;
}

int main(){

    // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }
    
    int T, N, K;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> K;

        vector<double> V;
        double v;
        for(int i = 0; i < N; i++){
            cin >> v;
            V.push_back(v);
        }

        time_t startt = clock();
        cout.precision(17);
        cout << "Case #" << t << ": " << lucky_dip(V, K, N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
