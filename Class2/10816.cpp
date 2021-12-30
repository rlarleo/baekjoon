#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;

int LowerBound(int start, int end, int key){
    int mid = -1;
    while(end > start){
        mid = (start + end) / 2;
        if(card[mid] >= key){
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }

    return end;
}

int UpperBound(int start, int end, int key){
    int mid = -1;
    while(end > start){
        mid = (start + end) / 2;
        if(card[mid] > key){
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return end;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	vector<int> result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		card.push_back(c);
	}
	sort(card.begin(), card.end());
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
        int key;
        cin >> key;
        int upper = UpperBound(0, card.size()-1, key);
        int lower = LowerBound(0, card.size()-1, key);
        if (upper == card.size() - 1 && card[n - 1] == key)
            upper++;
        int result = upper - lower;
        cout << result << ' ';
	}

}
