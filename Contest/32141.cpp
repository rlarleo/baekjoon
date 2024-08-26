#include <iostream>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    
    int N, H;
    bool isDie = false;
    int useCard = 0;
    cin >> N >> H;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        H -= input;
        if(!isDie && H <= 0){
            isDie = true;
            useCard = i + 1;
        }
    }

    if(!isDie) cout << -1;
    else cout << useCard;

    return 0;

}
