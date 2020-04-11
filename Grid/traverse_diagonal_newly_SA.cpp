#include <iostream>
#include <string>
#include <string>

using namespace std;


string maze_solver(string & path){

    for(int i = 0; i < path.length(); i++){
        if(path[i] == 'S'){
            path[i] = 'E';
        }
        else{
            path[i] = 'S';
        }
    }

    return path;
}

int main() {
    
    int T, N;
    string P;
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> N;
        cin >> P;

        time_t startt = clock();
        cout << "Case #" << t << ": " << maze_solver(P) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}