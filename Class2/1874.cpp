#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    vector<char> result;
    int cnt = 1;
    stack<int> s;
    bool flag = true;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        for(int j = cnt; j <= num; j++){
            s.push(j);
            cnt++;
            result.push_back('+');
        }
        if(s.top() == num){
            s.pop();
            result.push_back('-');
        }
        else{
            cout << "NO\n";
            return 0;
        }

    }
    for(auto r : result){
        cout << r << '\n';
    }

    return 0;
}
