// KS19/F
// HARD
// Permutation/Subset

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int new_learnings(const vector< set<int> > & network_skills, const int N){

    int new_learnings = 0;
    for(int i = 0; i < N; i++){
        //cerr << i << endl;
        for(int j = 0; j < N; j++){
            if(i != j){
                for(auto f: network_skills[i]) {
                    if(network_skills[j].find(f) == network_skills[j].end()){
                        new_learnings++;
                        //cerr << i << "->" << j << " S " << f << endl;
                        break;
                    }
                } 
            }
        }
    }
    return new_learnings;
}

int main(){

    
    int T, N, S, C, c;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N >> S;

        vector< set<int> > network_skills;
        for(int n = 0; n < N; n++){
            cin >> C;
            set<int> skills;
            for(int i = 0; i < C; i++){
                cin >> c;
                skills.insert(c);
            }
            network_skills.push_back(skills);
        }
        

        time_t startt = clock();
        cout << "Case #" << t << ": " << new_learnings(network_skills, N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}