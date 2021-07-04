#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp = {0, 1, 1, 1, 1, 1};
        
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= 5; i++) {
                dp[i] = dp[i] + dp[i-1];
            }
        }
        
        return dp[5];
    }
};