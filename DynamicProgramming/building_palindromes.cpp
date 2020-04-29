// KS19/B
// MEDIUM
// Prefix sum/ASCII/Palindrome

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

/*
2
7 5
ABAACCA
3 6
4 4
2 5
6 7
3 7
3 5
ABC
1 3
1 3
1 3
1 3
1 3

N=3 Q=5

Brute Force: O(Q*N) = 10.000.000.000
Pre calculate O(N*N/2) = 2.500.000.000

1 2 3
- 1 2
- - 1

1 2 1 2 3 2 1
- 1 2 1 2 3 2
- - 1 0 1 0 1
- - - 1 2 1 0
- - - - 1 0 1
- - - - - 1 2
- - - - - - 1

O((N+Q) * C) = 20000 * 26 = 260.000

0 1 1 2 3 3 3 4
0 0 1 1 1 1 1 1
0 0 0 0 0 1 2 2
*/

static int ABC = 26;

void preCalculateTable(const vector<char> & S, vector< vector<int> > & differences){

    int N = differences[0].size();
    for(int i = 1; i < N; i++){
        if(i != 1){
            for(int j = 0; j < ABC; j++){
                differences[j][i] = differences[j][i - 1];
            }
        }
        int index = int(S[i-1] - 'A');
        differences[index][i]++;        

    }
    /*
    for(int j = 0; j < ABC; j++){
        for(int i = 0; i < N; i++){
            cerr << differences[j][i] << " ";
        }
        cerr << endl;
    }
    */
}

int numbersOfPossiblePalindroms(const vector<char> & S, const int l, const int r, const vector< vector<int> > & differences){

    vector<int> counter(ABC);
    //cerr << r << " " << l << endl;
    for(int j = 0; j < ABC; j++){
        counter[j] = differences[j][r] - differences[j][l-1];
    }
    /*
    for(int i = 0; i < ABC; i++){
        cerr << counter[i] << " ";
    }
    cerr << endl;
    */
    bool one_time = false;

    for(auto & x: counter){
        if(x % 2 == 1){
            if(one_time){
                return 0;
            }
            one_time = true;
        }
    }
    return 1;
}
int main() {

    // Defclare variables
    int T, N, Q;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of students and size of team
        cin >> N >> Q;

        // Read scores of students
        vector<char> S = vector<char>(N);
        char si;
        for(int i = 0; i < N; ++i){
            cin >> si;
            S[i] = si;
        }
        int l, r;
        int sum = 0;
        time_t startt = clock();
        vector< vector<int> > differences(ABC, vector<int>(N+1, 0));
        preCalculateTable(S, differences);
        for(int i = 0; i < Q; i++){
            cin >> l >> r;
            sum += numbersOfPossiblePalindroms(S, l, r, differences);

        }
            
        cout << "Case #" << t << ": " << sum << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}