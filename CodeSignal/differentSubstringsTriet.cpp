int differentSubstringsTrie(std::string a) {
    set<string>s;
    for(int i=0;i<a.size();i++){
        string d="";
        for(int j=i;j<a.size();j++){
            d+=a[j];
            s.insert({d});
        }
    }
    return s.size();
}
