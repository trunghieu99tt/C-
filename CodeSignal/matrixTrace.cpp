int matrixTrace(std::vector<std::vector<int>> matrix) {
    int res = 0;
    for(int i = 0; i < matrix.size();++i)
        res += matrix[i][i];
    return res;
}
