std::vector<int> fractionReducing(std::vector<int> fraction) {

  struct Helper {
    int gcd(int a, int b) {
      if (a > b) {
        return gcd(b, a);
      }
      if (a == 0) {
        return b;
      }
      return gcd(b % a, a);
    }
  };
  Helper h;

  int commonDivisor = h.gcd(fraction[0], fraction[1]);
  fraction[0] /= commonDivisor;
  fraction[1] /=  commonDivisor ;

  return fraction;
}
