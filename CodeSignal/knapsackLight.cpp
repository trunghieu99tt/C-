int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {
    int sumweight=weight1+weight2;
    if(maxW>=sumweight) return value1+value2;
    if(maxW>=weight1 && (value1>=value2 || maxW<weight2) ) return value1;
    if(maxW>=weight2 && (value2>=value1|| maxW<weight1)) return value2;
    if(maxW>=weight1 && maxW>=weight2) return (value1>value2)?value1:value2;
    return 0;
}
