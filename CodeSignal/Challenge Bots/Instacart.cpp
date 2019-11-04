/*----------------------------delivery---------------------------*/
std::vector<bool> delivery(std::vector<int> order, std::vector<std::vector<int>> shoppers) {
    vector<bool> res;
    int n=shoppers.size(),i,j;
    for (int i=0;i<n;i++)
    {
        double k=(shoppers[i][0]+order[0])/float(shoppers[i][1])+shoppers[i][2];
        cout<<k<<endl;
        if(k>=order[1] && k<=order[2]+order[1]) 
            res.push_back(1);
        else res.push_back(0);
    }
    return res;
}

/*----------------------------isAdmissibleOverpayment------------------*/
bool isAdmissibleOverpayment(std::vector<double> prices, std::vector<std::string> notes, double x) {
    double temp=0.0;
    int j=0;
    for (auto i:notes)
    {
        if(i.find("Same")!=string::npos) j++;
        else{
            auto l=i.find_first_of('%');
            string t=i.substr(0,l);
            double k=double(stof(t));
            k/=100;
            if(k>100) return 0;
            if(i.find("higher")!=string::npos)
                temp+=fabs(prices[j]-prices[j]/(1.0+k));
            else 
                temp-=fabs(prices[j]-prices[j]/(1.0-k));
            j++;
        }
        cout<<temp<<endl;
    }
    return (abs(temp-x)<1e-9 || temp<x);
}
