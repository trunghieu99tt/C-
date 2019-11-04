int depositProfit(int deposit, int rate, int threshold) {
    int counter=0;
    while(deposit<threshold)
    {
        counter++;
        deposit=round(deposit+float(deposit)*rate/100);
    }
    return counter;
}
