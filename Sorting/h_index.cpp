// KS19/H
// MEDIUM
// Priority queue

// g++ main.cpp -o app -std=c++14
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

void hIndex(vector<int> & v){

    priority_queue<int,vector<int>,greater<int> > pq;
    int citations = 0;
    for(int i = 0; i < v.size(); i++){
        pq.push(v[i]);
        // cerr << i << " " << pq.top() << endl;
        if(pq.top() < citations + 1){
            pq.pop();
        }
        else{
            citations++;
        }
        cout << citations << " ";
    }
    
    cout << endl;
}

int main(){

    int T, N;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;

        vector<int> A;
        int a;
        for(int i = 0; i < N; i++){
            cin >> a;
            A.push_back(a);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": ";
        hIndex(A);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
