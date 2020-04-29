// KS19/A
// MEDIUM
// Prefix sum

#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int minHourOfCoaching(vector<int> & S, const int P, const int N){

    // Sort S
    sort(S.begin(), S.end(), greater<int>());

    // Sum for first subset
    long hours = 0;
    for(int i = 1; i < P; ++i){
        hours += S[0] - S[i];
    }
    long min = hours;
    
    // Loop over all other possible constellations
    for(int i = P; i < N; i++){
        
        hours -= (S[i-P] - S[i-P+1]) * (P-1);
        hours += S[i-P+1] - S[i];

        // Update minimum
        if(hours < min){
            min = hours;
        }
    }

    // Return minimum number of hours
    return min;
}
int main() {
    
    // Defclare variables
    int T, P, N;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of students and size of team
        cin >> N >> P;

        // Read scores of students
        vector<int> S = vector<int>(N);
        int si;
        for(int i = 0; i < N; ++i){
            cin >> si;
            S[i] = si;
        }

        // Output minimum hours of coaching
        cout << "Case #" << t << ": " << minHourOfCoaching(S, P, N) << endl;
    }
    return 0;
}