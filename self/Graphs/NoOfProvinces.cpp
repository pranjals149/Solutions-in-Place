#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, int n) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1) {
                isConnected[i][j] = 0;
                isConnected[j][i] = 0;
                dfs(isConnected, j, n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (isConnected[i][i] == 1) {
                dfs(isConnected, i, n);
                count++;
            }
        }
        
        return count;
    }
};