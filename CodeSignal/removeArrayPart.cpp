std::vector<int> removeArrayPart(std::vector<int> inputArray, int l, int r) {
    inputArray.erase(begin(inputArray) + l, begin(inputArray) + r + 1);
    return inputArray;
}
