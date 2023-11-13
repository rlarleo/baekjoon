#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);


    int n, sum = 0;
    cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}

    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int input = 0;
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    int cutCount = round((double)((vec.size() * 0.15)));
    int result = 0;
    for(int i = cutCount; i < vec.size() - cutCount; i++){
        result += vec[i];
    }

    cout << round((double)result / (vec.size() - (cutCount*2)));


    return 0;
}
