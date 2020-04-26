// CJ18/1A
// MEDIUM
// Rounding/Hash Map/Voting

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
#include <algorithm>
using namespace std;

bool Compare(const pair<int,pair<int,int>> & p1, const pair<int,pair<int,int>> & p2){
    return p1.first < p2.first;
}
int roundingError(vector<int> count, int N, int L){

    vector<int> round_up;

    vector<int> ints(N + 1, 0);
    for(int i = 1; i <= N;i++){
        float f = (i * 100.0) / N;
        if(f - int(f) >= 0.5){
            // cout << f << endl;
            round_up.push_back(i);
            ints[i] = ceil(f);
        }
        else{
            ints[i] = int(f);
        }
    }
    // for(auto r: round_up){
    //     cerr << r << " ";
    // } cerr << endl;
    if(round_up.empty()){
        return 100;
    }
    int closest = 0;
    int left_votes = N;
    // for(auto c: count){
    //     cout << c << " ";
    // } cout << endl;
    for(int i = 1; i < count.size(); i++){
        left_votes -= i *count[i];
    }
    count[0] = left_votes;
    // cerr << "LEFT VOTES " << left_votes << endl;
    vector< pair<int,pair<int,int>> > ma;
    for(int i = 0; i <= N; i++){
        if(i != round_up[closest]){
            ma.push_back(make_pair(round_up[closest] - i, make_pair(i, count[i])));
        }
        else{
            closest++;
            if(closest == round_up.size()) break;
        }
    }
    sort(ma.begin(), ma.end(), Compare);
    int moves = 0;

    // for(auto m: ma){
    //     std::cout << m.first << " " << m.second.first << " " << m.second.second<< std::endl;
    // }

    vector<int> new_count = count;
    int index = 0;
    while(left_votes > 0 && index < ma.size()){
        int needed_move = ma[index].first;
        int needed_people = ma[index].second.second;
        if(needed_move <= left_votes && needed_people > 0){
            int in = ma[index].second.first;
            // cerr << "ADD at " << in + needed_move << " from " << ma[index].second.first <<
            //     " because " << needed_move << "<" << left_votes << " and " << needed_people <<
            //     ">0"<<endl;
            left_votes -= needed_move;
            new_count[in]--;
            new_count[in + needed_move]++;
            ma[index].second.second--;

        }
        else{
            index++;
        }
    }
    while(left_votes > 0){
        new_count[1]++;
        left_votes--;
    }
    // for(auto c: ints){
    //     cerr << c << " ";
    // } cerr << endl;
    // for(auto c: new_count){
    //     cerr << c << "  ";
    // } cerr << endl;

    int max = 0;
    for(int i = 1; i < new_count.size(); i++){
        max += new_count[i] * ints[i];
        // if (new_count[i])
        // cerr << i << " " << ints[i] << " " << max << endl;
    }

    return max;
}

int main(){

    int T, N, L;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> L;

        int c;
        vector<int> count(N+1, 0);
        for(int l=0;l<L;l++){
            cin >> c;
            count[c]++;
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << roundingError(count, N, L) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
