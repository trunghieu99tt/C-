int numbersGrouping(std::vector<int> a) {
    int gr[1000000]={0},counter=0,i;
    for (auto i:a)
        if(i%10000==0) gr[i/10000]++;
        else 
        {
            int k=i/10000+1;
            gr[k]++;
        }
    for (auto i:gr)
        if(i) counter++;
    return counter+a.size();
}
