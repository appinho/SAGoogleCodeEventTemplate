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

float getAverageNeighborLevel(vector< vector<int> > & F, int R, int C, int cr, int cc){

    int sum = 0;
    int neighbors = 0;

    for(int r = cr + 1; r < R; r++){
        if(F[r][cc]){
            neighbors++;
            sum += F[r][cc];
            break;
        }
    }
    for(int r = cr - 1; r >= 0; r--){
        if(F[r][cc]){
            neighbors++;
            sum += F[r][cc];
            break;
        }
    }
    for(int c = cc + 1; c < C; c++){
        if(F[cr][c]){
            neighbors++;
            sum += F[cr][c];
            break;
        }
    }
    for(int c = cc - 1; c >= 0; c--){
        if(F[cr][c]){
            neighbors++;
            sum += F[cr][c];
            break;
        }
    }
    if(neighbors) return float (sum) / neighbors;
    else return 0.0;
}

long long squareDance(vector< vector<int> > & F, int R, int C){

    long long intensity = 0;
    bool battledOut = true;
    while(battledOut){
        // cerr << "CURRENT FLOOR" << endl;
        // for(int r = 0; r < R; r++){
        //     for(int c = 0; c < C; c++){
        //         cerr << F[r][c] <<  " ";
        //     }
        //     cerr << endl;
        // }
        battledOut = false;
        vector< pair<int,int> > ko_places;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(F[r][c] == 0) continue;
                intensity += F[r][c];
                float neighbor_level = getAverageNeighborLevel(F,R,C,r,c);
                
                if(F[r][c] < neighbor_level){
                    // cerr << "KO at " << r <<  " " << c << " " << F[r][c] <<
                    //     "<" << neighbor_level << endl;
                    ko_places.push_back(make_pair(r,c));
                    battledOut = true;
                }
            }
        }
        for(int i = 0; i < ko_places.size(); i++){
            F[ko_places[i].first][ko_places[i].second] = 0;
        }

    }
    return intensity;
}

int main(){

    int T, R, C, l;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> R >> C;

        vector< vector<int> > F;
        for(int r = 0; r < R; r++){
            vector<int> L;
            for(int c = 0; c < C; c++){
                cin >> l;
                L.push_back(l);
            }
            F.push_back(L);
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << squareDance(F, R, C) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
