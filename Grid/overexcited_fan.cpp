// CJ20/1C
// EASY
// Manhattan Distance

// g++ -std=c++14 -O2 -Wall test.cpp -o test
#include <bits/stdc++.h>
using namespace std;

int manhattanDistance(int X, int Y){
	return abs(X) + abs(Y);
}
void solve(int X, int Y, string & M){

	int distance = manhattanDistance(X,Y);
	if(distance == 0){
		cout << 0 << endl;
		return;
	}
	for(int i = 0; i < int(M.length()); i++){
		if(M[i] == 'N'){
			Y++;
		}
		else if(M[i] == 'S'){
			Y--;
		}
		else if(M[i] == 'W'){
			X--;
		}
		else{
			X++;
		}
		distance = manhattanDistance(X,Y);
		if(i + 1 >= distance){
			cout << i + 1 << endl;
			return;
		}
	}

	cout << "IMPOSSIBLE" << "\n"; // \n does not flush
}
int main() {
	// Makes input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, X, Y;
	string M;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		cin >> X >> Y >> M;

		time_t startt = clock();
        cout << "Case #" << t << ": ";
        solve(X,Y,M);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}