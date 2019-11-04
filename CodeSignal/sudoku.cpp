bool sudoku(std::vector<std::vector<int>> grid) {
    int i,j,res=0;
    int a[10]={0};
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
           if(count(grid[i].begin(),grid[i].end(),grid[i][j])!=1) 
               return 0;
   }
    int cot=0;
    while(cot<9)
    {
        res=0;
        for(i=0;i<9;i++)
            res+=grid[i][cot];
        if(res!=45) 
            return 0;
        cot++;
    }
    for(i=0;i<grid.size()-2;i+=3)
    {
        for(j=0;j<grid.size()-2;j+=3)
        {
            string check="";
            for (int k=i;k<=i+2;k++)
            {
                for(int l=j;l<=j+2;l++)
                    check+=(grid[k][l])+'0';
            }
             for(int f=1;f<=9;f++)
                if(count(check.begin(),check.end(),f+'0')!=1) 
                    return 0;
        }
    }
    return 1;
}
