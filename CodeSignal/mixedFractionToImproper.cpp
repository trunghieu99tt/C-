std::vector<int> mixedFractionToImproper(std::vector<int> a) {
    int tu=a[0]*a[2]+a[1],mau=a[2],th=__gcd(tu,mau);
    return {tu/th,mau/th};
}
