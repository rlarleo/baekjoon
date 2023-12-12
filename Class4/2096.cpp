#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int preMaxR1;
int preMaxR2;
int preMaxR3;
int preMinR1;
int preMinR2;
int preMinR3;
int maxR1;
int maxR2;
int maxR3;
int minR1;
int minR2;
int minR3;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N;
    
    int a1, a2, a3;
    
    cin >> N;
    cin >> a1 >> a2 >> a3;
    preMaxR1 = (a1);
    preMaxR2 = (a2);
    preMaxR3 = (a3);
    preMinR1 = (a1);
    preMinR2 = (a2);
    preMinR3 = (a3);
    maxR1 = (a1);
    maxR2 = (a2);
    maxR3 = (a3);
    minR1 = (a1);
    minR2 = (a2);
    minR3 = (a3);


    for(int i = 1; i < N; i++){
        cin >> a1 >> a2 >> a3;       
        maxR1 = (max(preMaxR1, preMaxR2) + a1);
        maxR2 = (max(max(preMaxR1, preMaxR2), preMaxR3) + a2);
        maxR3 = (max(preMaxR2, preMaxR3) + a3);

        minR1 = (min(preMinR1, preMinR2) + a1);
        minR2 = (min(min(preMinR1, preMinR2), preMinR3) + a2);
        minR3 = (min(preMinR2, preMinR3) + a3);

        preMaxR1 = maxR1;
        preMaxR2 = maxR2;
        preMaxR3 = maxR3;
        preMinR1 = minR1;
        preMinR2 = minR2;
        preMinR3 = minR3;
    }

    cout << max(max(maxR1, maxR2), maxR3);
    cout << ' ';
    cout << min(min(minR1, minR2), minR3);
    
    return 0;
}