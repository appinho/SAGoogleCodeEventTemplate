// KS20/C
// MEDIUM
// Topological Sort/DFS

// g++ template.cpp -std=c++14 -D_DEBUG
// https://cp-algorithms.com/graph/depth-first-search.html
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[26];
vector<int> visited;
vector<char> ans;
bool worked;

/* EXAMPLE
A
M
O -> A
O -> M
Z -> O

Visit A: 
1 0 0 0
2 0 0 0
A
Visit M
1 1 0 0
2 2 0 0
AM
Visit O
2 2 1 0
2 2 2 0
AMO
Visit Z
2 2 2 1
2 2 2 2
AMOZ
=> ZOMA
*/

void dfs(int v) {
	// cout << "Visit " << v << endl;
	// for(auto vi: visited){
	// 	cout << vi << " ";
	// }cout << endl;
	// for(auto vi: ans){
	// 	cout << vi << " ";
	// }cout << endl;
    visited[v] = 1;

    for (int u : adj[v]) {
    	// cout << v << "->" << u << endl;
        if (visited[u] == 0){
            dfs(u);
        }
        else if(visited[u] == 1){
			worked = false;
			return;
		}
    }
    ans.push_back(char(v+'A'));
    visited[v] = 2;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	// INPUT
	int T, R, C;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cin >> R >> C;

		// SOLVE
		vector<vector<char>> wall(R, vector<char>(C));
		string s;
		set<char> se;
		for(int i = 0; i < R; i++){
			cin >> s;
			for(int j = 0; j < C; j++){
				wall[i][j] = s[j];
				se.insert(s[j]);
			}
		}
		
		set<pair<int,int>> edges;
		for(int j = 0; j < C; j++){
			int prev = wall[R-1][j] - 'A';
			for(int i = R - 2; i >= 0; i--){
				int cur = wall[i][j] - 'A';
				pair<int,int> edge = make_pair(prev,cur);
				if(prev != cur && edges.count(edge) == 0){
					adj[prev].push_back(cur);
					// cout << "Edge " << prev << "->" << cur << endl;
				}
				edges.insert(edge);
				prev = cur;
			}
		}
		// for(int i = 0; i < 26; i++){
		// 	for(auto a: adj[i]){
		// 		cout << a << " ";
		// 	}
		// 	cout << "\n";
		// }
		worked = true;
		visited = vector<int>(26, 0);
		ans.clear();

		for(int i = 0; i < 26; i++){
		    if (se.count(i+'A') && visited[i] == 0){
		    	dfs(i);
		    }
		}
	    reverse(ans.begin(), ans.end());
		cout << "Case #" << t << ": ";
		if(worked){
			for(auto p: ans){
				cout << p;
			}
			cout << "\n";
		}
		else{
			cout << -1 << "\n";
		}
		for(int i=0; i<26; ++i)
			adj[i].clear();
	}
	
	return 0;
}