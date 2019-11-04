vector<std::vector<int>> boxBlur(vector<vector<int>> image) {
    int i,j,r=image.size(),c=image[0].size(),k,l,temp;
	vector<vector<int>> res(r-2,vector<int>(c-2));
    for (i=0;i<r-2;i++)
    {
        for(j=0;j<c-2;j++)
        {
            temp=0;
            for(k=i;k<=i+2;k++)
            {
                for(l=j;l<=j+2;l++)
                    temp+=image[k][l];
            }
            temp/=9;
            res[i][j]=temp;
        }
    }
   return res;
}
