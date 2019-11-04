double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1,2));
}
int findSquareSide(vector<int> x, std::vector<int> y) {
    vector<int> index{0,1,2,3};
    do{
        int flag = 1;
        double d = dist(x[index[0]], y[index[0]], x[index[1]], y[index[1]]);
        for(int i = 1;i<3;i++)
            if(dist(x[index[i]],y[index[i]], x[index[i-1]], y[index[i-1]]) != d)
            {
                flag = 0;
                break;
            }
        if(flag)
            return d * d;
    }
    while(next_permutation(begin(index),end(index)));
}
