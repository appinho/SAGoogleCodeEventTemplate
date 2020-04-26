// CJ18/Q
// MEDIUM
// Probability

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt, aa;
  int a, b;
  cin >> tt;
  // cerr << tt << endl;
  for (int qq = 1; qq <= tt; qq++) {
    cin >> aa;
    int width;
    int height;

    if(aa == 20){
      width = 5;
      height = 1;
    }
    else{
      width = 65;
      height = 1;
    }
    vector< vector<int> > grid(height+4, vector<int>(width+4,0));
    vector<set<int>> col(width + 2);
    // cerr << width << endl;
    for(int x = 0; x < 1000; x++){

      int min_col;
      int min = 10;
      int hits;
      int sum = col[0].size() + col[width+1].size();
      for(int i = 1; i <= width; i++){
        hits = col[i-1].size() + col[i].size() + col[i+1].size();
        sum +=col[i].size();
        if(hits == 0){
          min_col = i;
          break;
        }
        else if(hits < min){
          min = hits;
          min_col = i;
        }
      }
      // for(auto c: col){
      //   cerr << c.size() << " ";
      // }
      // cerr << endl;
      // cerr << "Try " << x << " col " << min_col << " " << min << endl;
      cout << 2 << " " << 1 + min_col << endl;
      cin >> a >> b;

      // cerr << x << " AIM " << 2 << "," << 1 + min_col << " GOT " <<
      //   a << "," << b << "->" << sum << endl;
      

      
      if (a == 0 && b == 0) {
        // cerr << "DONE" << endl;
        // for(int i = 0; i < grid.size(); i++){
        //   for(int j = 0; j < grid[i].size(); j++){
        //     cerr << grid[i][j] << " ";
        //   } 
        //   cerr << endl;
        // }
        // cerr << endl;
        // cerr << endl;
        break;
      }
      else{
        col[b-1].insert(a-1);
        grid[a][b] = 1;
      }
    }
  }
  return 0;
}
