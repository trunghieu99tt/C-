bool areSimilar(std::vector<int> a, std::vector<int> b) {
    int i,tempa,tempb,counter=0;;
    bool flag=true;
    for (i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
            if(flag==true)
            {
                flag=false;
                tempb=b[i];
                tempa=a[i];
            }
            else
            {
                if(a[i]!=tempb || b[i]!=tempa) return false;
                else counter++;
                if(counter>1) return false;
            }
        }
    }
    return true;
}
