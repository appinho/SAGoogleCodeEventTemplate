// g++ template.cpp -std=c++14 -D_DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	// INPUT
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		int N, M;
		cin >> N >> M;

		// SOLVE
		int sol = min(2, N - 1) * M; 

		// OUTPUT
		cout << sol << endl;
		// cout << "Case #" << t << ": " << sol << endl;
	}
	
	return 0;
}