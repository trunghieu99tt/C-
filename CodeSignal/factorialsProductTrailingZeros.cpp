	int factorialsProductTrailingZeros(int l, int r) {
		int sum=0;
		for(int i=l;i<=r;i++)
			sum+=factorialTrailingZeros(i);
		return sum;
	}
	
	int factorialTrailingZeros(int n) {
		int res=0;
		for(int i=1;i<=10;i++)
		{
			int pow1 = pow(5,i);
			res += n/pow1;
			if(pow1>n)
				break;
		}
		return res;
	}
