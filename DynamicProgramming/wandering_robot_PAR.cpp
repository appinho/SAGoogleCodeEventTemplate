// KS20/B
// MEDIUM
// Grid traversal/Probability

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

double wanderingRobot(vector<vector<bool>> G, const int W, const int H){

    // for(int h = 0; h < H; h++){
    //     for(int w = 0; w < W; w++){
    //         cerr << G[h][w] << " ";
    //     }
    //     cerr << endl;
    // }
    // cerr << endl;
    vector<vector<double>> P(H, vector<double>(W, 0));
    P[H-1][W-1] = G[H-1][W-1];
    bool pos = true;
    for(int h = H - 1; h >= 0; h--){
        pos &= G[h][W-1];
        if(pos)
            P[h][W-1] = 1;
        else
            P[h][W-1] = 0;
    }
    pos = true;
    for(int w = W - 1; w >= 0; w--){
        pos &= G[H-1][w];
        if(pos)
            P[H-1][w] = 1;
        else
            P[H-1][w] = 0;
    }
    for(int h = H - 2; h >= 0; h--){
        for(int w = W - 2; w >= 0; w--){
            if(!G[h][w]){
                P[h][w] = 0;
            }
            // else if(h == H-1 && w != W-1){
            //     P[h][w] = P[h][w-1];
            // }
            // else if(w == W-1  && h != H-1){
            //     P[h][w] = P[h-1][w];   
            // }
            // else if(h == H-1 && w == W-1){
            //     P[h][w] = P[h-1][w] + P[h][w-1];
            // }
            else{
                // if(P[h-1][w] == 0){
                //     P[h][w] = P[h][w-1];
                // }
                // else if(P[h][w-1] == 0){
                //     P[h][w] = P[h-1][w];
                // }
                // else{
                    P[h][w] = 0.5 * P[h+1][w] + 0.5 * P[h][w+1];
                // }
            }
        }
    }
    // for(int h = 0; h < H; h++){
    //     for(int w = 0; w < W; w++){
    //         cerr << P[h][w] << " ";
    //     }
    //     cerr << endl;
    // }
    return P[0][0];
}

int main(){

    int T, W, H, L, U, R, D;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> W >> H >> L >> U >> R >> D;

        vector<vector<bool>> G(H, vector<bool>(W, true));
        for(int w = L - 1; w < R; w++){
            for(int h = U - 1; h < D; h++){
                G[h][w] = false;
            }
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << wanderingRobot(G, W, H) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
