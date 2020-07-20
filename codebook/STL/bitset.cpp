bitset<40> b;
int k = 20;
//將int直接轉為bitset
bitset<40> bk(k);
//將string直接轉為bitset
string str = "10100110";
bitset<40> bstr(str);
// To int
bitset<N+5>(str).to_ulong()
// To long long
bitset<N+5>(str).to_ullong()
// access i-th bit
bset[2] == 1;

b.reset();//每個位元設0
b.set();//每個位元設1
b[pos] = 1;//第pos個位元設成1
b.count();//有幾個1
b.size();//大小

cin >> b;
//input: "0110xx0011"
//b = "0110"
bitset<8> bb("1001");
cout << bb ;// 00001001