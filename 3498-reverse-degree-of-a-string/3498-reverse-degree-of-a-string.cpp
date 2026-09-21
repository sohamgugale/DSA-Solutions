#include <string>

class Solution {
public:
    int reverseDegree(std::string s) {
        int totalDegree = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Position in string is 1-indexed (i + 1)
            int stringPos = i + 1;
            
            // Reversed alphabet value ('a' -> 26, 'b' -> 25, ..., 'z' -> 1)
            int reversedAlphaVal = 'z' - s[i] + 1;
            
            totalDegree += reversedAlphaVal * stringPos;
        }
        
        return totalDegree;
    }
};