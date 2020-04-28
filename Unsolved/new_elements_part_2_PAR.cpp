// CJ19/2
// HARD
// Sorting
// 

#include <bits/stdc++.h>

using namespace std;

bool Compare(const pair<int,int> & p1, const pair<int,int> & p2){
    if(p1.first + p1.second < p2.first + p2.second){
        return true;
    }
    else if(p1.first + p1.second == p2.first + p2.second){
        return p1.first < p2.first;
    }
    else{
        return false;
    }
}
void new_elements_part_2(vector<pair<int,int>> & M, int N){

    // sort(M.begin(), M.end(), Compare);
    // for(auto m:M){
    //     cerr << m.first << " " << m.second << endl;
    // }
    int wc = 1;
    int wj = 1;
    bool found;
    while(wc <= 100 && wj <= 100){
        // cerr << wc << " " << wj << endl;
        int last_w = -1;
        found = true;
        for(int i = 0; i < N; i++){
            int w = M[i].first * wc + M[i].second * wj;
            // cerr << w << " " << last_w << endl;
            if(w == last_w){
                wc++;
                found = false;
                break;
            }
            else if(w < last_w){
                wj++;
                found = false;
                break;
            }
            last_w = w;
        }
        if(found){
            break;
        }
    }
    if(found){
        cout << wc << " " << wj << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
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
    
    int T, N, c, j;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;

        vector<pair<int,int>> M;
        for(int i = 0; i < N; i++){
            cin >> c >> j;
            M.push_back(make_pair(c,j));
        }

        time_t startt = clock();
        cout << "Case #" << t << ": ";
        new_elements_part_2(M,N);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
