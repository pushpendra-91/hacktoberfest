#include <bits/stdc++.h>
using namespace std;
// Backtracking is revert the changes that you have made for the next function call back to its original state
void mazeWithObstacles(vector<vector<bool>> &mat, vector<string> &ans, string x, int row, int col)
{
    if (row == mat.size() - 1 and col == mat[0].size() - 1)
    {
        ans.push_back(x);
        return;
    }
    if (!mat[row][col])
        return;

    mat[row][col] = false; // this will avoid infinite recursion calls
    // bcoz we have marked it as visited so when next 4 calls run it will not visit this path again

    if (row < mat.size() - 1)
        mazeWithObstacles(mat, ans, x + 'D', row + 1, col); // going down
    if (col < mat[0].size() - 1)
        mazeWithObstacles(mat, ans, x + 'R', row, col + 1); // going right
    if (col > 0)
        mazeWithObstacles(mat, ans, x + 'L', row, col - 1); // going left
    if (row > 0)
        mazeWithObstacles(mat, ans, x + 'U', row - 1, col); // going up

    mat[row][col] = true; // reverting changes back to its original state
    return;
}
int main()
{
    vector<vector<bool>> mat = {{true, true, true}, {true, true, true}, {true, true, true}};
    vector<vector<int>> path(mat.size(), vector<int>(mat[0].size(), 0));
    vector<string> ans;
    mazeWithObstacles(mat, ans, "", 0, 0); // going top to bottom
    for (auto i : ans)
        cout << i << endl;
    return 0;
}