// CJ18/P
// EASY
// Precision

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

double speed_2_control_cruise(vector<pair<int,int>> & horses, int D){

	double max_time = 0;
	for(int n = 0; n < int(horses.size()); n++){
		double time = double(D - horses[n].first) / horses[n].second;
		if(time > max_time){
			max_time = time;
		}
	}
	return D / max_time;
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

	int T, N, D, k, s;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cin >> D >> N;
		
		vector<pair<int,int>> horses;
		for(int n = 0;n<N;n++){
			cin >> k >> s;
			horses.push_back(make_pair(k,s));
		}
		
		time_t startt = clock();
		cout.precision(10);
        cout << "Case #" << t << ": " << speed_2_control_cruise(horses, D) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}