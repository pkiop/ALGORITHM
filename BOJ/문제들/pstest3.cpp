#include <iostream>
#include <sstream>

using namespace std;
bool isNumber(char x)
{
  return '0' <= x && x <= '9';
}

string answer(string input, string pushHead)
{
  string ret = "";

  for (int i = 0; i < input.size(); ++i)
  {
    if (isNumber(input[i]))
    {
      int nowIdx = i;
      if (input[i + 1] == '(')
      {
        string push = "";
        int cnt = 1;
        for (int j = i + 2;; ++j)
        {
          if (input[j] == ')')
          {
            cnt--;
          }
          if (input[j] == '(')
          {
            cnt++;
          }
          if (cnt == 0)
          {
            i = j;
            break;
          }
          push += input[j];
        }
        string temp = answer(push, "X");
        for (int j = 0; j < input[nowIdx] - '0'; ++j)
        {
          if (pushHead != "X")
          {
            ret += pushHead;
          }
          ret += temp;
        }
      }
      else
      { // 숫자 뒤는 ( or 문자만 온다. 여긴 문자.
        for (int j = 0; j < input[i] - '0'; ++j)
        {
          if (pushHead != "X")
          {
            ret += pushHead;
          }
          ret += input[i + 1];
        }
        i = i + 1;
      }
    }
    else
    {
      if (input[i + 1] == '(')
      {
        int nowIdx = i;
        string push = "";
        int cnt = 1;
        for (int j = i + 2;; ++j)
        {
          if (input[j] == ')')
          {
            cnt--;
          }
          if (input[j] == '(')
          {
            cnt++;
          }
          if (cnt == 0)
          {
            i = j;
            break;
          }
          push += input[j];
        }
        string pushHead2 = "";
        if(pushHead == "X") {
          pushHead2 += input[nowIdx];
        } else {
          pushHead2 += pushHead + input[nowIdx];
        }
        ret += answer(push, pushHead2);
      }
      else
      {
        if (pushHead != "X")
        {
          ret += pushHead;
        }
        ret += input[i];
      }
    }
  }
  return ret;
}

void solution(int numOfOrder, string *orderArr)
{
  for (int i = 0; i < numOfOrder; ++i)
  {
    cout << answer(orderArr[i], "X") << endl;
  }
}

