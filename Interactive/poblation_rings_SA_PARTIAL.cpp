/*
t, w = readline_int_list()   // Reads 50 into t and 6 into w
printline 3 to stdout        // Asks about day 3.
flush stdout
n = readline_int()           // Reads 15 into n.
printline 1 to stdout        // Asks about day 1.
flush stdout
n = readline_int()           // Reads 7 into n.
printline 1 1 1 3 0 0 to stdout
flush stdout                 // We make a guess even though we could have
                             // queried the well up to four more times.
verdict = readline_int()     // Reads -1 into verdict (judge has decided our
                             //   solution is incorrect)
exit                         // Exits to avoid an ambiguous TLE error 
*/

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

static int mod = 63;

long long ask(int v){
    //printf("%d\n", v);
    //fflush(stdout);
    cout << v << endl;
    
    long long ret;
    cin >> ret;
    //assert(ret != -1);
    //scanf("%lld", &ret);
    return ret;
}

int main() {
    
    int T, W;
    long long N;
    cin >> T >> W;
    //scanf("%d %d", &T, &W);

    //std::cerr << T << " " << W << std::endl;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){
        //std::cerr << "TC " << t << std::endl;
        vector<long long> res(6, 0);
        for(int w = 5; w >= 0; --w){
            int guess = mod * w;
            if(guess == 0)
                guess = 1;
            //cerr << "Guess " << guess << endl;
            N = ask(guess);
            //cerr << "Rec " << N << endl;
            for(int i = w; i < 6; i++){
                //cerr << "Use " << res[i] << endl;
                N -= res[i] * pow(2, guess/(i+1));
                //cerr << i << " " << N << endl;
            }
            //cerr << N << endl;
            int e = guess/(w+1);
            //cerr << e << endl;
            long long d = pow(2,e);
            //cerr << d << endl;
            int sol = N / d;
            //cerr << "Found R" << w+1 << " " << sol << endl;
            res[w] = sol;
            //res[w] = N;
        }
        for(int i = 0; i < 6; i++){
            cout << res[i] << " ";
        }
        cout << endl;
        //printf("%lld %lld %lld %lld %lld %lld\n", res[1], res[2], res[3], res[4], res[5], res[6]);
        //fflush(stdout);
        
        int cor;
        cin >> cor;
        //scanf("%d", &cor);
        //assert(cor == 1);
    }
    return 0;
}