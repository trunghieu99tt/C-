/*-----------------allianceHelp-----------------*/
int allianceHelp(int t, int a) {
    a=min(a,10);
    int x=0.1*t;
    int s=max(x,60);
    return max(0,t-s*a);
}
