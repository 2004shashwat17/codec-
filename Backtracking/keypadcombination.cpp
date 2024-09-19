#include <iostream>
#include <string>
#include <vector>
using namespace std;
void bfs(int pos, int len, string ans, string Dig, vector<vector<char>> L)
{
    if (pos == len)
    {
        cout << ans << endl;
    }
    else
    {
        vector<char> letters = L[Dig[pos] - '0'];
        for (int i = 0; i < letters.size(); i++)
            bfs(pos + 1, len, ans + letters[i], Dig, L);
    }
}
void letterCombinations(string Dig, vector<vector<char>> L)
{
    int len = Dig.size();
    if (len == 0)
    {
        cout << "";
        return;
    }
    string ans = "";
    bfs(0, len, ans, Dig, L);
}
int main()
{
    vector<vector<char>> L = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
     {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
      {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    string digits = "23";
    letterCombinations(digits, L);
}
