#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int myIndex = 0;


int GetIndex(int index,  char person, vector<pair<int, char>> people){
    for(auto p : people){
        if(person == p.second)
            return p.first;
    }
    myIndex++;
    return myIndex;
}

int DiffLastIndex(char person, int currIndex, string people){
    for(int i = people.size() - 1; i > 0; i--){
        if(people[i] == person) return i - currIndex;
    }
    return 0;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, N;
    string input;
    cin >> T;
    for(int t = 0; t < T; t++){
        myIndex = 0;
        cin >> N;
        cin >> input;
        int result = 0;
        vector<pair<int, char>> people;
        for(int i = 0; i < N; i++){
            int currIdx = GetIndex(myIndex, input[i], people);
            pair<int, char> person = {currIdx, input[i]};
            people.push_back(person);
        }
        sort(people.begin(), people.end());
        
        for(int i = 0; i < N; i++){
            int count = 1;
            int plusI = 0;
            for(int j = i+1; j <= N; j++){
                if(j == N){
                    i += plusI;
                    break;
                }
                if(people[i].first != people[j].first) {
                    i += plusI;
                    break;
                }
                else {
                    count++;
                    plusI++;
                }
             
            }
            result += (count * DiffLastIndex(people[i].second, i, input));
        }

        cout << result*5 << endl;
    }



    return 0;
}
