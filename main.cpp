#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int sum(const vector<int> & v){

    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum;
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
        cout << "Case #" << t << ": " << sum(C) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}