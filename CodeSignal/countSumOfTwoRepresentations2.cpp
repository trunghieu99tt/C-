int countSumOfTwoRepresentations2(int n, int l, int r) {
    int count=0;
    for (int i = l; i <= r; i++)
        if (n-i >=l&&n-i<=r&& n-i>=i)
            count++;
    return count;
}
