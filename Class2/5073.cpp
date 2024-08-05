#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    while (true)
    {
        vector<int> vec;
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        else if (a == b && b == c)
            cout << "Equilateral" << '\n';
        else if (a == b || b == c || a == c)
        {
            vec.push_back(a);
            vec.push_back(b);
            vec.push_back(c);
            sort(vec.begin(), vec.end());
            if ((vec[0] + vec[1]) <= vec[2])
                cout << "Invalid" << '\n';
            else
                cout << "Isosceles" << '\n';
        }
        else
        {
            vec.push_back(a);
            vec.push_back(b);
            vec.push_back(c);
            sort(vec.begin(), vec.end());
            if ((vec[0] + vec[1]) <= vec[2])
                cout << "Invalid" << '\n';
            else
                cout << "Scalene" << '\n';
        }
    }
}
