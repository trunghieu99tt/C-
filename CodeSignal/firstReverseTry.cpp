std::vector<int> firstReverseTry(std::vector<int> arr) {
    if(arr.size()==0) return {};
    if(arr.size()==1) return arr;
    swap(arr[0],arr[arr.size()-1]);
    return arr;
}
