#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool isMo(char input)
{
    return input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u';
}

int main()
{
    ios_base::sync_with_stdio(false);

    while (true)
    {
        string input;
        bool flag = false;
        cin >> input;
        if (input == "end")
            break;
        cout << "<" << input << "> ";
        if (!(input.find('a') != string::npos ||
              input.find('e') != string::npos ||
              input.find('i') != string::npos ||
              input.find('o') != string::npos ||
              input.find('u') != string::npos))

        {
            cout << "is not acceptable." << '\n';
            continue;
        }
        else
        {
            stack<bool> s;
            for (int i = 0; i < input.size(); i++)
            {
                bool isM = isMo(input[i]);
                if (s.empty())
                    s.push(isM);
                else
                {
                    if (s.top() == isM)
                        s.push(isM);
                    else
                    {
                        while (!s.empty())
                        {
                            s.pop();
                        }
                        s.push(isM);
                    }
                }
                if (s.size() == 3)
                {
                    cout << "is not acceptable." << '\n';
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                for (int i = 1; i < input.size(); i++)
                {
                    if (input[i] == 'e' || input[i] == 'o')
                        continue;
                    if (input[i - 1] == input[i])
                    {
                        cout << "is not acceptable." << '\n';
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag)
                cout << "is acceptable." << '\n';
        }
    }

    return 0;
}
