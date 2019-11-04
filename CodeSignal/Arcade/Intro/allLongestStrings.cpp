std::vector<std::string> allLongestStrings(std::vector<std::string> a) {
    int max=0;
    vector<string> b;
    for(auto i:a)
        if(i.length()>max) max=i.length();
    for (auto i:a)
        if(i.length()==max) b.push_back(i);
     return b;
}
