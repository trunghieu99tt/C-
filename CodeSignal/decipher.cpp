std::string decipher(std::string cipher) {
    int temp=0;
    string res="";
    for (auto i:cipher)
    {
        temp=temp*10+(i-'0');
        if(temp>=97 && temp<=122)
        {
            res+=char(temp);
            temp=0;
        }
    }
    return res;
}
