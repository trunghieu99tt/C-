bool isSkewSymmetricMatrix(std::vector<std::vector<int>> matrix) {
    int i,j;
    for (i=0;i<matrix.size();i++)
    {
        for (j=0;j<matrix[0].size();j++)
          if(matrix[i][j]!=-matrix[j][i]) return false;
    }
    return true;
}