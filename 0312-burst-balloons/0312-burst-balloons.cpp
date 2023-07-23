class Solution {
public:
    int f(int i, int j, vector<int>& a, vector<vector<int>>& dp)
{
	if (i > j) return 0;
	if (dp[i][j]!= -1) return dp[i][j];
	int ans = INT_MIN;
	for (int k = i; k <= j; k++)
	{
		int cost = a[i-1]*a[k]*a[j+1] + f(i, k-1, a, dp) + f(k+1, j, a, dp);
		ans = max(ans, cost);
	}
	return dp[i][j] = ans;
}
int maxCoins(vector<int>& a)
{
	// Write your code here.
	int N = a.size();
	a.push_back(1);
	a.insert(a.begin(),1);
	vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
	return f(1,N,a, dp);
}
};