std::vector<int> fractionReducing(std::vector<int> a) {
    int k=__gcd(a[0],a[1]);
    return std::vector<int>{a[0]/k,a[1]/k};
}
