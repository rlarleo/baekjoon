#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, k, n;
    char cmd;
    cin >> T;

    for(int j = 0; j < T; j++){
        multiset<int> ms;
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> cmd;
            cin >> n;
            if(cmd == 'I'){
                ms.insert(n);
            }
            else {
                if(ms.size() > 0){
                    if(n == 1){
                        ms.erase(--ms.end());
                    }
                    else {
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if(ms.empty()) cout << "EMPTY" << '\n';
        else{
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << '\n';
        }

    }
    return 0;
}
