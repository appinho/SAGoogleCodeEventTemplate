// CJ19/1C
// MEDIUM
// Permutations / GCD

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

using namespace std;

struct compareFirstPairMember {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first + a.second < b.first + b.second;
    }
};

int numSortingsA(vector<pair<int,int> > & v){

    // std::sort(v.begin(), v.end()); //, compareFirstPairMember());
    int num_sorts = 0;
    do {
        float ratio = 0;
        bool valid = true;
        for (int i = 1; i < v.size(); i++) {
            float new_ratio;
            if(v[i].second < v[i-1].second){
                new_ratio = (v[i].first - v[i-1].first) / (v[i - 1].second - v[i].second);
            }
            else if(v[i].second == v[i-1].second){
                if(v[i].first < v[i-1].first){
                    valid = false;
                    break;
                }
            }
            else{
                new_ratio = (v[i - 1].first - v[i].first) / (v[i - 1].second - v[i].second);
            }            
            if(new_ratio < ratio){
                // cerr << sum << ">=" << new_sum << endl;
                valid = false; 
                break;
            }
            else{
                ratio = new_ratio;
            }
            // if(new_ratio < ratio){
            //     valid = false;
            //     break;
            // }
            // else ratio = new_ratio;
        }
        if(valid){
            num_sorts++;
            cerr << "Found " << num_sorts << endl;
            for (int i = 0; i < v.size(); i++) {
                cerr << v[i].first << "," << v[i].second << "  ";
            }
            cerr << endl;
        }
    } while (next_permutation(v.begin(), v.end())); //, compareFirstPairMember())); 
    return num_sorts;
}

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int numSortings(const vector<pair<int,int> > & v, int n){

    set<pair<int,int> > s;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
            int dx = v[i].first - v[j].first;
            int dy = v[j].second - v[i].second;
        
            if (dx > 0 && dy > 0) {
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                s.emplace(dx, dy);
                // cerr << dx << " " << dy << " " << g << endl;
            }
        }
    }
    return (int) s.size() + 1;
}

int main(){

    int T, N;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;

        vector<pair<int,int> > C;
        int c1, c2;
        for(int i = 0; i < N; i++){
            cin >> c1 >> c2;
            C.push_back(make_pair(c1, c2));
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << numSortings(C, N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
