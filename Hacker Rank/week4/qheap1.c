#include <stdio.h>
#define LIM 100000

int J[LIM], H = 0;   // heap + size

// swap helper
void N(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

// push up
void U(int i) {
    while (i && J[(i-1)/2] > J[i]) {
        N(&J[i], &J[(i-1)/2]);
        i = (i-1)/2;
    }
}

// push down
void D(int i) {
    int l, r, m;
    while (1) {
        l = 2*i+1, r = 2*i+2, m = i;
        if (l < H && J[l] < J[m]) m = l;
        if (r < H && J[r] < J[m]) m = r;
        if (m == i) break;
        N(&J[i], &J[m]);
        i = m;
    }
}

// insert
void A(int v) {
    J[H] = v;
    U(H++);
}

// erase one value
void R(int v) {
    int i;
    for (i = 0; i < H; i++) if (J[i] == v) break;
    if (i == H) return;
    J[i] = J[--H];
    U(i); D(i);
}

// get min
int I() { return J[0]; }

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int t, v;
        scanf("%d", &t);
        if (t == 1) { scanf("%d", &v); A(v); }
        else if (t == 2) { scanf("%d", &v); R(v); }
        else if (t == 3) printf("%d\n", I());
    }
    return 0;
}
