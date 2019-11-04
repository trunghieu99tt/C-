std::vector<int> sortByHeight(std::vector<int> a) {
    std::vector<int> b;
    for (auto i:a)if(i!=-1) b.push_back(i);
    sort(b.begin(),b.end());
    auto index=b.begin();
    for (auto &i:a)
        if(i!=-1) i=*(index++);
    return a;
}
