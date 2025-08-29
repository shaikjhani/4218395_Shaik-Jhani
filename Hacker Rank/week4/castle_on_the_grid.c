#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 110

typedef struct {
    int x, y, dist;
} Cell;

char board[LIMIT][LIMIT];
int seen[LIMIT][LIMIT];
int size;

// Direction vectors (row, col)
int dirX[] = {0, 0, 1, -1};
int dirY[] = {1, -1, 0, 0};

int shortestPath(int sx, int sy, int tx, int ty) {
    Cell q[LIMIT * LIMIT];
    int head = 0, tail = 0;

    q[tail++] = (Cell){sx, sy, 0};
    seen[sx][sy] = 1;

    while (head < tail) {
        Cell cur = q[head++];

        if (cur.x == tx && cur.y == ty) return cur.dist;

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dirX[d];
            int ny = cur.y + dirY[d];

            // slide like a rook until hitting wall or border
            while (nx >= 0 && nx < size && ny >= 0 && ny < size && board[nx][ny] != 'X') {
                if (!seen[nx][ny]) {
                    seen[nx][ny] = 1;
                    q[tail++] = (Cell){nx, ny, cur.dist + 1};
                }
                nx += dirX[d];
                ny += dirY[d];
            }
        }
    }
    return -1; // unreachable
}

int main() {
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%s", board[i]);
    }

    int sx, sy, tx, ty;
    scanf("%d %d %d %d", &sx, &sy, &tx, &ty);

    memset(seen, 0, sizeof(seen));
    printf("%d\n", shortestPath(sx, sy, tx, ty));
    return 0;
}
