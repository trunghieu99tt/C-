bool isPangram(std::string s) {
    map<char,int> cnt;
    for(auto i:s)
    {
        i = tolower(i);
        cnt[i]++;
    }
    for(char c = 'a';c<='z';c++)
        if(!cnt[c])
            return 0;
    return 1;
}
