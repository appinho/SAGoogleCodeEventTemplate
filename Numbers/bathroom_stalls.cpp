// CJ18/P
// 
// 

// g++ -std=c++14 -O2 -Wall test.cpp -o test
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/*
S = {N}  - This is a multiset!
repeat K times:
X = max(S)
X0 = ceil((X - 1) / 2)
X1 = floor((X - 1) / 2)
if this is the last step:
  we are done; answer is X0 and X1
else:
  remove one instance of X from S
  insert X0 and X1 into S
*/
void bathroom_stalls_2(ll N, ll K){

	priority_queue<ll> S;
	S.push(N);
	ll l, r;
	for(int k = 1; k <= K; k++){
		ll X = S.top();
		l = ceil((X-1) / 2);
		r = (X-1) / 2;
		S.pop();
		S.push(l);
		S.push(r);
	}

	cout << l << " " << r << endl;
}
/*
S = {N}  - This is a set, not a multiset!
C(N) = 1
P = 0
repeat:
X = max(S)
X0 = ceil((X - 1) / 2)
X1 = floor((X - 1) / 2)
P = P + C(X)
if P ≥ K:
  we are done; the answer is X0 and X1.
else:
  remove X from S
  insert X0 and X1 into S
  add C(X) to the counts of X0 and X1 in C
*/
void bathroom_stalls(ll N, ll K){

	map<ll, ll> counts;
	counts[N] = 1;
	ll l, r;
	while(true){
		auto count = *--counts.end();
		ll X = count.first;
		l = X - (X + 1) / 2;
		r = (X-1) / 2;
		// cerr << count.first << " " << count.second << " " << l << " " << r << endl;
		counts.erase(--counts.end());
		if(count.second >= K){
			break;
		}
		K -= count.second;
		counts[l] += count.second;
		counts[r] += count.second;
	}

	cout << l << " " << r << endl;
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

	int T;
	ll N, K;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cin >> N >> K;
		time_t startt = clock();
        cout << "Case #" << t << ": ";
        bathroom_stalls(N, K);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}