//Following code is used to Itterate through graphs implemented using adjencency list using DFS recursively

void DFS(int V)//Total vertices V
{
  bool* visited = new bool[V]; // create a boolean array on heap to keep track of vertices
  for(int i=0 ;i<V ; i++)      // init to false
  {
    visited[i] = false;
  }
  // Now focus on code below
  //Notice that outer loop will keep track of disconnected Nodes
  //While the inner loop inside DFSHelp will keep track of all vertices that are connected
  //Keep this in mind as this will be useful in our future endeavours 
  for(int i=0 ;i<V ; i++)
  {
    //if Not visited the vertex is marked as visited and checks all Nodes that are connected to that vertix
    if(!visited[i])
    {
      DFSHelp(i,visited);
    }
  }
  
}
void DFSHelp(int v,bool visited[])
{
  // marks the Node as visited
  visited[v] = true;
  
  cout << v << endl;
  // checks all other nodes in following loop and calls recursively accordingly
  list<int>::iterator ite;
  for(ite = adj[v].begin(); ite!= adj[v].end();i++)
  {
    if(!visited[*i])
    {
      DFSHelp(*i,visited);
    }
  }
}
