// CJ18/Q
// HARD
// Precision/Geometry

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

long double A;
void solve()
{
	long double phi=asinl(A/sqrtl(2))-M_PI/4;
	long double c=0.5*cosl(phi),s=0.5*sinl(phi);
	printf("%.16Lf %.16Lf 0\n",c,s);
	printf("%.16Lf %.16Lf 0\n",-s,c);
	printf("0 0 0.5\n");
}

void cubic_ufo_sol(){

	long double l = M_PI / 4 - fabsl(acosl(A / sqrtl(2.0)));
	cout.precision(15);
	cout << cosl(l) / 2 << " " << sinl(l) / 2 << " " << 0 << "\n"; // \n does not flush
	cout << -sinl(l) / 2 << " " << cosl(l) * 0.5 << " " << 0 << "\n"; // \n does not flush
	cout << 0 << " " << 0 << " " << 0.5 << "\n"; // \n does not flush
}

void cubic_ufo(){

	long double l = 0;
	long double r = 45 * M_PI / 180 ;

	long double m;
	long double NA;
	// cerr.precision(17);
	// cerr << l << " " << r << endl;
	while(fabsl(r-l) >= 1e-18){

		m = (l+r) / 2;
		NA = cosl(m) + sinl(m);
		// if(fabsl(NA-A) < 1e-18){
		// 	break;
		// }
		if(NA-A > 0){
			r = m;
		}
		else{
			l = m;
		}
	}
	long double c = cosl(m) * 0.5;
	long double s = sinl(m) * 0.5;
	// cerr << m << " " << l << " " << r << " " << NA-A << endl;
	cout.precision(17);
	cout << c << " " << s << " " << 0 << "\n"; // \n does not flush
	cout << -s << " " << c << " " << 0 << "\n"; // \n does not flush
	cout << 0 << " " << 0 << " " << 0.5 << "\n"; // \n does not flush
}
int main() {

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		scanf("%Lf",&A);

		// time_t startt = clock();
        cout << "Case #" << t << ":\n";
        // printf("Case #%d:\n",t);
        cubic_ufo();
        // cerr << "~ #" << t << " done! time : " << (long double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}