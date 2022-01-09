#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int i = 0;
    while(true){
        stack<char> s;
        string words;
        getline(cin, words);
        bool flag = false;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == '[' || words[i] == '('){
                s.push(words[i]);
            } else if(words[i] == ']'){
                if(s.size() != 0 && (s.top() == '[' || s.top() == ')')) s.pop();
                else {
                    flag = true;
                    break;
                }
            } else if(words[i] == ')'){
                if(s.size() != 0 && (s.top() == '(' || s.top() == ']') ) s.pop();
                else {
                    flag = true;
                    break;
                }
            }
        }
        if(words == ".") break;
        if(flag || s.size() != 0) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }


    return 0;
}
