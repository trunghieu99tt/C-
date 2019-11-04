int lateRide(int n) {
    int hours=n/60,minutes=n%60,sum=0;
    while(hours>0)
    {
        sum+=hours%10;
        hours/=10;
    }
    while(minutes>0)
    {
        sum+=minutes%10;
        minutes/=10;
    }
    return sum;
}
