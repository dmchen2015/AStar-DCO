#ifndef NODE_H
#define NODE_H

#include <cfloat>
//That's the data structure for storing a single search node.
//Although one might realize A* pathfinder relying only on g-value,
//it's a good idea to store f- and h-values explicitly for the sake of simplicity
//(and either h- or f-value is definetely needed for realizing different tie-breaking strategies).
//Backpointer is obligatory for any-angle algorithms, e.g. Theta*, and it makes sense to utilize it
//in A*-like algorithms as well for reconstructing path (after the main search phase is finished).

//So, in the end of the day, we have a sort of "universal" search-node structure
//compatable with various types of grid pathfinders (Dijkstra, A*, Jump Point Search, Theta* etc.)
//which means - that's all you need for that project.

struct Node
{
    int     i, j; //grid cell coordinates
    double  F, g, H; //f-, g- and h-values of the search node
    Node    *parent; //backpointer to the predecessor node (e.g. the node which g-value was used to set the g-velue of the current node)
    bool br;

    bool operator == (const Node &other) const
    {
        return i == other.i && j == other.j;
    }

    Node()
    {

        i = -1;
        j = -1;
        g = DBL_MAX;
        H = 0;
        F = DBL_MAX;
        parent = nullptr;

    }

    Node(Node const& a )
    {
        i = a.i;
        j = a.j;
        g = a.g;
        H = a.H;
        F = a.F;
        parent = a.parent;
        br = a.br;
    }

    ~Node()
    {

    }
};
#endif
