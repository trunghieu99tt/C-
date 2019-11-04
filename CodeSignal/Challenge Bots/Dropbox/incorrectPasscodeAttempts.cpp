bool incorrectPasscodeAttempts(std::string p, std::vector<std::string> a) {
    int c=0;
    for (auto i:a)
    {
        bool f=0;
        if(i!=p)
        {
            c++;
            f=1;
        }
        if(c==10) return 1;
        if(!f) c=0;
    }
    return 0;
}
