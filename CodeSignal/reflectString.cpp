string reflectString(string s) {
    map<char,char> r;
    char t='a',b='z';
    for(int i=0;i<=25;i++)
        r.insert(make_pair(t++,b--));
    for(auto &i:s)
        i=r[i];
    return s;
}
