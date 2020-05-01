// g++ -std=c++14 -O2 -Wall test.cpp -o test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

void solve(int N){

	cout << N << "\n"; // \n does not flush
}
int main() {
	// Makes input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);

	// REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }

	int T, N;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		cin >> N;

		time_t startt = clock();
        cout << "Case #" << t << ": ";
        solve(N);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}