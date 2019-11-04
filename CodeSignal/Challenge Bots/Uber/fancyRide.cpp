std::string fancyRide(int l, std::vector<double> fares) {
    vector<string> op{"UberX", "UberXL", "UberPlus", "UberBlack", "UberSUV"};
    string res;
    double max;
    for (int i=0;i<fares.size();i++)
    {
        if(fares[i]*l<=20 && fares[i]*l>=max)
        {
            max=fares[i]*l;
            res=op[i];
        }
    }
    return res;
}
