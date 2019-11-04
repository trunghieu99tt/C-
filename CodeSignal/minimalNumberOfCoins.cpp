int minimalNumberOfCoins(std::vector<int> coins, int price) {

  int result = 0;

  for (int i = (int)coins.size() - 1; i >= 0; i--) {
      if(price>=coins[i])
      {
        while(price>=coins[i])
        {
           price-=coins[i];
          result++;
        }
      }
  }

  if (price) {
    return -1;
  }
  return result;
}
