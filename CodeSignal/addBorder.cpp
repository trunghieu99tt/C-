std::vector<std::string> addBorder(std::vector<std::string> picture) {
    vector<std::string> result;
    int i,n=picture[0].size();
    string s="";
    for (i=0;i<n+2;i++) s+='*';
     result.push_back(s);
    for (i=0;i<picture.size();i++)
    {
        string k="";
        k='*'+picture[i]+'*';
        result.push_back(k);
    }
    result.push_back(s);
    return result;
}
