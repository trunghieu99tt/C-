bool sameDigitNumber(int n) {
    int a=n%10;
    while(n){
        if(n%10!=a)
            return false;
        n/=10;
    }
    return true;
}
