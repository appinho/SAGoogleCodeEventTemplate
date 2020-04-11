#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string evacuate(vector<int> & P, const int N, int sum){

    string res;
    if(N == 2){
        while(sum > 2){
            res += "AB ";
            sum -= 2;
        }
        res += "AB";
    }
    else{
        while(sum > 2){
            auto it = max_element(P.begin(), P.end());
            int index = distance(P.begin(), it);
            res += 'A' + index;
            res += " ";
            (*it)--;
            sum--;
        }
        for(int i = 0; i < N; i++){
            if(P[i] > 0)
                res += 'A' + i;
        }
    }
    return res;
}
int main() {

    // Defclare variables
    int T, N, P;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of students and size of team
        cin >> N;

        // Read scores of students
        vector<int> S = vector<int>(N);
        int si;
        int sum = 0;
        for(int i = 0; i < N; ++i){
            cin >> P;
            S[i] = P;
            sum += P;
        }

        // Output minimum hours of coaching
        time_t startt = clock();
        cout << "Case #" << t << ": " << evacuate(S, N, sum) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}