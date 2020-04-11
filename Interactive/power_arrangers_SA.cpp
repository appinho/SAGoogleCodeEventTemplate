#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

//int C = 5;
//int CH = [119, 23, 5, 1];

int C = 5;
vector<int> CH = {119, 23, 5, 1};
vector<int> O = {23, 5, 1, 0};

char ask(int guess, int & f){

    //cerr << "GUESS " << guess << endl;
    cout << guess << endl;
    
    char response;
    cin >> response;
    //assert(response != 'N');
    //cerr << response << endl;
    f++;
    //cerr << f << endl;
    return response;
}

int main() {

	int T, F;
	cin >> T >> F;
	cerr << T << " " << F << endl;
    
	// Loop over test cases
	for(int t = 1; t <= T; ++t){
        
        int f = 0;
        vector<bool> used(C, false);
        vector<bool> asked(CH[0], false);
        
        std::string sol = "";

		cerr << "Test Case # " << t << endl;
        for(int i = 0; i < C - 1; i++){
            cerr << "i " << i << endl;
            vector<int> count(C);
            vector<char> res(CH[0]);

            for(int j = 0; j < CH[0]; j++){
                if(!asked[j]){
                    char answer = ask(j*C + i + 1, f);
                    res[j] = answer;
                    int index = int(answer - 'A');
                    count[index]++;
                }
            }
            cerr << "Counter ";
            for(int j = 0; j < C; j++){
                cerr << count[j] << " ";
            }
            cerr << endl;
            char s;
            for(int j = 0; j < C; j++){
                if(count[j] == O[i] && !used[j]){
                    s = char(j + 65);
                    used[j] = true;
                    //cerr << "SOL " << s << endl;
                }
            }
            //for()
            for(int j = 0; j < CH[0]; j++){
                if(res[j] != s){
                    asked[j] = true;
                }
            }
            cerr << "Asked ";
            for(int j = 0; j < CH[0]; j++){
                cerr << asked[j] << " ";
            }
            cerr << endl;
            sol += s;
            cerr << "CUR SOL " << sol << endl;
        }
        cerr << "Used";
        //for(int i = 0; i < C; i++){
        //    cerr << used[i] << " ";
        //}
        //cerr << endl;
        for(int i = 0; i < C; i++){
            if(!used[i]){
                sol += char(i + 65);
            }
        }
        cerr << "END SOL " << sol << endl;
        if(sol.size() != 5){
            cerr << "ERROR" << endl;
        }
        cout << sol << endl;
        
        char correct;
        cin >> correct;
        //assert(correct != 'N');
        cerr << "Correct: " << correct << endl;
        
    }

    return 0;
}