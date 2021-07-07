#include <bits/stdc++.h>

#define ll long long
#define ldb long double
#define db double
#define mp make_pair
#define pb push_back
#define F first
#define S second

#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vstr vector<string>
#define vdb vector<double>
#define vbool vector<bool>
#define vvi vector<vector<int> >
#define mii map<int,int>
#define minheap(x) priority_queue<x,vector<x>,greater<x>>

#define rep(i,a,b) for(int i=a; i<b; i++)
#define repr(i,a,b) for(int i=a; i>=b; i--)
#define all(x) (x).begin() , (x).end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it!=a.end(); it++)
#define lb lower_bound
#define ub upper_bound
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

//debug
#define scan(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) {cout<<a[i]<<' ';}cout<<'\n'
#define debug(arr) for(auto x: arr) cout<<x<<" "; cout<<endl;
#define deb(x) cout<< #x <<"="<< x <<endl;
#define deb2(x,y) cout<< #x <<"="<< x <<", "<< #y <<"="<< y<<endl;
#define CHECK cout<<"HERE HAHAAAA"<<endl;


#define endl "\n"
#define PI 3.1415926535897932384626
#define inf 1e18
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL) 
using namespace std;
const int mod = 1'000'000'007;




/////////////////////functions for simplicity ///////////////////////////////
template<typename... T>
void read(T&... args){
	((cin >> args), ...);     // read(x,y,z);
}                             // any no. of arguements)

template<typename... T>       
void write(T&&... args){          // && rvalue reference (new for c++)            //write(x,y,z,cc);
	((cout << args<<" " ), ...);          // any no. of arguements)
}

int mpow(int base, int exp);        //pow fumction O(logn) time
//////////////////////////////////////////////////////////////////////////





void solve(){
   int n,a,b;
   cin>>n>>a>>b;
   unordered_set<ll>s;
   s.insert(1);
   CHECK;
   ll maxx = 1,low=1;
   while(maxx < n){
     for(auto it= s.find(low);it!=s.end();it++){
       ll n1=*it *a;
       ll n2 = *it + b;
      auto it1= s.find(n1);
       auto it2 = s.find(n2);
       if(it1==s.end()){
         s.insert(n1);
         maxx= max(maxx,n1);
       }
       if(it1==s.end()){
         s.insert(n2);
         maxx= max(maxx,n2);
       }
       if(it1!=s.end() && it2!=s.end()){
         low = min(n1,n2);
       }
     }
   }
   auto it = s.find(n);
   if(it!=s.end()){
     cout<<"Yes"<<endl;

   }
 else cout<<"No"<<endl;
}


int32_t main() {
     fast_io;

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll t=1;
    cin >> t;					
    while(t--)
		solve();
   return 0;
}







 int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}