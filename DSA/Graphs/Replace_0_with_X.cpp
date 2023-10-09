#include <vector>

void dfs(int row, int col, vector<vector<int>> &vis, 
    char **mat, int delrow[], int delcol[]) {
        vis[row][col] = 1; 
        int n = vis.size();
        int m = vis[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol); 
            }
        }
    }

void replaceOWithX(char** arr, int n, int  m)
{
    if(n <=2 or m <= 2) return;
    vector<vector<int>> vis(n, vector<int>(m,0));
    int delrow[] = { -1, 0, 1, 0 };
    int delcol[] = { 0, 1, 0, -1 };

    // traverse frist and last row;
    for(int i = 0; i < m; i++){
        if(!vis[0][i] && arr[0][i] == 'O'){
            vis[0][i] = 1;
            dfs(0, i, vis, arr, delrow, delcol);
        }

        if(!vis[n-1][i] && arr[n-1][i] == 'O'){
            vis[n-1][i] = 0;
            dfs(n-1, i, vis, arr, delrow, delcol);
        }
    }

    // traverse for first and last col
    for(int i = 0; i < n; i++){
        if(!vis[i][0] && arr[i][0] == 'O'){
            vis[i][0] = 1;
            dfs(i, 0, vis, arr, delrow, delcol);
        }

        if(!vis[i][m-1] && arr[i][m-1] == 'O'){
            vis[i][m-1]=1;
            dfs(i, m-1, vis, arr, delrow, delcol);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] and arr[i][j] == 'O'){
                arr[i][j] = 'X';
            }
        }
    }
}
