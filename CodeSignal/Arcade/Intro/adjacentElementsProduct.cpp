int adjacentElementsProduct(std::vector<int> inputArray) {
    int maxproduct=inputArray[0]*inputArray[1];
    for (int i=1;i<inputArray.size()-1;i++)
        maxproduct=max(maxproduct,inputArray[i]*inputArray[i+1]);
    return maxproduct;
}
