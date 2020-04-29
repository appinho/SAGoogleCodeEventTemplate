// KS19/C
// EASY
// Circular buffer

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void go(int N, int G, int M, vector< pair<int,int > > & g, int t){

    vector< vector< pair<int,int > > > last_frame(N);
    vector<bool> ended(N, false);
    for(int i = 0; i < g.size(); i++){
        int last_pos = ((g[i].first + g[i].second * M) % N + N) % N;
        if(last_pos <= 0){
            last_pos += N;
        }
        last_frame[last_pos - 1].push_back(pair<int,int >(i + 1, g[i].second));
        ended[last_pos - 1] = true;
    }
    
    for(int i = 0; i < N; i++){
        if(last_frame[i].empty()){
            int pos_1 = i;
            int pos_2 = i;
            bool found = false;
            for(int j = 0; j < M; j++){
                if(found){
                    break;
                }
                pos_1 = ((pos_1 - 1) % N + N) % N;
                for(int k = 0; k < last_frame[pos_1].size(); k++){
                    if(last_frame[pos_1][k].second == -1 && ended[pos_1]){
                        last_frame[i].push_back(last_frame[pos_1][k]);
                        found = true;
                    }
                }
                pos_2 = ((pos_2 + 1) % N + N) % N;
                for(int k = 0; k < last_frame[pos_2].size(); k++){
                    if(last_frame[pos_2][k].second == 1 && ended[pos_2]){
                        found = true;
                        last_frame[i].push_back(last_frame[pos_2][k]);
                    }
                }
            }
        }
    }

    vector<int> counter(G, 0);
    for(int i = 0; i < N; i++){
        if(!last_frame[i].empty()){
            for(int k = 0; k < last_frame[i].size(); k++){
                counter[ last_frame[i][k].first - 1 ]++;
            }
        }
    }

    cout << "Case #" << t << ": ";
    for(int g = 0; g < G; g++){
        cout << counter[g] << " ";
    }
    cout << endl;
}

int main() {

    // Defclare variables
    int T, N, G, M;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> N >> G >> M;

        vector< pair<int,int > > guests;

        int p;
        char d;
        for(int g = 0; g < G; g++){
            cin >> p >> d;
            if(d == 'C')
                guests.push_back(pair<int,int >(p, 1));
            else
                guests.push_back(pair<int,int >(p, -1));
        }

        time_t startt = clock();
        // Output minimum delivery time
        go(N, G, M, guests, t);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
