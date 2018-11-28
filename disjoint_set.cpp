#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define max(x,y) ( x>y ? x: y )
#define min(x,y) ( x<y ? x: y )
const int Max = 50000;
int diset[3*Max+5];
void init() {
    for(int i = 1; i<=3*Max; i++) diset[i] = i;
}
int find(int x) {
    return x == diset[x] ? x : diset[x] = find(diset[x]);
}
void un(int a,int b) {
    diset[find(a)] = find(b);
}
int main() {
    int n,k,answer = 0;
    cin>>n>>k;
    init();
    for(int i = 0; i<k; i++) {
        int d,x,y;
        cin>>d>>x>>y;
        if(x<=n && x>=1 && y<=n && y>=1 ) {
            if(d==2 && x==y){
                answer++;
                continue;
            }
            int hx = find(x), hy = find(y);
            int rx = find(x+n), ry = find(y+n);
            int brx = find(x+2*n), bry = find(y+2*n);
            //printf("<%d %d %d %d>\n",hx,rx,hy,ry);
            if(d == 1) {
                if(ry == hx || rx == hy || brx == hy || bry == hx ) answer++;
                else un(hx,hy), un(rx,ry),un(brx,bry);
            } else if(d == 2) {
                if(hx == hy || brx == bry || rx == ry || ry == hx || brx == hy) answer++;
                else un(rx,hy), un(bry,hx), un(ry,brx);
            }
        } else answer++;
        /*for(int j = 1; j<=3*n; j++)printf("<%d %d> ",j,diset[j]);
        cout<<'\n';*/
    }
    cout<<answer<<'\n';
}
