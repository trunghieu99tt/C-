int additionWithoutCarrying(int param1, int param2) {
   string a=to_string(param1),b=to_string(param2), result="";
   int i=a.length()-1,j=b.length()-1;
   while(i>=0 && j>=0)
   {
      int k=(a[i]-48)+(b[j]-48);
      char ch;
      if(k<10) ch=k+'0';
      else ch=(k%10)+'0';
      result=ch+result;
      i--;j--;
   }
   for (int l=i;l>=0;l--) result=a[l]+result;
   for (int l=j;l>=0;l--) result=b[l]+result;
   int ouput=int(stoi(result,nullptr,10));
   return ouput;
}
