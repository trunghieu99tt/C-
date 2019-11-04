int arrayElementsProduct(std::vector<int> a) {
    int ans = 1;
    for(auto i:a)
        ans*=i;
    return ans;
}
