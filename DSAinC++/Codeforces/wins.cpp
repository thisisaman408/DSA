#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        vector<pair<int, int>> suneet = {{a1, b1}, {a1, b2}, {a2, b1}, {a2, b2}};
        vector<pair<int, int>> slavic = {{b1, a1}, {b1, a2}, {b2, a1}, {b2, a2}};
        
        int suneet_wins = 0;
        
        for (auto round : suneet) {
            int suneet_card1 = round.first;
            int slavic_card1 = round.second;
            
            for (auto inner_round : slavic) {
                int suneet_card2 = inner_round.second;
                int slavic_card2 = inner_round.first;
                
                if (suneet_card1 != suneet_card2 && slavic_card1 != slavic_card2) {
                    int suneet_score = 0, slavic_score = 0;
                    
                    if (suneet_card1 > slavic_card1) suneet_score++;
                    else if (suneet_card1 < slavic_card1) slavic_score++;
                    
                    if (suneet_card2 > slavic_card2) suneet_score++;
                    else if (suneet_card2 < slavic_card2) slavic_score++;
                    
                    if (suneet_score > slavic_score) suneet_wins++;
                }
            }
        }
        
        cout << suneet_wins << endl;
    }
    return 0;
}
