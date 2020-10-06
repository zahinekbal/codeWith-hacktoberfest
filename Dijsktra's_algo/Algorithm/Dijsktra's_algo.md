# Dijsktra's Algorithm

<p>&nbsp;</p>


## What is Dijsktra's Algorithm? 
Dijkstra's Algorithm allows you to calculate the shortest path between one node (you pick which one) and every other node in the graph.
Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. Like Prim’s MST, we generate a SPT (shortest path tree) with given source as root. We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.
<p>&nbsp;</p>





## Why Dijsktra's Algorithm?
- It is used in IP routing to find Open shortest Path First.

- It is used in finding Shortest Path.

- To find locations of Map which refers to vertices of graph.

- Distance between the location refers to edges.
<p>&nbsp;</p>

## Some Cons of Dijsktra's Algorithm
- It do blind search so wastes lot of time while processing.
- It cannot handle negative edges
- This leads to acyclic graphs and most often cannot obtain the right shortest path.

<p>&nbsp;</p>

## Explanation
Let the node at which we are starting be called the initial node. Let the distance of node Y be the distance from the initial node to Y. Dijkstra's algorithm will assign some initial distance values and will try to improve them step by step. 

1. Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.
    



2. Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes. Set the initial node as current.

    

3. For the current node, consider all of its unvisited neighbours and calculate their tentative distances through the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbour B has length 2, then the distance to B through A will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, the current value will be kept.


4. When we are done considering all of the unvisited neighbours of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.

5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.   

6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.
<p>&nbsp;</p>

## Example

Let us trace the above algorithm using an example:

Consider the following inputs:

<img src="images/dj1.jpg" width=300px alt="represent"></img>

Step 1: The set sptSet is initially empty and distances assigned to vertices are {0, INF, INF, INF, INF, INF, INF, INF} where INF indicates infinite. Now pick the vertex with minimum distance value. The vertex 0 is picked, include it in sptSet. So sptSet becomes {0}. After including 0 to sptSet, update distance values of its adjacent vertices. Adjacent vertices of 0 are 1 and 7. The distance values of 1 and 7 are updated as 4 and 8. Following subgraph shows vertices and their distance values, only the vertices with finite distance values are shown. The vertices included in SPT are shown in green colour.

<img src="images/dj2.jpg" width=200px alt="represent"></img>




Step 2: Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). The vertex 1 is picked and added to sptSet. So sptSet now becomes {0, 1}. Update the distance values of adjacent vertices of 1. The distance value of vertex 2 becomes 12.
   
 <img src="images/dj3.jpg" width=200px alt="represent"></img>



Step 3: Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). Vertex 7 is picked. So sptSet now becomes {0, 1, 7}. Update the distance values of adjacent vertices of 7. The distance value of vertex 6 and 8 becomes finite (15 and 9 respectively).
  
  <img src="images/dj4.jpg" width=200px alt="represent"></img>


Step 4: Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). Vertex 6 is picked. So sptSet now becomes {0, 1, 7, 6}. Update the distance values of adjacent vertices of 6. The distance value of vertex 5 and 8 are updated.

<img src="images/dj5.jpg" width=300px alt="represent"></img>



Step 5: We repeat the above steps until sptSet does include all vertices of given graph. Finally, we get the following Shortest Path Tree (SPT).
 
 <img src="images/dj6.jpg" width=300px alt="represent"></img>







      
         

## Psuedo Code

<p>&nbsp;</p>

  
    function Dijkstra(Graph, source):
 
        create vertex set Q
 
        for each vertex v in Graph:            
           dist[v] ← INFINITY                 
           prev[v] ← UNDEFINED                
           add v to Q                     
       dist[source] ← 0                       
     
       while Q is not empty:
          u ← vertex in Q with min dist[u]   
                                             
          remove u from Q
         
          for each neighbor v of u:           // only v that are still in Q
              alt ← dist[u] + length(u, v)
              if alt < dist[v]:              
                  dist[v] ← alt
                  prev[v] ← u

       return dist[], prev[]
