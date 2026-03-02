#include <iostream>
#include <map>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> goals;
    string winningTeam;
    int maxGoals = 0;
    
    for (int i = 0; i < n; i++) {
        string team;
        cin >> team;
        goals[team]++;
        
        if (goals[team] > maxGoals) {
            maxGoals = goals[team];
            winningTeam = team;
        }
    }
    
    cout << winningTeam << endl;
    
    return 0;
}
