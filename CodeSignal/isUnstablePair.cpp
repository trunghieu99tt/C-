bool isUnstablePair(std::string s1, std::string s2) {
    auto k1=s1,k2=s2;
    for (auto &a:s1) a=tolower(a);
    for (auto &a:s2) a=tolower(a);
    return (k1<k2)!=(s1<s2);
}
