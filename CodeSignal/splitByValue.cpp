std::vector<int> splitByValue(int k, std::vector<int> a) {
vector<int>b;for(int i=0;i<a.size();i++){
    if(a[i]<k)b.push_back(a[i]);
}
 for(int i=0;i<a.size();i++){
     if(a[i]>=k)b.push_back(a[i]);
 }
    return b;
}