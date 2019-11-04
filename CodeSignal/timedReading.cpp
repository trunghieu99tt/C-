int timedReading(int maxLength, std::string text) {
    string temp="";
    int counter=0;
    for (auto &i:text)
        i=tolower(i);
    for (auto i:text+' ')
    {
        if(i>='a' && i<='z') temp+=i;
        else{
            if(temp.length()<=maxLength && temp!="") counter++;
            temp="";
        }
    }
    return counter;
}
