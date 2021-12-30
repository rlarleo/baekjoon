#include <iostream>
#include <set>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    set<string> hears;
    set<string> looks;
    set<string> result;
    int N, M;
    string name;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> name;
        hears.insert(name);
    }

    for(int i = 0; i < M; i++){
        cin >> name;
        looks.insert(name);
    }

    for(auto h : hears){
        if( looks.end() != looks.find(h) ){
            result.insert(h);
        }
    }

    cout << result.size() << '\n';
    for(auto r : result){
        cout << r << '\n';
    }

    return 0;
}
