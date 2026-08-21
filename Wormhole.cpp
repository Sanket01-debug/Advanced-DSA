#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int total = 2 * n + 2;

        int x[101];
        int y[101];
        int cost[101];

        int sx, sy;
        cin >> sx >> sy;
        x[0] = sx;
        y[0] = sy;

        int dx, dy;
        cin >> dx >> dy;
        x[1] = dx;
        y[1] = dy;

        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2, c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;

            x[2 * i + 2] = x1;
            y[2 * i + 2] = y1;

            x[2 * i + 3] = x2;
            y[2 * i + 3] = y2;

            cost[i] = c;
        }

        int graph[101][101];
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                graph[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int start = 2 * i + 2;
            int end = 2 * i + 3;

            graph[start][end] = cost[i];
            graph[end][start] = cost[i];
        }

        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                if (graph[i][j] == -1)
                {
                    graph[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                }
            }
        }

        int dist[101];
        bool visited[101];

        for (int i = 0; i < total; i++)
        {
            dist[i] = 100000000;
            visited[i] = false;
        }

        dist[0] = 0;

        for (int count = 0; count < total; count++)
        {

            int u = -1;
            int minDist = 100000000;

            for (int i = 0; i < total; i++)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    minDist = dist[i];
                    u = i;
                }
            }

            visited[u] = true;

            for (int v = 0; v < total; v++)
            {
                if (!visited[v] &&
                    dist[u] + graph[u][v] < dist[v])
                {

                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << dist[1] << endl;
    }

    return 0;
}