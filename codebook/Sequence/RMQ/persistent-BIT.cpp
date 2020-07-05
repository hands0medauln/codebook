#define N 100000
#define lowbit(x) x&(-x)
struct P{
  int data,id;
  P(int d=0,int i=0):data(d),id(i){}
  friend bool operator<(const P &a,const P &b){
    return a.id<b.id;
  }
};
int n,now;
vector<P> tree[N+5];
void init() {
  now = 0;
  for(int i=1;i<=n;++i)
  {
    tree[i].clear();
    tree[i].push_back(P());
  }
}
void modify(int x,int d) {
  for(;x <= n; x += lowbit(x))
    tree[x].push_back(P(tree[x].back().data+d,now));
  ++now;
}
// 查詢第 id 次操作的區間和，id 從 0 開始計算
int query(int x,int id) {
  int ans = 0;
  for(; x;x -= lowbit(x)){
    auto a=std::upper_bound(
      tree[x].begin(),
      tree[x].end(),
      P(0,id)) - 1;
    ans += a->data;
  }
  return ans;
}