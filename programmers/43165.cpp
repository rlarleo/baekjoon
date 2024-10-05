#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int curr, int index)
{
    if (index == numbers.size())
    {
        if (curr == target)
        {
            answer++;
        }
        return;
    }
    dfs(numbers, target, curr - numbers[index], index + 1);
    dfs(numbers, target, curr + numbers[index], index + 1);
}

int solution(vector<int> numbers, int target)
{

    dfs(numbers, target, 0, 0);
    return answer;
}