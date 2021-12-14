#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    stack<int> myStack;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int s;
            cin >> s;
            myStack.push(s);
        }
        else if(cmd == "top"){
            if(myStack.size() == 0) cout << -1 << '\n';
            else cout << myStack.top() << '\n';
        }
        else if(cmd == "size"){
            cout << myStack.size() << '\n';
        }
        else if(cmd == "pop"){
            if(myStack.size() == 0) cout << -1 << '\n';
            else {
                cout << myStack.top() << '\n';
                myStack.pop();
            }
        }
        else if(cmd == "empty"){
            if(myStack.size() == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}
