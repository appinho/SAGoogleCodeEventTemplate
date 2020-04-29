// KS19/A
// MEDIUM
// BFS/Manhattan Distance

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue> 

using namespace std;

// BFS neighbor arrays
int newx[] = {-1, 0, 1, 0}; 
int newy[] = {0, -1, 0, 1}; 

// print grid
void printGrid(vector< vector<int> > dist, int m, int n){
    cout << endl;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int bfs(vector< vector<int> > & dist, const int R, const int C, queue< pair<int,int> > & q){

    while(!q.empty()){ 

        // Pop coordinate pair
        pair<int ,int> poped = q.front(); 
        q.pop(); 
  
        // coordinate of currently poped node 
        int x = poped.first; 
        int y = poped.second; 
  
        // now check for all adjancent of poped element 
        for(int i = 0; i < 4; i++){ 

            // coordinate of adjacent cells
            int adjx = x + newx[i]; 
            int adjy = y + newy[i]; 
  
            // if new coordinates are within boundry and 
            // we can minimize the distance of adjancent 
            // then update the distnace of adjacent in 
            // distance matrix and push this adjacent 
            // element in queue for further bfs 
            if (adjx >= 0 && adjx < R && adjy >= 0 && adjy < C && 
                dist[adjx][adjy] > dist[x][y] + 1){

                // update distance 
                dist[adjx][adjy] = dist[x][y] + 1; 
                q.push(make_pair(adjx,adjy));
            } 
        }
    }

    int worst_case = 0;
    for (int i=0; i<R; i++){ 
        for (int j=0; j<C; j++){
            if(dist[i][j] > worst_case)
                worst_case = dist[i][j];
        }
    }
    return worst_case;
}

bool second_round(const vector< vector<int> > & dist, const int R, const int C, const int K){
    int max_sub = 2 * (R+C);
    int max_sum = 2 * (R+C);
    int min_sub = -2 * (R+C);
    int min_sum = -2 * (R+C);
    bool ok = true;
    for (int i=0; i<R; i++){ 
        for (int j=0; j<C; j++){
            if(dist[i][j] > K){
                max_sum = min(max_sum,i+j+K);
                max_sub = min(max_sub,i-j+K);
                min_sum = max(min_sum,i+j-K);
                min_sub = max(min_sub,i-j-K);
                ok = false;
            }
        }
    }
    if(ok)
        return true;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int plus = i + j;
            int minus = i - j;
            if (min_sum <= plus && plus <= max_sum && min_sub <= minus && minus <= max_sub){
                return true;
            }
        }
    }
    return false;
}

int minDeliveryTime(const vector< vector<bool> > & G, const int R, const int C){
    
    // Fill matrix of same shape as G that shows the distance to closest store
    int worst_case_dist = R + C;
    vector< vector<int> > dist = vector< vector<int> >(R, vector<int>(C, worst_case_dist));

    // queue of pairs to store nodes for bfs 
    queue< pair<int,int> > q; 
  
    // traverse matrix and push all stores into it
    for (int i=0; i<R; i++){ 
        for (int j=0; j<C; j++){
  
            if (G[i][j]){ 
                // distace of '1' from itself is always 0 
                dist[i][j] = 0; 
  
                // make pair and push it in queue 
                q.push(make_pair(i, j)); 
            } 
        } 
    } 
    int w = bfs(dist, R, C, q);
    //printGrid(dist, R, C);
    int k_min = 0;
    int k_max = w;
    int k = w/2;
    while(k_min < k_max){
        int k = (k_min + k_max) / 2;
        bool valid = second_round(dist, R, C, k);
        if(valid){
            k_max = k;
        }
        else{
            k_min = k + 1;
        }
    }
    return k_max;
}

int main() {    
    // Defclare variables
    int T, R, C;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of rows and colomns
        cin >> R >> C;

        // Fill grid
        vector< vector<bool> > G = vector< vector<bool> >(R, vector<bool>(C, false));
        string has_store;
        for(int i = 0; i < R; ++i){
            cin >> has_store;
            for(int j = 0; j < C; ++j){
                if(has_store[j] == '1')
                    G[i][j] = true;
            }
        }

        // Output minimum delivery time
        cout << "Case #" << t << ": " << minDeliveryTime(G, R, C) << endl;
    }
    return 0;
}