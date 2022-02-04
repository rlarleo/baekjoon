#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<int> s, reset;
    int n, x;
    cin >> n;
    string cmd;
    set<int>::iterator iter;

    for(int i = 0; i<= 20; i++) reset.insert(i);

    for(int i = 0; i < n; i++){
        cin >> cmd;
        if(cmd == "add"){
            cin >> x;
            if(s.find(x) == s.end()){
                s.insert(x);
            }
        }
        else if(cmd == "remove"){
            cin >> x;
            iter = s.find(x);
            if(iter != s.end()){
                s.erase(*iter);
            }
        }
        else if(cmd == "check"){
            cin >> x;
            iter = s.find(x);
            if(iter != s.end()){
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        else if(cmd == "toggle"){
            cin >> x;
            iter = s.find(x);
            if(iter == s.end()){
                s.insert(x);
            } else {
                s.erase(*iter);
            }
        }
        else if(cmd == "all"){
            s = reset;
        }
        else if(cmd == "empty"){
            s.clear();
        }
    }

    return 0;
}
