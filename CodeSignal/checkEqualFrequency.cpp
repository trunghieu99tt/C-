bool checkEqualFrequency(std::vector<int> inputArray) {
    std::vector<std::pair<int, int> > foo;
    for (auto  i : inputArray) {
        bool bar = 1;
        for (int j = 0; j < foo.size();j++) 
            if (i == foo[j].first) {
                foo[j].second++;
                bar = 0;
            }
        if (bar) foo.push_back(std::make_pair(i, 1));
    }
    for (int i = 0; i < foo.size() - 1; i++)
        if (foo[i].second != foo[i+1].second)
            return false;
    return true;
}
