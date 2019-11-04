std::string ans, caesarBoxCipherEncoding(std::string s) {
    int n = sqrt(s.size()),i,j;
    vector<vector<char>> c;
    int cnt = 0;
    vector<char> tmp;
    for(auto i:s)
    {
        tmp.push_back(i);
        cnt++;
        if(cnt >= n)
        {
            c.push_back(tmp);
            cnt = 0;
            tmp.clear();
        }
    }
    for(j = 0;j<n;j++)
        for(i = 0;i<n;i++)
            ans+= c[i][j];
    return ans;
}
