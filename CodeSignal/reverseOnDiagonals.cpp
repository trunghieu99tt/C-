std::vector<std::vector<int>> reverseOnDiagonals(std::vector<std::vector<int>> matrix) {
    int n=matrix.size(),i,j;
    if(n==1) return matrix;
    for(i=0;i<n/2;i++)
        for(j=0;j<n;j++)
            if(i==j) swap(matrix[i][j],matrix[n-1-i][n-1-j]);
            else if(i==n-j-1) swap(matrix[i][j],matrix[n-i-1][n-1-j]);
    return matrix;
}
