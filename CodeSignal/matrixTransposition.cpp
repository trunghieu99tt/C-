typedef std::vector<std::vector<int>> vvi;
vvi matrixTransposition(vvi matrix) {

  vvi result;
  for (int i = 0; i < matrix[0].size(); i++) {
    std::vector<int> empty;
    result.push_back(empty);
    for (int j = 0; j < matrix.size(); j++) {
      result[j].push_back(matrix[j][i]);
    }
  }
  return result;
}
