/*
        Problem: LOJ - 1112
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef pair <ll, ll> pll;
 
const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;
 
ll BLOCK_SIZE;
ll BLOCK[1001];
ll ar[100001];
 
ll getID( ll idx ){
      ll id = idx / BLOCK_SIZE;
      return id;
}
 
ll calc(){
      for( int i=1; i<1000; i++ ){
            BLOCK[i] = 0;
      }
}
 
void del( int idx ){
      int id = getID( idx );
      BLOCK[id] -= ar[idx];
      ar[idx] = 0;
}
void add( int idx, ll val ){
      int id = getID( idx );
      BLOCK[id] += val;
}
 
ll query( int l, int r ){
      int lf = getID( l );
      int rt = getID( r );
 
      ll ret = 0;
 
      if( lf == rt ){
            for( int i=l; i<=r; i++ ){
                  ret += ar[i];
            }
            return ret;
      }
 
      for( int i=l; i<(lf + 1) * BLOCK_SIZE; i++ ){
            ret += ar[i];
      }
 
      for( int i=lf+1; i<rt; i++ ){
            ret += BLOCK[i];
      }
 
      for( int i=rt*BLOCK_SIZE; i<=r; i++){
            ret += ar[i];
      } return ret;
}
     
int main(){
      #ifdef Mr_Emrul
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
      #endif /// Mr_Emrul
 
      //ios_base::sync_with_stdio(false);
      //cin.tie(0);
 
      int t, n, m;
 
      while( ~scanf("%d", &t) ){
            int tc = 1;
            while( t-- ){
                  scanf("%d %d", &n, &m);
                  BLOCK_SIZE = sqrt( n );
                  calc();
                  for( int i=1; i<=n; i++ ){
                        scanf("%lld", &ar[i]);
                        add( i, ar[i] );
                  }
                  printf("Case %d:\n", tc++);
                  int type, l, r, val;
                  while( m-- ){
                        scanf("%d", &type);
                        if(type == 1){
                              scanf("%d", &l);
                              l++;
                              printf("%lld\n", ar[l]);
                              del( l );
                        }
                        else if(type == 2){
                              scanf("%d %d", &l, &val);
                              l++;
                              add( l, val );
                              ar[l] += val;  
                        }
                        else{
                              scanf("%d %d", &l, &r);
                              l++; r++;
                              printf("%lld\n", query( l, r ));
                        }
                  }
            }
            cerr << "--------------------" << '\n';
      }    
      return 0;
}
