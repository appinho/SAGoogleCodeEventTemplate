// KS20/B
// EASY
// Stack/Nested/Parenthesis

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
#define G 1000000000

void robot_path_decoding(string & path){

    long long r = 0;
    long long c = 0;
    for(int i = 0; i < path.length(); i++){
        if(path[i] == 'N'){
            r--;
        }
        else if(path[i] == 'E'){
            c++;
        }
        else if(path[i] == 'S'){
            r++;
        }
        else if(path[i] == 'W'){
            c--;
        }
        else{
            stack<pair<int,pair<long long,long long>>> s;
            s.push(make_pair<int,pair<long long,long long>>(path[i] - 48,make_pair<long long,long long>(0,0)));
            i++;
            while(! s.empty() && i < path.length()){
                if(path[i] == '('){

                }
                else if(path[i] == 'N'){
                    s.top().second.first--;
                }
                else if(path[i] == 'E'){
                    s.top().second.second++;
                }
                else if(path[i] == 'S'){
                    s.top().second.first++;
                }
                else if(path[i] == 'W'){
                    s.top().second.second--;
                }
                else if(path[i] == ')'){
                    auto cur_step = s.top();
                    s.pop();
                    if(!s.empty()){
                        s.top().second.first += cur_step.first * cur_step.second.first;
                        s.top().second.second += cur_step.first *  cur_step.second.second;
                        // cerr << "BEFORE " << s.top().first << "*" << s.top().second.first << " " << s.top().second.second << endl;
                        s.top().second.first %= G;
                        s.top().second.second %= G;
                        
                        // cerr << "SHIFT " << s.top().first << "*" << s.top().second.first << " " << s.top().second.second << endl;
                    }
                    else{
                        r += cur_step.first * cur_step.second.first;
                        c += cur_step.first * cur_step.second.second;
                        r %= G;
                        c %= G;
                        // cerr << "BIG SHIFT " << cur_step.first << "*" 
                        //     << cur_step.second.first << " " << cur_step.second.second << endl;
                        // cerr << r << " " << c << endl;
                        break;
                    }
                    // cr = 0;
                    // cc = 0;
                }
                else{
                    s.push(make_pair<int,pair<long long,long long>>(path[i] - 48,make_pair<long long,long long>(0,0)));
                }
                // cerr << s.size() << " " << i << " " << path[i] << " " << cr << " " << cc << endl;
                i++;
            }
            // i--;
            // r += dr;
            // c += dc;
            // i++;
        }
        
        if(r<0){
            r += G;
        }
        if(r>G){
            r -= G;
        }
        if(c<0){
            c += G;
        }
        if(c>G){
            c -= G;
        }
        // cerr << r << " " << c << endl;
    }
    cout << c+1 << " " << r+1;
}

int main(){

    int T;
    string path;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> path;

        time_t startt = clock();
        cout << "Case #" << t << ": ";
        robot_path_decoding(path);
        cout << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
