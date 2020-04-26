// CJ19/1A
// HARD
// Backtracing/Random

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

static int R, C;

bool dfs(int x, int y, vector<vector<bool> > & visited, vector<pair<int,int> > & path){

    
    //cerr << path.size() << "   " << x << " " << y << endl;

    if(path.size() == R*C){
        //cerr << "DONE" << endl;
        return true;
    }

    vector<pair<int,int> > next_nodes;

    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(!visited[r][c]){
                if(x != r && y != c && (x+y) != (r+c) && (x-y) != (r-c)){
                    next_nodes.push_back(make_pair(r, c));
                }
            }
        }
    }
    if(!next_nodes.empty()){
        for(int i = 0; i < next_nodes.size(); i++){
            int nx = next_nodes[i].first;
            int ny = next_nodes[i].second;
            visited[nx][ny] = true;
            path.push_back(make_pair(nx, ny));
            if(dfs(nx, ny, visited, path)){
                return true;
            }
            else{
                visited[nx][ny] = false;
                path.pop_back();
            }
        }
    }
    return false;
}

void pylons(){

    int rend = (R+1)/2;
    int cend = (C+1)/2;
    for(int r = 0; r < rend; r++){
        for(int c = 0; c < cend; c++){
            //cerr << "START " << r << " " << c << endl;
            vector<vector<bool> > visited(R, vector<bool>(C, false));
            vector<pair<int,int> > path;
            visited[r][c] = true;
            path.push_back(make_pair(r, c));
            if(dfs(r, c, visited, path)){
                cout << "POSSIBLE" << endl;
                for(auto const & p: path){
                    cout << (p.first + 1) << " " << (p.second + 1) << endl;
                }
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    
    int T;
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> R >> C;

        //time_t startt = clock();
        cout << "Case #" << t << ": ";
        pylons();
        //cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}