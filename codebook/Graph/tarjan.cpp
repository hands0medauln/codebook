#define N 50005
std::vector<int> s[N];
int low[N],v[N]={0},Time=0,ans=0,cnt=0;
int st[N],top=0,contract[N];
bool instack[N]={0};
void dfs(int x){
	low[x]=v[x]=++Time;
	st[top++]=x;
	instack[x]=1;
	for(int i=0,r;i<(int)s[x].size();++i){
		if(!v[r=s[x][i]])dfs(r);
		if(instack[r])low[x]=std::min(low[x],low[r]);
	}
	if(v[x]==low[x]){
		int u;
		do{
			instack[u=st[--top]]=0;
			contract[u]=cnt;/*每個點所在的SCC*/
		}while(u!=x);
		++cnt;
	}
}