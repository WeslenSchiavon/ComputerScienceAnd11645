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

int min(int a, int b) { return a < b ? a : b; }

int tsp(int visited[], int pos, int count, int cost, int start, int path[], int bestPath[], int *bestCost) {
    if (count == N && dist[pos][start] > 0) {
        int totalCost = cost + dist[pos][start];
        if (totalCost < *bestCost) {
            *bestCost = totalCost;
            for (int i = 0; i < N; i++) bestPath[i] = path[i];
        }
        return totalCost;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[pos][i] > 0) {
            visited[i] = 1;
            path[count] = i;
            tsp(visited, i, count + 1, cost + dist[pos][i], start, path, bestPath, bestCost);
            visited[i] = 0;
        }
    }
    return *bestCost;
}

int main() {
    int visited[N] = {0}, path[N], bestPath[N];
    int bestCost = INT_MAX;
    visited[0] = 1; path[0] = 0;

    tsp(visited, 0, 1, 0, 0, path, bestPath, &bestCost);

    printf("🔹 Melhor rota (solução ótima):\n");
    for (int i = 0; i < N; i++) printf("%s -> ", aldeias[bestPath[i]]);
    printf("%s\n", aldeias[0]);
    printf("🔸 Distância total: %d km\n", bestCost);
    return 0;
}
