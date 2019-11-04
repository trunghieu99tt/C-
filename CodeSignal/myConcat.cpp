std::string myConcat(std::vector<std::string> arguments, std::string separator) {
    string res="";
    for(auto i:arguments)
    {
        res+=i;
        res+=separator;
    }
    return res;
}
