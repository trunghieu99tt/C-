int crossingSum(std::vector<std::vector<int>> matrix, int a, int b) {
    int r=matrix.size(),i,res=0,c=matrix[0].size();
    for (i=0;i<c;i++)
        res+=matrix[a][i];
    for (i=0;i<r;i++)
        res+=matrix[i][b];
    res-=matrix[a][b];
    return res;
}
