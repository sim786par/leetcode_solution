class Solution {
private:
    const long long MAX_LIMIT = 1e16; // Safe upper bound to prevent overflow

    // Computes nCr safely with an early overflow cap
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r; // Optimize calculations

        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            // Prevent overflow during multiplication
            if (res > MAX_LIMIT / (n - i + 1)) return MAX_LIMIT;
            res = res * (n - i + 1) / i;
        }
        return res;
    }
    // Calculates total unique multiset permutations based on remaining frequencies
    long long countWays(const vector<int>& freq) {
        int total = 0;
        for (int count : freq) total += count;

        long long ways = 1;
        int remaining = total;
        for (int count : freq) {
            if (count > 0) {
                long long combinations = nCr(remaining, count);
                // Prevent overflow when multiplying multinomial stages
                if (ways > MAX_LIMIT / combinations) return MAX_LIMIT;
                ways *= combinations;
                remaining -= count;
            }
        }
        return ways;
    }
public:
    string smallestPalindrome(string s, int k) {
        vector<int> fullFreq(26, 0);
        for (char c : s) fullFreq[c - 'a']++;

        // Step 1: Validate palindrome feasibility and extract structural halves
        int oddCount = 0;
        int midIdx = -1;
        vector<int> halfFreq(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (fullFreq[i] % 2 != 0) {
                oddCount++;
                midIdx = i;
            }
            halfFreq[i] = fullFreq[i] / 2;
        }

        // A palindrome is impossible if more than one character has an odd frequency
        if (oddCount > 1) return "";
        // Verify if total valid combinations are even enough to satisfy k
        long long totalPermutations = countWays(halfFreq);
        if (k > totalPermutations) return "";

        int halfLen = 0;
        for (int count : halfFreq) halfLen += count;

        string leftHalf = "";

        // Step 2: Greedily build the left half position by position
        for (int pos = 0; pos < halfLen; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (halfFreq[i] == 0) continue;

                // Tentatively place character i
                halfFreq[i]--;
                long long options = countWays(halfFreq);

                if (options >= k) {
                    // This character is the correct match for the current position
                    leftHalf += (char)('a' + i);
                    break; // Move to the next position placeholder
                } else {
                    // Skip all permutations starting with this character
                    k -= options;
                    halfFreq[i]++; // Backtrack and try next character
                }
            }
        }

        // Step 3: Reconstruct the full string
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        if (midIdx != -1) {
            char midChar = (char)('a' + midIdx);
            return leftHalf + midChar + rightHalf;
        }
        
        return leftHalf + rightHalf;
    }
};