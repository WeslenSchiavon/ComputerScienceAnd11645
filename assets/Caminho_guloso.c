#include <stdio.h>
#include <limits.h>

#define N 7

char *aldeias[N] = {
    "Maturacá", "Ariabü", "Maiá", "Paduarí", "Nazaré", "Watoriki", "Haximu"
};

int dist[N][N] = {
    {0, 9, 15, 21, 19, 13, 10},
    {9, 0, 11, 17, 20, 15, 12},
    {15, 11, 0, 8, 14, 16, 18},
    {21, 17, 8, 0, 9, 19, 20},
    {19, 20, 14, 9, 0, 13, 17},
    {13, 15, 16, 19, 13, 0, 11},
    {10, 12, 18, 20, 17, 11, 0}
};

int main() {
    int visited[N] = {0};
    int current = 0, next, total = 0;
    visited[current] = 1;

    printf("Rota (heurística gulosa):\n");
    printf("%s ", aldeias[current]);

    for (int step = 1; step < N; step++) {
        int best = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[current][j] < best) {
                best = dist[current][j];
                next = j;
            }
        }
        visited[next] = 1;
        total += best;
        current = next;
        printf("-> %s ", aldeias[current]);
    }

    total += dist[current][0];
    printf("-> %s\n", aldeias[0]);
    printf("Distância total: %d km\n", total);
    return 0;
}