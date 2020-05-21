// g++ template.cpp -std=c++14 -D_DEBUG
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[26];
vector<bool> visited;
vector<char> ans;
bool worked;

void dfs(int v) {
	if(visited[v]){
		worked = false;
		return;
	}
    visited[v] = true;

    for (int u : adj[v]) {
    	// cout << v << "->" << u << endl;
        if (!visited[u]){
            dfs(u);
        }
    }
    ans.push_back(char(v+'A'));
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
		visited = vector<bool>(26, false);
		ans.clear();

		for(int i = 0; i < 26; i++){
		    if (adj[i].size())
		        dfs(i);
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