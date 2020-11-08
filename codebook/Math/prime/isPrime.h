// O(sqrt(n))
bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}


bool witness(__int64 a, __int64 n)
{
    __int64 t,d,x;
    d=1;
    int i=ceil(log(n-1.0)/log(2.0)) - 1;//youwu ba -1 qudiao
    for(;i>=0;i--)
    {
        x=d;  d=(d*d)%n;
        if(d==1 && x!=1 && x!=n-1) return true;
        if( ((n-1) & (1<<i)) > 0)d=(d*a)%n;
    }
    return d==1?false: true;
}
 
bool miller_rabin(__int64 n)
{
    if(n==2)    return true;
    if(n==1 || ((n&1)==0))    return false;
    for(int i=0;i<3;i++){
        __int64 a=rand()*(n-2)/RAND_MAX +1;
        if(witness(a, n))    return false;
        if(witness(s[i],n))  return false;
    }
    return true;
}
