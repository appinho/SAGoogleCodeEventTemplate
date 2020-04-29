// KS19/C
// EASY
// Grid traversal

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue> 

using namespace std;

void robotWalk(const int t, vector< vector<bool> > & grid,
        const vector<char> & commands, const int SR, const int SC){
    
    int x = SR - 1;
    int y = SC - 1;
    grid[x][y] = true;

    for(int n = 0; n < commands.size(); n++){
        const char & c = commands[n];

        while(grid[x][y]){
            if(c == 'N'){
                x -= 1;
            }
            else if(c == 'W'){
                y -= 1;
            }
            else if(c == 'S'){
                x += 1;
            }
            else{
                y += 1;
            }
        }
        grid[x][y] = true;
    }

    cout << "Case #" << t << ": " << x + 1 << " " << y + 1 << endl;
}

int main() {
    
    // Defclare variables
    int T, N, R, C, SR, SC;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of rows and colomns
        cin >> N >> R >> C >> SR >> SC;

        // Fill grid
        vector< vector<bool> > grid = vector< vector<bool> >(R, vector<bool>(C, false));

        // Obtain commands
        vector<char> commands;
        char c;
        for(int n = 0; n < N; n++){
            cin >> c;
            commands.push_back(c);
        }

        time_t startt = clock();
        // Output minimum delivery time
        robotWalk(t, grid, commands, SR, SC);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}