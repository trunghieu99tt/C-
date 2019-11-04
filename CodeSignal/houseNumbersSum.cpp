int houseNumbersSum(std::vector<int> inputArray) {
    int res=0;
    for(auto i:inputArray)
        if(i!=0 ) res+=i;
        else break;
    return res;
}
