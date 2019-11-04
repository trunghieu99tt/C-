int squareDigitsSequence(int a0) {
   int check[1001]={0},counter=1;
   check[a0]=1;
   while(1)
   {
      counter++;
      int temp=0,temp1=a0;
      while(temp1)
      {
         temp+=round(pow(temp1%10,2));
         temp1/=10;
      }
      a0=temp;
      if(check[a0]==1) return counter;
      check[a0]=1;
   }
}
