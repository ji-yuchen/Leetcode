/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int numFresh = 0;
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if (grid[i][j]==1){
                    numFresh++;
                }
            }
        }
        while(!q.empty() && numFresh > 0){
            int size = q.size();
            res++;
            while(size != 0){
                pair<int, int> pos = q.front();
                q.pop();
                size--;
                bfs(grid, q, pos.first-1, pos.second, numFresh);
                bfs(grid, q, pos.first+1, pos.second, numFresh);
                bfs(grid, q, pos.first, pos.second-1, numFresh);
                bfs(grid, q, pos.first, pos.second+1, numFresh);
            }
        }
        if(numFresh == 0){
            return res;
        }
        else{
            return -1;
        }
    }
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int x, int y, int& numFresh){
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1){
            q.push({x, y});
            grid[x][y] = 2;
            numFresh--;
        }
    }
};
