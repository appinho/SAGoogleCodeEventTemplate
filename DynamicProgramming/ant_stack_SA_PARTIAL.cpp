#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n;
int w[100001];
int computed[11][60];

void print_computed(){
    cerr << endl;
    for(int i = 0; i < 11; i ++){
        for(int j = 0; j < 60; j ++){
            cerr << computed[i][j] << " ";
        }
        cerr << endl;
    }
}

int dp(int ant, int weigth)
{
    if(weigth<0) return 0;
    if(ant==n) return 1;
    if(computed[ant][weigth]!=-1) return computed[ant][weigth];

    int mm = 0;
    for(int i=ant+1;i<=n;i++)
    {
        mm = max ( mm, dp(i, min(w[i]*6,weigth-w[i])) );
    }
    computed[ant][weigth]=mm+1;
    return mm+1;
}

int solve(){

    memset(computed,0-1,sizeof(computed));
    print_computed();
    int mm=0;
    for(int i=1;i<=n;i++){
        mm = max( mm, dp(i,w[i]*6) );
        cerr << i << " " << mm << endl;
        print_computed();
    }
	return mm;
}

int main() {
    
    // Remove ifstream later
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }

    // Read in number of test cases
    int T;
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

    	// Read input
    	cin >> n;

        for(int i = 0; i < n; i++){
            cin >> w[n-i];
        }

    	// Time and perform
        time_t startt = clock();
        cout << "Case #" << t << ": " << solve() << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    
    return 0;
}