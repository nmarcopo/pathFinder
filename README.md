# Data Structures Project: Path Finding
Originally submitted on April 20, 2018 to professor [Shreya Kumar](https://www3.nd.edu/~skumar5/).

# Addendum:
## You can run this project here: Not finished yet, come back soon!!
I'd like to say a huge "thank you" to my friend Andy, who really came in big time on this project. The week this project was due, I had a ton of other projects due as well. Thankfully, Andy had a little more time to spare, so he was able to contribute to this project more than I was, especially in regard to the write-up we needed at the end of the project.  
This is an implementation of Dijkstra's Algorithm visualized on a map. The tiles have certain weights to them, which allow the runner to take the "shortest path" through them.

# Team Members:
- Nicholas Marcopoli
- Sung Hyun "Andy" Shin

# Original README:
Nicholas Marcopoli nmarcopo, Sung Hyun Shin sshin1

Project 05: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

1. 
Web application works properly.

2. 
Generating random maps and moving runner works properly

3. Benchmarks:

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 0.002998 sec  | 1.207031 Mb    |
| 20            | 0.007997 sec  | 1.230469 Mb    |
| 50            | 0.042993 sec  | 1.371094 Mb    |
| 100           | 0.184971 sec  | 1.875000 Mb    |
| 200           | 0.802877 sec  | 3.832031 Mb    |
| 500           | 5.739127 sec  | 17.511719 Mb   |
| 1000          | 24.934210 sec | 66.253906 Mb   |

4. Post-Benchmark Questions:

We represented the map as a 2D array of integers. We translated the char’s given into integers stored into a 2D array with int *’s. 

Since the cost of the path is only from leaving a node, the edge between nodes was stored as the weight of the node being left. For example, maybe (0,0) would be stored as a 6, so going from (0,0) to (0,1) or (1,0) would cost 6 and the edge is 6.

The complexity of our implementation of Dijkstra’s Algorithm is O(E+V*log(V)). V is the number of nodes and E is the number of edges. 

This complexity is due to our use of a min-priority queue. Thus, the frontier (min-priority queue) will return lowest cost, making us not have to check every node twice, as Dijkstra’s without minimum priority queues does.

Our implementation scales fairly well, especially at low table sizes. When the table size became over 500, the times were much slower than before. This program is much better suited for smaller datasets (up to a 200x200 table), which it can consistently compute in under a second.

A larger size of the map inherently increases our Dijkstra’s algorithm in execution and memory usage. Larger maps require a larger 2D array to be stored, larger frontier, and larger marked map, which increases our memory usage. With larger maps, there are more edges and nodes to be checked to get to the end, which takes a longer execution time. Both memory usage and time complexity are increasing exponentially, but it makes sense because n-sized maps increase both column and row count, which is an exponential increase.
