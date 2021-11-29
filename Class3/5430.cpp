#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<string> vec;
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++){
        string func, arr, temp = "";
        int n;
        cin >> func >> n >> arr;

        int numOfD = 0;
        for(int j = 0; j < func.length(); j++){
            if(func[j] == 'D') numOfD ++;
        }
        if(numOfD > n) {
            cout << "error" << '\n';
        }
        else if(n == 0) {
            cout << "[]" << '\n';
        }
        else {
            bool R = true;
            deque<int> d;

            for(int j = 1; j < arr.length(); j++){
                if(arr[j] == ',' || arr[j] == ']') {
                    d.push_back(stoi(temp));
                    temp = "";
                }
                else temp = temp + arr[j];
            }

            for(int j = 0; j < func.length(); j++){
                if(func[j] == 'R'){
                    if(R) R = false;
                    else R = true;
                }
                else{
                    if(R){
                        d.pop_front();
                    }
                    else{
                        d.pop_back();
                    }
                }
            }
            cout << '[';

            if(R){
                for(auto deque : d){
                    if(d.size() == 1)
                        cout << to_string(d.front());
                    else
                        cout << to_string(d.front()) + ',';
                    d.pop_front();
                }
            }
            else{
                for(auto deque : d){
                    if(d.size() == 1)
                        cout << to_string(d.back());
                    else
                        cout << to_string(d.back()) + ',';
                    d.pop_back();
                }
            }
            cout << "]\n";
        }
    }


    return 0;
}
