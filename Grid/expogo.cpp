// CJ20/1B
// MIDDLE
// Odd/Even

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
#include <bitset>

using namespace std;

string expogo(int X, int Y){

    string s;
    if(abs(X % 2) == abs(Y % 2)){
        s = "IMPOSSIBLE";
        return s;
    }

    while(X != 0 || Y != 0){
        int ans;
        int sum = (X + Y - 1) / 2;
        // cerr << X << " " << Y << " " << sum << " " << sum % 2 << " " << X % 2 << endl;
        if(X % 2){
            if(((sum % 2) && !(X == -1 && Y == 0)) || (X == 1 && Y == 0)){
                s += "E";
                X--;
            }
            else{
                X++;
                s += "W";
            }
        }
        else{
            if(((sum % 2) && !(X == 0 && Y == -1))|| (X == 0 && Y == 1)){
                s += "N";
                Y--;
            }
            else{
                s += "S";
                Y++;
            }
        }
        // cerr << "AFTER " << s << " " << X << " " << Y << endl;
        X /=2;
        Y /=2;
    }
    return s;
}

int main(){

    // // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }
    
    int T, X, Y;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> X >> Y;

        time_t startt = clock();
        cout << "Case #" << t << ": " << expogo(X,Y) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
