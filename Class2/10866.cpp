#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    deque<int> myDeque;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push_front"){
            int s;
            cin >> s;
            myDeque.push_front(s);
        }
        if(cmd == "push_back"){
            int s;
            cin >> s;
            myDeque.push_back(s);
        }
        else if(cmd == "pop_front"){
            if(myDeque.size() == 0) cout << -1 << '\n';
            else {
                cout << myDeque.front() << '\n';
                myDeque.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(myDeque.size() == 0) cout << -1 << '\n';
            else {
                cout << myDeque.back() << '\n';
                myDeque.pop_back();
            }
        }
        else if(cmd == "size"){
            cout << myDeque.size() << '\n';
        }
        else if(cmd == "empty"){
            if(myDeque.size() == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd == "front"){
            if(myDeque.size() == 0) cout << -1 << '\n';
            else cout << myDeque.front() << '\n';
        }
        else if(cmd == "back"){
            if(myDeque.size() == 0) cout << -1 << '\n';
            else cout << myDeque.back() << '\n';
        }
    }

    return 0;
}
