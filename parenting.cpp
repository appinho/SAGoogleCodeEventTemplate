#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

string schedule(vector<vector<int> > & v, const int N){

    sort(v.begin(), v.end()); 
    string schedule(N, 'x');
    int jamie_min = 0;
    int cameron_min = 0;
    // for(int i = 0; i < N; i++){
    //     cerr << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    // }
    for(int i = 0; i < N; i++){
        if(jamie_min <= v[i][0]){
            jamie_min = v[i][1];
            schedule[v[i][2]] = 'J';
            continue;
        }
        if(cameron_min <= v[i][0]){
            cameron_min = v[i][1];
            schedule[v[i][2]] = 'C';
            continue;
        }
        return "IMPOSSIBLE";
    }
    return schedule;
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

        vector<vector<int> > S;
        int c1, c2;
        for(int i = 0; i < N; i++){
            cin >> c1 >> c2;
            vector<int> row;
            row.push_back(c1);
            row.push_back(c2);
            row.push_back(i);
            S.push_back(row);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << schedule(S, N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
