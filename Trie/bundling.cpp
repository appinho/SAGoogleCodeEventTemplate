// KS20/A
// MEDIUM
// Trie
// Prefix/Combinatorics

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

const int ALPHA = 26;

long solve(vector<string> S, int N, int K){

    vector<vector<int>> trie;
    trie.emplace_back(ALPHA, -1);
    map<pair<int,int>,int> ma;
    for(int i = 0; i < N; i++){
		string & s = S[i];
		// Traverse through trie
		int t = 0;
		for (char c : string(s.begin(), s.end())) {
			// cerr << "Adding " << c << endl;
			int d = (int) (c - 'A');
			// If char creates a new branch
			if (trie[t][d] == -1) {

				// Add new node
				trie[t][d] = (int) trie.size();
				trie.emplace_back(ALPHA, -1);
			}
			t = trie[t][d];
			ma[make_pair(t,d)]++;
		}
    }
    // for(auto tr: trie){
    //   for(auto t: tr){
    //     cerr << t << " ";
    //   }
    //   cerr << endl;
    // }
    // cerr << endl;
    long ans = 0;
    for(auto m: ma){
      // cerr << v << " ";
      ans += m.second / K;
    } // cerr << endl;
    return ans;
}

long solve2(vector<string> S, int N, int K){

	unordered_map<string, int> ma;
	for(int i = 0; i < N; i++){
		for(int j = 1; j <= int(S[i].length()); j++){
			ma[S[i].substr(0,j)]++;
		}
	}
	long sum = 0;
	for(auto m: ma){
		sum += m.second / K;
	}
	return sum;
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

	int T, N, K;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		cin >> N >> K;

		string s;
		vector<string> S;
		
		for(int i = 0; i < N; i++){
			cin >> s;
			S.push_back(s);
		}
		time_t startt = clock();
        cout << "Case #" << t << ": " << solve(S, N, K) << "\n";
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}