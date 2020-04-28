// CJ19/1A
// HARD
// Trie
// Prefix/Suffix

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    const int ALPHA = 26;
    vector<vector<int>> trie;
    // TRIE will have dimensions #Nodes + 1 x ALPHA
    // where each cell stores the row to jump to for accessing the next node
    // Last row is only -1
    trie.emplace_back(ALPHA, -1);
    vector<int> visits(1, 0);
    vector<int> pv(1, -1);
    while (n--) {
      string s;
      cin >> s;
      // Traverse through trie
      int t = 0;
      for (char c : string(s.rbegin(), s.rend())) {
        int d = (int) (c - 'A');
        // If char creates a new branch
        if (trie[t][d] == -1) {
          // trie[0][L / 11] = 1;
          // cerr << "ADD " << c << "/" << d << " TRIE SIZE " << (int) trie.size() << endl;
          
          // Add new node
          trie[t][d] = (int) trie.size();
          trie.emplace_back(ALPHA, -1);
          visits.push_back(0);
          pv.push_back(t);
        }

        t = trie[t][d];
        visits[t]++;
      }
    }
    // Trie size number of nodes + 1 since this was the new buffer
    for(auto tr: trie){
      for(auto t: tr){
        cerr << t << " ";
      }
      cerr << endl;
    }
    cerr << endl;
    cerr << "# NODES " << trie.size() - 1 << endl;
    for(auto v: visits){
      cerr << v << " ";
    } cerr << endl;
    // Visit stores the number of not adding a node
    for(auto v: pv){
      cerr << v << " ";
    } cerr << endl;
    // Visit stores the walkthrough of each letter
    int ans = 0;
    for (int i = (int) trie.size() - 1; i >= 0; i--) {
      if (visits[i] < 2) {
        continue;
      }
      ans++;
      int v = i;
      while (v != -1) {
        visits[v] -= 2;
        v = pv[v];
      }
    }
    cout << 2 * ans << '\n';
  }
  return 0;
}
