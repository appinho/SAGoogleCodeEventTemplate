// CJ19/1C
// MEDIUM
// Probability

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

int vote(int V, int P){
    int day;
    cin >> day;
    // cerr << "Vote day " << day << endl;
    // cerr << "Vote V " << V << " Player " << P << endl;
    cout << V << " " << P << endl;
    
    return day;
}

vector<int> look(int V){
    int day;
    cin >> day;
    // cerr << "Look on Day " << day << endl;
    // cerr << "Look into V " << V << endl;
    cout << V << " " << 0 << endl;
    
    int n;
    cin >> n;
    // cerr << n << endl;
    vector<int> tokens(n);
    for(int i = 0; i < n; i++){
        cin >> tokens[i];
    }
    
    return tokens;
}

int main() {
    
    // reads 250 into t
    int T;
    cin >> T;

    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // int D;
        // // reads 1 (day 1)
        // cin >> D;
        // std::cerr << "Start with day " << D << std::endl;
        for(int d = 1; d <= 60; d++){
            int day = vote(d % 10 + 1, d);
            // cerr << day << " " << d << endl;
            // assert(d == day);
        }
        vector<int> num_votes;
        int min_votes = 1000;
        int index = 0;
        // cerr << "LOOKI LOOKI" << endl;
        for(int v = 1; v <= 20; v++){
            vector<int> tokens = look(v);
            int votes = (int) tokens.size();
            // cerr << "Vase " << v << " " << votes;
            num_votes.push_back(votes);
            if(min_votes >= votes){
                min_votes = votes;
                index = v;
            }
            // for(auto token: tokens){
            //     cerr << token << " ";
            // }
            // cerr << endl;
        }
        int final_vote = index;
        // cerr << "FINAL VOTE " << final_vote << endl;
        
        for(int f = 1; f <= 19; f++){
            int min_votes = 1000;
            int index = -1;
            for(int v = 0; v < 20; v++){
                // cerr << num_votes[v] << "<" << min_votes << endl;
                if(num_votes[v] < min_votes && v + 1 != final_vote){
                    // cerr << "NEW MIN AT " << v << " " << num_votes[v]<< endl;
                    index = v + 1;
                    min_votes = num_votes[v];
                }
            }
            // cerr << "Add to " << index << endl;
            int day = vote(index, 1);
            num_votes[index - 1]++;
        }
        // for(int v = 1; v <= 20; v++){
        //     if(num_votes[v] < min_votes && v != final_vote){
        //         index = v;
        //     }
        // }
        
        int final_day = vote(final_vote, 100);
    }
    return 0;
}