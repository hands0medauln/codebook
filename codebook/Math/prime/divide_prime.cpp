void divide_prime(int n)
{
	int p=2;
	int t(trunc(sqrt(n)));
	while(n!=1&&p<=t)
	{
		int i=0;
		if(n%p==0)
		{
			while(n%p==0){n/=p;i++;};
			cout<<p<<'^'<<i<<' ';
		};
		p++;
	};
	if(n!=1)cout<<n<<'^'<<1;
}