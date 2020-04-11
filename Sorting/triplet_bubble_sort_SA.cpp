#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> & S){

    for(int i = 0; i < S.size(); i++){
        cout << S[i] << " ";
    }
    cout << endl;
}

string correctSort(vector<int> & S, const int N){

    vector<int> S1, S2;
    for(int i = 0; i < N; i++){
        if(i % 2 == 1){
            S1.push_back(S[i]);
        }
        else{
            S2.push_back(S[i]);
        }
    }
    //printVector(S1);
    //printVector(S2);
    //printVector(S);
    sort(S.begin(), S.end());
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    //printVector(S1);
    //printVector(S2);
    //printVector(S);
    int ei = 0;
    int oi = 0;
    for(int i = 0; i < N; i++){
        if(i % 2 == 1){
            if(S[i] != S1[oi])
                return to_string(i);
            oi++;
        }
        else{
            if(S[i] != S2[ei])
                return to_string(i);
            ei++;
        }
        
    }
    return "OK";
}
int main() {

    // Defclare variables
    int T, N;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of students and size of team
        cin >> N;

        // Read scores of students
        vector<int> S = vector<int>(N);
        int si;
        for(int i = 0; i < N; ++i){
            cin >> si;
            S[i] = si;
        }

        // Output minimum hours of coaching
        time_t startt = clock();
        cout << "Case #" << t << ": " << correctSort(S, N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}