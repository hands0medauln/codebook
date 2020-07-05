//注意，f0=1,f1=1,f2=2...
const LL mod=1e9+7;
struct Matrix  { 
  LL a[2][2];
  void all_0()
  {
    memset(a, 0, sizeof(a));
  }
  void I()
  {
    a[0][0]=1; a[0][1]=0;
    a[1][0]=0; a[1][1]=1;
  }
  void X()
  {
    a[0][0]=1; a[0][1]=1;
    a[1][0]=1; a[1][1]=0;
  }
};
Matrix operator*(const Matrix &a, const Matrix &b)
{
  Matrix ret;
  ret.all_0();
  for (LL i=0; i<2; i++)
    for (LL j=0; j<2; j++)
      for (LL k=0; k<2; k++)  {
        ret.a[i][j]+=a.a[i][k]*b.a[k][j];
        ret.a[i][j]%=mod;
      }
  return ret;
}
Matrix power(Matrix a, LL n)
{
  Matrix ret;
  ret.I();
  if (n==0)  return ret;
  ret.X();
  if (n==1)  return ret;
  ret=power(a, n/2);
  ret=ret*ret;
  if (n%2==1)  ret=ret*a;
  return ret;
}
LL query(LL n)
{
  Matrix tmp;
  tmp.X();
  tmp=power(tmp, n);
  LL ret=tmp.a[1][0]+tmp.a[1][1];
  ret%=mod;
  return ret;
}
// query(i) -> fibo_i