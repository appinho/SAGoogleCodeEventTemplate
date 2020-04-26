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

using namespace std;

void evenSubset(const vector<int> & v){

    vector<int> sol;
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 == 0){
            cout << 1 << endl;
            cout << i + 1 << endl;
            return;
        }
        else{
            if(sol.size() < 2){
                sol.append(v[i]);
            }
        }
    }
    if(sol.size() == 2){
        cout << 2 << endl;
        cout << sol[0] << " " << sol[1] << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){

    // // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }
    
    int T, N;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;

        vector<int> C;
        int c;
        for(int i = 0; i < N; i++){
            cin >> c;
            C.push_back(c);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": ";
        evenSubset(C);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
