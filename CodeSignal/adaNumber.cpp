int value(char c)
{
    if(c >= '0' && c <='9')
        return c - '0';
    if(c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    if(c >= 'A' && c <= 'F')
        return 10 + c - 'A';
    return 17;
}

bool adaNumber(std::string line) {
    if(line.empty()) return false;
    for(size_t pos=line.find("_"); pos!=string::npos; pos=line.find("_", pos))
        line.erase(pos, 1);
    int base = 0;
    string::iterator it;
    for(it=line.begin(); it!=line.end() && *it!='#'; ++it)
    {
        if(value(*it)>9) return false;
        base = base*10 + value(*it);
    }
    if(it==line.end() && base>0) return true;
    if(*it=='#' && (base < 2 || base > 16)) return false;
    if(it<line.end()-2) for(it=it+1; it!=line.end() && *it!='#'; ++it)
        if(value(*it)>=base) return false;
    if(it!=line.end()-1) return false;
    return true;
}
