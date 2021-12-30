#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, int> poketmons;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    int num;
    string poketmon;
    cin >> N >> M;
    vector<string> vec;

    for(int i = 1; i <= N; i++){
        cin >> poketmon;
        poketmons.insert(make_pair(poketmon, i));
        vec.push_back(poketmon);
    }

    for(int i = 0; i < M; i++){
        cin >> poketmon;
        if(isdigit(poketmon[0]) == true){
            int num = stoi(poketmon);
            cout << vec[num-1] << '\n';
        }
        else{
            cout << poketmons.find(poketmon)->second << '\n';
        }
    }
    return 0;
}
