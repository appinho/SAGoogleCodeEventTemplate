// CJ18/1A
// Medium
// Sorting/Counting

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

string cookieCut(vector<vector<bool>> & grid,
	vector<int> & hor, vector<int> & ver, 
	int sum, int H, int V, int R, int C){

	if(sum == 0){
		return "POSSIBLE";
	}
	if(sum % (H + 1) || sum % (V + 1)){
		return "IMPOSSIBLE";
	}

	int chop_hor = sum / (H + 1);
	int chop_ver = sum / (V + 1);
	// cerr << "FIND  " << chop_hor << " " << chop_ver << endl;
	// for(auto h: hor){
	// 	cerr << h << " ";
	// } cerr << endl;
	// for(auto h: ver){
	// 	cerr << h << " ";
	// } cerr << endl;
	int mult = 1;
	int sum_row = 0;
	vector<int> hor_cuts;
	hor_cuts.push_back(-1);
	for(int i = 0; i < R; i++){
		sum_row += hor[i];
		if(sum_row > mult * chop_hor){
			// cerr << "R " << i << " " << mult * chop_hor << " " << sum_row << endl;
			return "IMPOSSIBLE";
		}
		else if(sum_row == mult * chop_hor){
			mult++;
			hor_cuts.push_back(i);
		}
	}
	mult = 1;
	int sum_ver = 0;
	vector<int> ver_cuts;
	ver_cuts.push_back(-1);
	for(int j = 0; j < C; j++){
		sum_ver += ver[j];
		if(sum_ver > mult * chop_ver){
			// cerr << "V " << j << " " << mult * chop_ver << " " << sum_ver << endl;
			return "IMPOSSIBLE";
		}
		else if(sum_ver == mult * chop_ver){
			mult++;
			ver_cuts.push_back(j);
		}
	}
	int pieces = sum / (H+1) / (V+1);
	// cerr << "PIECES  " << pieces << endl;
	// for(auto h: hor_cuts){
	// 	cerr << h << " ";
	// } cerr << endl;
	// for(auto h: ver_cuts){
	// 	cerr << h << " ";
	// } cerr << endl;
	for(int i = 0; i < int(hor_cuts.size() - 1);i++){
		for(int j = 0; j < int(ver_cuts.size() - 1);j++){
			int temp = 0;
			// cerr << "HOR " << i << " " << hor_cuts[i] +1 << " " << hor_cuts[i+1] << endl;
			// cerr << "VER " << j << " " << ver_cuts[j] +1 << " " << ver_cuts[j+1] << endl;
			for(int k = hor_cuts[i] +1; k <= hor_cuts[i+1]; k++){
				for(int l = ver_cuts[j] + 1; l <= ver_cuts[j+1]; l++){
					// cerr << k << " " << l << endl;
					if(grid[k][l]){
						temp++;
					}
				}
			}
			// cerr << "COMPARE " << temp << " " << pieces << endl;
			if(temp != pieces){
				return "IMPOSSIBLE";
			}
		}
	}

	return "POSSIBLE";
}
int main() {
	// Makes input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int T, R, C, H, V;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		cin >> R >> C >> H >> V;
		vector<int> hor(R,0);
		vector<int> ver(C,0);
		vector<vector<bool>> grid(R, vector<bool>(C, false));
		char a;
		int sum = 0;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin >> a;
				if(a != '.'){
					hor[i]++;
					ver[j]++;
					sum++;
					grid[i][j] = true;
				}
			}
		}
		
		time_t startt = clock();
        
        cout << "Case #" << t << ": " << cookieCut(grid, hor, ver, sum, H, V, R, C) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}