bool isArithmeticProgression(std::vector<int> s) {
    int d = s[1] - s[0];
    for(int i = 1;i<s.size();i++)
        if(s[i] - s[i-1]!=d)
            return 0;
    return 1;
}
