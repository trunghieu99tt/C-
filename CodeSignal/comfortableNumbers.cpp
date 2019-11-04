int sumDigit(int n)
{
	int sum=0;
	while(n)
	{
      sum+=n%10;
		n/=10;
	}
		sum+=n%10;
	return sum;
}
bool check(int a, int b)
{
	return (a!=b && b>=(a-sumDigit(a)) && b<=(a+sumDigit(a)));
}

int comfortableNumbers(int l, int r) {
   int i,j,counter=0;
	for (i=l;i<=r;i++)
	{
		for (j=i-sumDigit(i);j<=i+sumDigit(i);j++)
			if(j>=l && j<=r && j>i && check(j,i)==true) 
				counter++;
	}
   return counter;
}
