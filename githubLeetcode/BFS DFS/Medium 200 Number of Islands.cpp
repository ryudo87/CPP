//这道求岛屿数量的题的本质是求矩阵中连续区域的个数，很容易想到需要用深度优先搜索 DFS 来解
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        unsigned m = grid.size(), n = grid[0].size();
        
        int cnt = 0;
        for (unsigned i=0;i<m;++i) {
            for (unsigned j=0;j<n;++j) {
                if (grid[i][j] == '1') {
                    markIslands(grid, i, j);//DFS, mark (i, j)  '2' as visited
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
    
    void markIslands(vector<vector<char>>& grid, int x, int y) {
        unsigned m = grid.size(), n = grid[0].size();
        if (x<0 || x>=m || y<0 || y>= n) return;
        if (grid[x][y] != '1') return;
        
        grid[x][y] = '2';//visited land
        
        //visit adjacent grid, mark as '2' for '1'
        markIslands(grid, x-1, y);
        markIslands(grid, x+1, y);
        markIslands(grid, x, y-1);
        markIslands(grid, x, y+1);
    }
    
    
};


https://www.cnblogs.com/grandyang/p/4402656.html
