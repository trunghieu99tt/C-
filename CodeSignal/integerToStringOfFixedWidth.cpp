std::string integerToStringOfFixedWidth(int number, int width) {
    string s=to_string(number);
    if(width<=s.size()) return s.substr(s.size()-width);
    else 
        while(width>s.size())
            s="0"+s;
    return s;
}
