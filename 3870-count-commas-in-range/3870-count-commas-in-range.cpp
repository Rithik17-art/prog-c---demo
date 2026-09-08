class Solution {
public:
    int countCommas(int n) {
        int totalCommas = 0; 
        if (n >= 1000) {
            totalCommas += (n - 1000 + 1);
        }
        if (n >= 1000000) {
            totalCommas += (n - 1000000 + 1);
        }
        if (n >= 1000000000) {
            totalCommas += (n - 1000000000 + 1);
        }
        return totalCommas;
    }
};