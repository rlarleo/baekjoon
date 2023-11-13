#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string input;
    int index;

    cin >> input;
    cin >> index;

    cout << input[index-1];

    return 0;
}
