int arrayMinimumAboveBound(std::vector<int> a, int bound) {
    sort(a.begin(),a.end());
    for (int i:a)
        if(i>bound) return i;
}
