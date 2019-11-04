int maxMultiple(int divisor, int bound) {
    int n;
    for (n=bound;n>0;n--) if(n%divisor==0) return n;
}
