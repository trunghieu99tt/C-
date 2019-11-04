int firstMultiple(std::vector<int> d, int start) {
    int lcm = d[0];
    for(auto i:d)
        lcm = (lcm * i)/__gcd(lcm,i);
    int mul = start/lcm;
    if(lcm * mul < start)
        mul++;
    return lcm * mul;
}
