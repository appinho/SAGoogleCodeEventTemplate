// CJ18/Q
// EASY
// Swap

#include <iostream>

using namespace std;

int calc_damage(const string & commands){

    int dam = 1;
    int sum = 0;
    for(int i = 0; i < commands.length(); i++){
        if(commands[i] == 'S')
            sum += dam;
        else
            dam *= 2;
    }
    return sum;
}

string minimumHacks(const int shield, string & commands){

    // Calculate current damage
    int damage = calc_damage(commands);
    int swaps = 0;

    while(damage > shield){
        bool swaped = false;
        for(int i = commands.length() - 1; i >= 0; i--){
            if(commands[i-1] == 'C' && commands[i] == 'S'){
                std::swap(commands[i-1], commands[i]);
                swaped = true;
                break;
            }
        }
        if(!swaped){
            return "IMPOSSIBLE";
        }
        else{
            damage = calc_damage(commands);
        }
        swaps++;
    }
    return to_string(swaps);
}
int main() {
    
    // Defclare variables
    int T, D;
    string P;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of students and size of team
        cin >> D >> P;

        // Output minimum hours of coaching
        cout << "Case #" << t << ": " << minimumHacks(D, P) << endl;
    }
    return 0;
}