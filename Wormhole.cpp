#include <iostream>
#include <queue>
#include <climits>
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

        // Source = node 0
        int sx, sy;
        cin >> sx >> sy;

        x[0] = sx;
        y[0] = sy;

        // Destination = node 1
        int dx, dy;
        cin >> dx >> dy;

        x[1] = dx;
        y[1] = dy;

        // Store wormholes
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

        // Graph
        int graph[101][101];

        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                graph[i][j] = -1;
            }
        }

        // Wormhole edges
        for (int i = 0; i < n; i++)
        {
            int start = 2 * i + 2;
            int end = 2 * i + 3;

            graph[start][end] = cost[i];
            graph[end][start] = cost[i];
        }

        // Normal distance between every pair of points
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                if (graph[i][j] == -1)
                {
                    graph[i][j] =
                        abs(x[i] - x[j]) + abs(y[i] - y[j]);
                }
            }
        }

        // ---------------- Dijkstra ----------------

        int dist[101];

        for (int i = 0; i < total; i++)
        {
            dist[i] = INT_MAX;
        }

        // {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Source = 0
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            // Check all neighbours
            for (int v = 0; v < total; v++)
            {
                int wt = graph[node][v];

                if (d + wt < dist[v])
                {
                    dist[v] = d + wt;

                    pq.push({dist[v], v});
                }
            }
        }

        // Destination = 1
        cout << dist[1] << endl;
    }

    return 0;
}