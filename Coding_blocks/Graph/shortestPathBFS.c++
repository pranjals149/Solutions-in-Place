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
        l[y].push_back(x);
    }

    void bfs(T src)
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

        // Print the distance to every node
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node " << node << " D from src" << d << endl;
        }
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);

    return 0;
}
