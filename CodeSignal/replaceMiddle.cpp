std::vector<int> replaceMiddle(std::vector<int> arr) {
   vector<int> res;
   int i,n=arr.size();
   if(n%2!=0) return arr;
   else
   {
      for (i=0;i<n/2-1;i++)
         res.push_back(arr[i]);
         res.push_back(arr[n/2-1]+arr[n/2]);
      for (i=n/2+1;i<n;i++)
         res.push_back(arr[i]);
   }
   return res;
}
