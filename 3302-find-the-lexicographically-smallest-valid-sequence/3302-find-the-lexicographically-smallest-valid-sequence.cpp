class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> match(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            match[i] = match[i + 1];
            if (j >= 0 && word1[i] == word2[j]) { match[i]++; j--; }
        }
        
        vector<int> res;
        bool usedMismatch = false;
        int i = 0;
        for (int k = 0; k < m; k++) {
            while (i < n) {
                bool exact = (word1[i] == word2[k]);
                bool sub   = (!usedMismatch) && (match[i + 1] >= m - k - 1);
                if (exact || sub) {
                    res.push_back(i);
                    if (!exact) usedMismatch = true;
                    i++;
                    break;
                }
                i++;
            }
            if ((int)res.size() != k + 1) return {};
        }
        return res;
    }
};