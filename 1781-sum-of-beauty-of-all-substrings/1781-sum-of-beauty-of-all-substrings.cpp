class Solution {
public:
    int beautySum(string s) {
		// Variable to store answer
        int ans = 0;
		// Size of the string
        int n = s.size();
		// Loop for left index of the substring
        for(int i=0; i<n; i++) {
			// Counter to store frequency of letters in substring
            int cnt[26] = {};
			// Initialise min and max frequency
            int max_f = INT_MIN;
            int min_f = INT_MAX;
			// Loop for right index of substring
            for(int j=i; j<n; j++) {
				// Get index of alphabet
                int ind = s[j] - 'a';
				// Increment frequency of that index
                cnt[ind]++;
				// The max frquency will be the maximum of the current max frquency and count of current index.
				// This is because that was the only value that was incremented in this run.
                max_f = max(max_f, cnt[ind]);
				// The maximum value of min frequency is the count of the current index
				// This is used for initialisation of min_f varaiable
                min_f = cnt[ind];
				// Loop across all alphabets to get the min frequency
                for(int k=0; k<26; k++) {
					// We want to consider the non-zero minimum, i.e. the letter should exist in the substring
                    if(cnt[k] >= 1)
                        min_f = min(min_f, cnt[k]);
                }
				// Increment answer by difference of max_f and min_f
                ans += (max_f - min_f);
            }
        }
        return ans;
    }
};