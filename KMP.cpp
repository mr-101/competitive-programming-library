#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define sz(x) (int)x.size()
#define all(v) v.begin() , v.end()
#define N 100005
#define M 1000005
#define mod 1000000007

using namespace std;

typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef bitset<15> maskk;


vi prefixFunc(string pat) {
	int m = sz(pat);
	vi longestprefix(m);
	for(int i = 1 , k = 0; i < m; ++i) {
		while(k > 0 && pat[i] != pat[k]) 
			k = longestprefix[k-1];
		if(pat[k] == pat[i])
			longestprefix[i] = ++k;
		else
			longestprefix[i] = k;
	}
	return longestprefix;
}

void kmp(string str , string pat) {
	int n = sz(str);
	int m = sz(pat);
	vi longestprefix = prefixFunc(pat);
	for(int i = 0 , k = 0; i < n; ++i) {
		while(k > 0 && pat[k] != str[i])
			k = longestprefix[k-1];
		if(pat[k] == str[i])
			++k;
		if(k == m) {
			printf("%d\n" , i-m+1);
			k = longestprefix[k-1];
		}
	}
}

int main() { 
    kmp("abcaaba" , "aa");
    return 0;
 }
