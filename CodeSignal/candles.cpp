int candles(int candlesNumber, int makeNew) {
    int add=0,res=candlesNumber,left=candlesNumber;
    if(candlesNumber<makeNew) return candlesNumber;
    while(left>=makeNew)
    {
        int temp=left/makeNew;
        res+=temp;
        left=left-temp*makeNew+temp;
    }
    return res;
}
