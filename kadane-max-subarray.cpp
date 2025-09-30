int maxSubArray(vector<int>& nums) {
    const int n = nums.size();
    // dp[i] = maximum sum ending at i-th index.
    vector<int> dp(n, 0);
    int finalAns;
    finalAns = dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        finalAns = max(finalAns, dp[i]);
    }
    return finalAns;
}
