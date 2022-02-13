#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    map<string, string> map;
    string site, pw;
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> site >> pw;
        map.insert({site, pw});
    }
    for(int i = 0; i < M; i++){
        cin >> site;
        auto it = map.find(site);
        cout << (*it).second << endl;

    }

    return 0;
}
