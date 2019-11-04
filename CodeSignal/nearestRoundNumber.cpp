int nearestRoundNumber(int value) {
    if(value%10==0) return value;
    return (value/10 +1) *10;
}
