bool isCaseInsensitivePalindrome(std::string s) {
    for (auto &i:s)
        i=tolower(i);
    auto k=s;
    reverse(k.begin(),k.end());
    return k==s;
}
