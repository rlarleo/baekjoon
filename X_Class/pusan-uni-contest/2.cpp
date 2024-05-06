#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    vector<int> books;
    cin >> N;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        books.push_back(input);
    }
    sort(books.begin(), books.end());

    int currFirst = 0;
    int result = 0;
    for(auto book : books){
        if(book >= currFirst * 2){
            result++;
            currFirst = book;
        }
    }
    cout << result;
}
