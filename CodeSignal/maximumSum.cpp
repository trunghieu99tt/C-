int maximumSum(std::vector<int> a, std::vector<std::vector<int>> q) {
    int sum=-1,n=q.size();
    sort(a.begin(),a.end());
    do{
        int temp=0,i,j;
        for (i=0;i<n;i++)
        {
            for (j=q[i][0];j<=q[i][1];j++)
                temp+=a[j];
         }
        sum=max(temp,sum);
    }
    while(next_permutation(a.begin(),a.end()));
    return sum;
}
