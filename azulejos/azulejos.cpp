#include <bits/stdc++.h>

using namespace std;

#define nscanf(N, A, F) for (int i = 0; i < N; i++) scanf("%d", &A[i].F);

struct tile {
    int i;
    int p;
    int h;
};

bool byPriceAsc(struct tile a, struct tile b) {
    return a.p < b.p;
}

bool byHeightAsc(struct tile a, struct tile b) {
    return a.h < b.h;
}

bool byHeightDesc(struct tile a, struct tile b) {
    return a.h > b.h;
}

int main() {
    int n;
    scanf("%d", &n);
    tile back[n];
    tile front[n];
    for (int i = 0; i < n; i++) {back[i].i = i + 1; front[i].i = i + 1;}
    nscanf(n, back, p);
    nscanf(n, back, h);
    nscanf(n, front, p);
    nscanf(n, front, h);
    sort(back, back + n, byHeightAsc);
    sort(front, front + n, byHeightDesc);
    sort(back, back + n, byPriceAsc);
    sort(front, front + n, byPriceAsc);
    for (int i = 0; i < n; i++) {
        if (back[i].h <= front[i].h) {
            printf("impossible\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", back[i].i);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", front[i].i);
    printf("\n");
    return 0;
}
