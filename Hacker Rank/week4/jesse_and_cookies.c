#include <stdio.h>
#define LIM 1000000

int J[LIM], H; // heap + size

void S(int *x,int *y){int t=*x;*x=*y;*y=t;}

// bubble up
void U(int i){
    while(i && J[(i-1)/2] > J[i]){
        S(&J[i], &J[(i-1)/2]);
        i=(i-1)/2;
    }
}

// bubble down
void D(int i){
    while(1){
        int l=2*i+1, r=l+1, m=i;
        if(l<H && J[l]<J[m]) m=l;
        if(r<H && J[r]<J[m]) m=r;
        if(m==i) break;
        S(&J[i],&J[m]);
        i=m;
    }
}

void P(int v){ J[H]=v; U(H++); }   // insert

int R(){                           // remove min
    if(!H) return -1;
    int t=J[0]; J[0]=J[--H]; D(0); return t;
}

int solve(int n,int K,int arr[]){
    H=0;
    for(int i=0;i<n;i++) P(arr[i]);
    int steps=0;
    while(H>1 && J[0]<K){
        int x=R(), y=R();
        P(x+2*y);
        steps++;
    }
    return J[0]>=K?steps:-1;
}

int main(){
    int n,k; scanf("%d%d",&n,&k);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("%d\n",solve(n,k,arr));
}
