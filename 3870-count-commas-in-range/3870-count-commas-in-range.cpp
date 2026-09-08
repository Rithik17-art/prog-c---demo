class Solution {
public:
    int countCommas(int n) {
        int totalCommas = 0;
        
        // Every number >= 1,000 adds 1 comma
        if (n >= 1000) {
            totalCommas += (n - 1000 + 1);
        }
        // Every number >= 1,000,000 adds a 2nd comma
        if (n >= 1000000) {
            totalCommas += (n - 1000000 + 1);
        }
        // Every number >= 1,000,000,000 adds a 3rd comma
        if (n >= 1000000000) {
            totalCommas += (n - 1000000000 + 1);
        }
        
        return totalCommas;
    }
};