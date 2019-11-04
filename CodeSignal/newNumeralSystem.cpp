std::vector<std::string> newNumeralSystem(char number) {
    vector<string> result;
    char a='A',b=number;
    string temp;
    while(a<=b)
    {
        temp="";
        temp+=a;
        temp+=" + ";
        temp+=b;
        result.push_back(temp);
        a++;
        b--;
    }
    return result;
}
