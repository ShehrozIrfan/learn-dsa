//Incase of BFS we will make use of queue and will implement following idea
//Take a start vertex
//Check all neighbours and push them onto queue
//now take the first neighbour and push all neighbours onto queue and so on

void BFS()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) 
          visited[i] = false;
    list<int> queue; // Create a queue for BFS
    
    //The outer loop will keep track of all disconnected nodes
    for(int i=0; i<V; i++){
    if (!visited[i]){
      
    visited[i] = true; // Mark the node as visited and enqueue it
    queue.push_back(i);// As we discussed
      
    list<int>::iterator ite;
      while (!queue.empty()){
           i = queue.front(); // Dequeue a vertex from queue & print it
           cout << i << " ";
           queue.pop_front();

                               // Get all adjacent vertices of the dequeued vertex i. If an adjacent vertex is not visited,then mark it visited and enqueue it
      for (ite = adj[i].begin(); ite != adj[i].end(); ++ite){
            if (!visited[*ite]){
               visited[*ite] = true;//mark the neighbours and push them onto queue
               queue.push_back(*ite);
               }

            }
       }
    }
    delete [] visited;
}
