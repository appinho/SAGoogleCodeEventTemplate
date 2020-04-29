// KS19/E
// HARD
// Sorting/Binary search

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

std::string code_eat_switcher(const int S, const int D, 
    vector<pair<float,float> > & slots, vector<pair<float,float> > & days){

    std::string sol = "";

    for(int ss = 0; ss < S; ss++){
        cerr << "SLOTS: " << ss << " -> " << slots[ss].first << " " << slots[ss].second << endl;
    }

    if(S==1){
        for(int dd = 0; dd < D; dd++){
            float rat = 1 - (days[dd].first / slots[0].first);
            float Y = rat * slots[0].second;
            cerr << rat << " " << Y << endl;
            if(rat >= 0 && rat <= 1 && Y >= days[dd].second)
                sol += "Y";
            else
                sol += "N";
        }
    }
    else if(S==2){
        for(int dd = 0; dd < D; dd++){
            cerr << "DAY: " << dd << " -> " << days[dd].first << " " << days[dd].second << endl;
            bool made_it = false;
            for(int c = 0; c <= slots[0].first; c++){
                float X = c;
                float C_L = days[dd].first - X;
                cerr << c << " " << C_L << endl;
                if(C_L <= 0){
                    C_L = 0;
                }
                if(C_L > slots[1].first) continue;
                float rat1 = (slots[0].first - X) / slots[0].first;
                float rat2 = (slots[1].first - C_L) / slots[1].first;
                //float rat1 = 1 - (X / slots[0].first);
                //float rat2 = 1 - (C_L / slots[1].first);
                int Y = rat1 * slots[0].second + rat2 * slots[1].second;
                cerr << X << " " << " " << Y << " || " << rat1 << " " << rat2 << endl; 
                if(Y >= days[dd].second){
                    made_it = true;
                    cerr << "MADE IT " << X << " " << " " << Y << " || " << rat1 << " " << rat2 << endl;
                    break;
                }
            }
            if(made_it)
                sol += "Y";
            else
                sol += "N";
        }
    }
    
    return sol;
}

int main() {

    // Defclare variables
    int T, S, D;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of rows and colomns
        cin >> D >> S;

        vector< pair<float,float> > slots(S);
        vector< pair<float,float> > days(D);

        // Obtain commands
        float l , r;
        for(int s = 0; s < S; s++){
            cin >> l >> r;
            slots[s].first = l;
            slots[s].second = r;
        }
        for(int d = 0; d < D; d++){
            cin >> l >> r;
            days[d].first = l;
            days[d].second = r;
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << code_eat_switcher(S, D, slots, days) << endl;
        // Output minimum delivery time
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}