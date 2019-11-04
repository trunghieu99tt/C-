std::vector<int> digitalSumSort(std::vector<int> a) {
    sort(a.begin() , a.end() , [](int l , int r){
        int lc = l , rc = r;
        int lt = 0;
        int rt = 0;
        while(l){
            lt += l%10;
            l /= 10;
        }
        while(r){
            rt += r%10;
            r /= 10;
        }
        if(lt == rt){
            return lc < rc;
        }
        return lt < rt;
    });
    return a;
}
