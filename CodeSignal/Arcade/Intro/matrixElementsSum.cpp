int matrixElementsSum(std::vector<std::vector<int>> matrix) {
    int i,j,r=matrix.size(),c=matrix[0].size();
    int a[r][c]={1},sum=0,k;
    for (j=0;j<c;j++)
        for(i=0;i<r;i++) 
            if(matrix[i][j]==0)
        {
            for (k=i;k<r;k++) a[k][j]=0;
        }
    for (i=0;i<r;i++)
        for (j=0;j<c;j++) if(a[i][j]==1) sum+=matrix[i][j];
    return sum;
}
