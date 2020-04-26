// CJ20/1B
// MIDDLE
// Binary search
// blindfolded_bullseye

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

string ask(int x, int y){

    cout << x << " " << y << endl;
    
    string response;
    cin >> response;
    // cerr << x << " " << y << " " << response << endl;
    return response;
}

int main(){
   
    int T, A, B;
    int R;

    cin >> T >> A >> B;
    int L = 1000000000;
    int edge = L - A;
    for(int t = 1; t <= T; ++t){

        int tmin = 0;
        int tmax = edge * 2;
        int bmin = 0;
        int bmax = edge * 2;
        
        while(tmin <= tmax){
            int m = (tmin + tmax) / 2;
            string res = ask(0, L - m);
            // cerr << m << " " << res << endl;
            if(res == "MISS"){
                tmin = m + 1;
            }
            else if(res == "HIT"){
                tmax = m - 1;
            }
        }
        // cerr << "R " << " " << tmin << endl;
        while(bmin <= bmax){
            int m = (bmin + bmax) / 2;
            string res = ask(0, -L + m);
            if(res == "MISS"){
                bmin = m + 1;
            }
            else if(res == "HIT"){
                bmax = m - 1;
            }
        }

        int lmin = 0;
        int lmax = edge * 2;
        int rmin = 0;
        int rmax = edge * 2;
        while(lmin <= lmax){
            int m = (lmin + lmax) / 2;
            string res = ask(-L + m, 0);
            if(res == "MISS"){
                lmin = m + 1;
            }
            else if(res == "HIT"){
                lmax = m - 1;
            }
        }
        while(rmin <= rmax){
            int m = (rmin + rmax) / 2;
            string res = ask(L - m, 0);
            // cerr << res << endl;
            if(res == "MISS"){
                rmin = m + 1;
            }
            else if(res == "HIT"){
                rmax = m - 1;
            }
            // else{
            //     cerr << "WEIRD" << endl;
            // }
        }
        int R = L - (lmin + rmin + tmin + bmin) / 4;
        cerr << lmin << " " << rmin << "/" << tmin << " " << bmin << "->" << R <<endl;

        int gx = (lmin - rmin) / 2;
        int gy = (bmin - tmin) / 2;
        cerr << gx << " " << gy << endl;
        bool finish = false;
        // int tr = 0;
        for(int x = -10; x <= 10; x++){
            for(int y = -10; y <= 10; y++){
                string new_res = ask(gx + x, gy + y);
                // cerr << tr << " " << lmin + x << " " << tmin + y << " " << new_res << endl;
                if(new_res == "CENTER"){
                    finish = true;
                }
                // tr ++;
                if(finish) break;
            }
            if(finish) break;
        }

    }
    return 0;
}
