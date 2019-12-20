#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int make_loc(int i, int j) {
        return 1000 * i + j;
    }

    void dfs(vector<vector<int>>& matrix, int i, int j, unordered_set<int> &mine, unordered_set<int> &peer) {
        int loc = make_loc(i, j);
        int h = matrix[i][j];

        if (mine.count(loc) > 0)
            return;
        mine.insert(loc);

        if (peer.count(loc) > 0)
            ans.push_back({i, j});

        if (i && h <= matrix[i-1][j])
            dfs(matrix, i-1, j, mine, peer);

        if (j && h <= matrix[i][j-1])
            dfs(matrix, i, j-1, mine, peer);

        if (i < matrix.size()-1 && h <= matrix[i+1][j])
            dfs(matrix, i+1, j, mine, peer);

        if (j < matrix[0].size()-1 && h <= matrix[i][j+1])
            dfs(matrix, i, j+1, mine, peer);
    }

    vector<vector<int>> ans;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        unordered_set<int> pacific, atlantic;

        if (!matrix.size() || !matrix[0].size())
            return ans;

        for (int i = 0; i < matrix.size(); i ++)
            dfs(matrix, i, 0, pacific, atlantic);

        for (int i = 0; i < matrix[0].size(); i ++)
            dfs(matrix, 0, i, pacific, atlantic);

        for (int i = 0; i < matrix.size(); i ++)
            dfs(matrix, i, matrix[0].size()-1, atlantic, pacific);

        for (int i = 0; i < matrix[0].size(); i ++)
            dfs(matrix, matrix.size()-1, i, atlantic, pacific);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> matrix, ans;
    vector<int> row;
    int row_sz = atoi(argv[1]);
    int n;

    while (cin >> n) {
        row.push_back(n);
        if (row.size() == row_sz) {
            matrix.push_back(row);
            row.clear();
        }
    }

    ans = solution.pacificAtlantic(matrix);

    for (auto &r : ans) {
        for (auto e : r)
            cout << e << " ";
        cout << endl;
    }
    
    return 0;
}
