// KS19/B
// HARD
// Segment Tree/Prefix sum

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

/*
4
6 2
1 1 4 1 4 4
8 1
1 2 500 3 4 500 6 7
10 1
100 200 8 8 8 8 8 300 400 100
12 2
40 50 1 1 1 60 70 2 2 2 80 90

BF O(N^3 * log(N))
*/

struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second)
            return l.second < r.second;

        return l.first < r.first;
    }
};

int diverseSubarray(const vector<int> & A, const int N, const int S){

    int max = 0;
    for(int l = 0; l < N; l++){
        for(int r = l; r < N; r++){
            map<int,int> ht;
            for(int i = l; i <= r; i++){
                if( ht.find( A[i] ) != ht.end() ){
                    ht[ A[i] ]++;
                }
                else{
                    ht.insert(pair<int,int>(A[i], 1));
                }
            }
            set<pair<int,int>, comp> set(ht.begin(), ht.end());
            int sum = 0;
            for(auto & x: set){
                if(x.second <= S){
                    sum += x.second;
                }
            }
            if(sum > max){
                max = sum;
            }
        }
    }
    return max;
}

int diverseSubarrayOpt(const vector<int> & A, const int N, const int S){

    
    int max = 0;
    for(int l = 0; l < N; l++){
        map<int,int> ht;
        int count = 0;
        for(int i = l; i < N; i++){
            if( ht.find( A[i] ) != ht.end() ){
                ht[ A[i] ]++;
            }
            else{
                ht.insert(pair<int,int>(A[i], 1));
            }
            if(ht[A[i]] <= S){
                count++;
            }
            else if(ht[A[i]] == S+1){
                count -= S;
            }
            if(count > max){
                max = count;
            }
        }
    }

    return max;
}
int main() {

    // Defclare variables
    int T, S, N;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of students and size of team
        cin >> N >> S;

        // Read scores of students
        vector<int> A(N);
        for(int i = 0; i < N; ++i){
            cin >> A[i];
        }
        time_t startt = clock();
        cout << "Case #" << t << ": " << diverseSubarrayOpt(A, N, S) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}