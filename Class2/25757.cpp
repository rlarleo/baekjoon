#include <iostream>
#include <set>
#include <queue>
#include <cmath>
#include <stdlib.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    set<string> s;
    string Game, name;
    int N, game = 3;
    cin >> N >> Game;
    
    if(Game == "Y"){
        game = 1;
    }
    else if(Game == "F"){
        game = 2;
    }

    for(int i = 0 ; i < N; i ++){
        cin >> name;
        s.insert(name);
    }

    cout << s.size() / game;
}
