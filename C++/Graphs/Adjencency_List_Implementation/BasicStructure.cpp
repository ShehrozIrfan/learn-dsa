//Following is the basic structure of graph implemented using adjencency list 
class Graph()
{
  private:
    int V;                                   //Total number of vertices
    list<int>* adj;                          //List to keep track of edges between vertices and to recurse through them
  public:
    Graph(int n)                             //Constructor that intializes the total number of vertices and the list adj
    {
        V = n;
        adj = new list<int>[V];
    }
    void TakeInput(int n, int w)             //Add edge between n and w that are the given vertices
    {
        adj[n].push_back(w);                 //Incase of directed graph only add an edge from n to w
        adj[w].push_back(n);
    }
    //We will do itterations seperately as they are of different types
}
