// Problem - Minimum number of dice throws required to reach the destination 36 starting from the source. Find the shortest path as well.

// There are S snakes and L ladders. Given will be starting and ending point of a snake. For example, 12(start) 34(end) - for snakes .... 2 to 15 (for ladders)

// verties are 0 - 36 (total - 37)
#include <iostream>
#include <map>

using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    void bfs(T src, T dest)
    {
        // src is the starting node
        map<T, int> dist;
        queue<T> q;

        //all the other nodes except the source node will have the distance of infinity
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);

        //source node will have the distance 0
        dist[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            for (int nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);

                    //mark the neighbor as visited
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        // Print the distance to destination node
        return dist[dest];
    }
};

int main()
{
    int board[50] = {0};

    //snakes and ladders
    board[2] = 13;
    board[5] = 2;
    board[9] = 10;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //add all edges to the graph
    Graph<int> g;
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }

    g.addEdge(36, 36);

    g.bfs(0, 36);

    return 0;
}