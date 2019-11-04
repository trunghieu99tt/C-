vector<int> maximalAllowableSubarrays(std::vector<int> a, int s) {
    int i,j , n = a.size();
    long long sum[n+1];
    sum[0] = 0;
    for(i = 1;i<=n;i++)
        sum[i] = sum[i-1] + a[i-1];
    vector<int> ans;
    for(i = 1;i<=n;i++)
    {
        for(j = n;j>=1;j--)
        {
            if(sum[j] - sum[i-1] <= s)
            {
                ans.push_back(j-1);
                break;
            }
        }
    }
    return ans;
}
