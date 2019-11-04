int phoneCall(int min1, int min2_10, int min11, int s) {
    int sum,i;
    if(s>=min1) 
    {
        sum=1;
        s-=min1;
    }
    else return 0;
    if(s/min2_10>=9)
    {
        s-=min2_10*9;
        sum+=9;
    }
    else return sum+s/min2_10;
    if(s>min11) return sum+=s/min11;
}
