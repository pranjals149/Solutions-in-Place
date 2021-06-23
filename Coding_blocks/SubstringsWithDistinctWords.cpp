class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        
        int a = s[0];
        int b = s[1];
        int c = s[2];
        
        for (int i = 3; i <= s.length()-1; i++) {
            if (a != b and b != c and c != a) {
                count++;
            }
            a = b;
            b = c;
            c = s[i];
        }
        
        if (a != b and b != c and c != a) {
            count++;
        }
        
        return count;
    };
    
};