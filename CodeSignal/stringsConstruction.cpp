int stringsConstruction(std::string a, std::string b) {
    int countera[26]={0},counterb[26]={0},i,min=11;
    for (auto i:a) countera[i-'a']++;
    for (auto i:b) counterb[i-'a']++;
    for (auto i:a)
        if(b.find(i)==string::npos) return 0;
    for (i=0;i<=26;i++)
    {
        if(countera[i]>0 && counterb[i]>0)
            if(counterb[i]/countera[i]<=min) min=counterb[i]/countera[i];
    }
    return min>10?0:min;
}
