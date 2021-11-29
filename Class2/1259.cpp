#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        string s = to_string(n);
        bool result = true;
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()-1-i]) {
                result = false;
            }
        }
        result? cout << "yes" << '\n' : cout << "no" << '\n';

    }

    return 0;
}
