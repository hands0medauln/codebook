#define N 1000005
#define MOD (1e9+7)
// ax == 1 (mod m),query x -> use exgcd
// if m is prime ,than x = a^(p-2) % p
LL inv[N];   // mod_inv table
LL fact[N];  // factorial table
void buildFact()
{
  fact[0] = fact[1] = 1;
  for(LL i = 2; i < N; i++)
    fact[i] = fact[i - 1] * i % MOD;
}
//section 1 for exgcd start
void exgcd(LL a, LL b, LL &x, LL &y)
{
  if(!b) x = 1, y = 0;
  else
  {
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}
LL niYuan(LL a, LL b)//ax+by = 1
{
  LL x, y;
  exgcd(a, b, x, y);
  return (x + b) % b;
}
//section 1 for exgcd end

//section 2 for fema's theorem start
LL pow(LL a, LL n, LL p) // a^n % p
{
  LL ans = 1;
  while(n)
  {
    if(n & 1) ans = ans * a % p;
    a = a * a % p;
    n >>= 1;
  }
  return ans;
}
// if MOD(b) is prime we use fema's theorem
// LL niYuan(LL a, LL b)
// {
//     return pow(a, b - 2, b);
// }
// section 2 for fema's theorem end

//section 3 for tableing inverse start
void mod_inv_table(){
  inv[1]=1;
  for (int i = 2; i < N; ++i)
  {
    inv[i] = (MOD-MOD/i)*inv[MOD%i] %MOD;
  }
}
//section 3 for tableing end
// C a 取 b
LL C(LL a, LL b)
{
  return fact[a] * niYuan(fact[b], MOD) % MOD
    * niYuan(fact[a - b], MOD) % MOD;
}

buildFact();    
C(1000,2)
//if need table of mod_inv from 1~MOD-1
mod_inv_table();
