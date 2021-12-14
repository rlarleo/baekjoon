#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    queue<int> myQueue;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int s;
            cin >> s;
            myQueue.push(s);
        }
        else if(cmd == "front"){
            if(myQueue.size() == 0) cout << -1 << '\n';
            else cout << myQueue.front() << '\n';
        }
        else if(cmd == "back"){
            if(myQueue.size() == 0) cout << -1 << '\n';
            else cout << myQueue.back() << '\n';
        }
        else if(cmd == "size"){
            cout << myQueue.size() << '\n';
        }
        else if(cmd == "pop"){
            if(myQueue.size() == 0) cout << -1 << '\n';
            else {
                cout << myQueue.front() << '\n';
                myQueue.pop();
            }
        }
        else if(cmd == "empty"){
            if(myQueue.size() == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}
