// keyword: Totient, euler phi function
#define N 250000
LL phi[N+5]; 
void build() 
{ 
  for(int i=1; i<=N; i++) 
    phi[i] = i;
  for(int p=2; p<=N; p++) 
  { 
    if(phi[p] == p) 
    { 
      phi[p] = p-1; 
      for(int i = 2*p; i<=N; i += p) 
        phi[i] = (phi[i]/p) * (p-1); 
    } 
  } 
} 
