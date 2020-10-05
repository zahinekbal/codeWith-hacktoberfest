/*
 * File: Codeforces 717A - Festival Organization
 * Algorithm: Modular Inverse
 * Created Date: Tuesday August 4th 2020
 */

// The solution belongs to https://www.programmersought.com/article/19372435962/
#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=205;
struct cp{
	int x,y;
	cp(int x=0,int y=0):x(x),y(y){}
	friend inline cp operator+(const cp&a,const cp&b){return cp(add(a.x,b.x),add(a.y,b.y));}
	friend inline cp operator-(const cp&a,const cp&b){return cp(dec(a.x,b.x),dec(a.y,b.y));}
	friend inline cp operator*(const cp&a,const cp&b){return cp(add(mul(a.x,b.x),mul(5,mul(a.y,b.y))),add(mul(a.x,b.y),mul(a.y,b.x)));}
	friend inline cp operator*(const cp&a,const int&b){return cp(mul(a.x,b),mul(a.y,b));}
	friend inline cp operator/(const cp&a,const cp&b){
		int t=ksm(dec(mul(b.x,b.x),mul(5,mul(b.y,b.y))),mod-2);
		return cp(mul(t,dec(mul(a.x,b.x),mul(5,mul(a.y,b.y)))),mul(t,dec(mul(a.y,b.x),mul(a.x,b.y))));
	}
	friend inline cp operator^(cp a,int p){cp ret=cp(1,0);for(;p;p>>=1,a=a*a)if(p&1)ret=ret*a;return ret;}
	friend inline cp operator^(cp a,ll p){cp ret=cp(1,0);for(;p;p>>=1,a=a*a)if(p&1)ret=ret*a;return ret;}
}A,B,X,Y,ans;
int C[N][N],s[N][N],k;
ll l,r;
inline void init(const int&up){
	s[0][0]=1;
	for(ri i=0;i<=up;++i){
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<i;++j)C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	for(ri i=1;i<=up;++i)for(ri j=1;j<=i;++j)s[i][j]=add(s[i-1][j-1],mul(s[i-1][j],i-1));
	A=cp(0,ksm(5,mod-2)),B=cp(0,mod-ksm(5,mod-2));
	X=cp((mod+1)>>1,(mod+1)>>1),Y=cp((mod+1)>>1,mod-((mod+1)>>1));
}
inline cp S(cp x,int k){
	if(x.x==1&&x.y==0)return x*((r-l+1)%mod);
	return (x^l)*(((x^(r-l+1))-cp(1,0))/(x-cp(1,0)));
}
inline cp calc(int k){
	cp ret;
	for(ri i=0;i<=k;++i)ret=ret+(S((X^i)*(Y^(k-i)),i)*((A^i)*(B^(k-i)))*C[k][i]);
	return ret;
}
int main(){
	cin>>k>>l>>r,l+=2,r+=2;
	init(k);
	cp t;
	ri mt=1;
	for(ri i=0;i<=k;++i)t=calc(i)*s[k][i],(k+i)&1?ans=ans-t:ans=ans+t,Mul(mt,i?i:1);
	cout<<mul(ans.x,ksm(mt,mod-2));
	return 0;
}

