#include <iostream>
using namespace std;

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    
    int col, row;
    
    if(h%(n+1) != 0)    col = (h/(n+1)) + 1;
    else    col = (h/(n+1));
    if((w%(m+1)) != 0)    row = (w/(m+1)) + 1;
    else    row = (w/(m+1));
    
    cout << col * row;

    return 0;
}