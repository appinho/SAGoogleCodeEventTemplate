// KS19/H
// MEDIUM
// Permutation/Modulo

// g++ main.cpp -o app -std=c++14
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>    // std::next_permutation, std::sort

using namespace std;

string elevanagram(vector<int> & v){

    // for(auto e: v){
    //     cout << e << " ";
    // }
    vector<int> q;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i]; j++){
            q.push_back(i+1);
        }
    }

    do {
        int sum = 0;
        for(int i = 0; i < q.size(); i++){
            if(i % 2 == 0){
                sum += q[i];
            }
            else{
                sum -= q[i];
            }
        }
        if(sum % 11 == 0){
            return "YES";
        }    
    } while (next_permutation(q.begin(),q.end()));
    
    return "NO";
}

int main(){

    int T;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        vector<int> A;
        int a;
        for(int i = 0; i < 9; i++){
            cin >> a;
            A.push_back(a);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << elevanagram(A) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
