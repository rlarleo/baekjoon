#include <string>
#include <vector>
#include <iostream>

using namespace std;

string time_to_string(int time)
{
    if (time < 10)
        return "0" + to_string(time);
    return to_string(time);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    string answer = "";
    string curr = "";
    int mm = stoi(pos.substr(0, 2));
    int ss = stoi(pos.substr(3, 2));
    int video_len_mm = stoi(video_len.substr(0, 2));
    int video_len_ss = stoi(video_len.substr(3, 2));
    int op_start_mm = stoi(op_start.substr(0, 2));
    int op_start_ss = stoi(op_start.substr(3, 2));
    int op_end_mm = stoi(op_end.substr(0, 2));
    int op_end_ss = stoi(op_end.substr(3, 2));
    curr = time_to_string(mm) + ":" + time_to_string(ss);
    if (curr <= op_end && curr >= op_start)
    {
        mm = op_end_mm;
        ss = op_end_ss;
    }

    for (auto cmd : commands)
    {
        if (cmd == "prev")
        {
            if (ss < 10)
            {
                mm = mm - 1;
                ss = ss + 50;
            }
            else
            {
                ss = ss - 10;
            }
            if (mm < 0)
            {
                mm = 0;
                ss = 0;
            }
            curr = time_to_string(mm) + ":" + time_to_string(ss);
            if (curr <= op_end && curr >= op_start)
            {
                mm = op_end_mm;
                ss = op_end_ss;
            }
        }
        else if (cmd == "next")
        {
            if (ss >= 50)
            {
                mm = mm + 1;
                ss = ss - 50;
            }
            else
            {
                ss = ss + 10;
            }
            if (video_len_mm < mm || (video_len_mm == mm && video_len_ss < ss))
            {
                mm = video_len_mm;
                ss = video_len_ss;
            }
            curr = time_to_string(mm) + ":" + time_to_string(ss);
            if (curr <= op_end && curr >= op_start)
            {
                mm = op_end_mm;
                ss = op_end_ss;
            }
        }
    }
    return time_to_string(mm) + ":" + time_to_string(ss);
}