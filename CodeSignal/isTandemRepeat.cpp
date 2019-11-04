bool Check(string a,string b)
{
    int counter=0;
    while(b.find(a)!=string::npos)
    {
        b.erase(b.find(a),a.length());
        counter++;
    }
    return b.length()==0 && counter==2;
}
bool isTandemRepeat(std::string inputString) {
    string temp="";
    for (auto i:inputString)
    {
        temp+=i;
        auto k=inputString;
        if(Check(temp,k)) return true;
    }
    return false;
}
