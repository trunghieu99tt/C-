std::vector<std::vector<int>> swapDiagonals(std::vector<std::vector<int>> a) {
    int i,j,n=a.size();
    for (i=0;i<n;i++)
        swap(a[i][i],a[i][n-i-1]);
    return a;
}
