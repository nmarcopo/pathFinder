// dijsktras.cpp
// Sung Hyun Shin & Nicholas Marcopoli
#include <iostream>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Compare function for minimum priority queue containing tuple's
struct Compare{
    public:
        bool operator()(tuple<int, pair<int, int>, pair<int, 
        int>>n1, tuple<int, pair<int, int>, pair<int, int>>n2){
            return get<0>(n1) > get<0>(n2);
        }
};

// Dijkstra's Algorithm
void dijkstras(int **graph, pair<int, int> runnerStart, pair<int, int> runnerEnd,int cols, int rows){
    
    // frontier is a priority queue with cost, destination, source
    priority_queue<tuple<int, pair<int, int>, pair<int, int> >, vector< tuple< int, pair<int, int>, pair<int, int> > >, Compare> frontier;
    map <pair<int,int>,pair<pair<int,int>,int>> marked; // key is destination, value is pair of source and cost
    int x; // path cost
    pair<int, int> v, u; // node v is the node that node u is going to. v is destination, u is source
    vector<pair<int,int>> ans; //path

    // start point pushed
    frontier.push(make_tuple(graph[runnerStart.first][runnerStart.second], runnerStart, runnerStart)); // cost, destination, source
    
    while(!frontier.empty()){
        x = get<0>(frontier.top());
        v = get<1>(frontier.top());
        u = get<2>(frontier.top());
        frontier.pop();

        // if not in marked
        if(marked.find(v) != marked.end()){
            continue;
        }
        
        marked[v]=make_pair(u,x);
        
        // if end point, end
        if(v == runnerEnd){
            break;
        }
        
        // add edges
        if(v.second-1 >= 0){
            frontier.push(make_tuple(graph[v.first][v.second-1]+x,make_pair(v.first,v.second-1),v));
        }
        if(v.first-1 >= 0){
            frontier.push(make_tuple(graph[v.first-1][v.second]+x,make_pair(v.first-1,v.second),v));
        }
        if(v.second+1 != cols){
            frontier.push(make_tuple(graph[v.first][v.second+1]+x,make_pair(v.first,v.second+1),v));
        }
        if(v.first+1 != rows){
            frontier.push(make_tuple(graph[v.first+1][v.second]+x,make_pair(v.first+1,v.second),v));
        }
    }
    
    // path doesn't include cost of the end node
    marked[v].second = marked[v].second - graph[v.first][v.second];
    
    // printing total cost
    cout << marked[v].second << endl;
    
    // going through path backwards
    while(v != runnerStart){
        ans.insert(ans.begin(),v);
        v = marked[v].first;
    }
    // inserting start
    ans.insert(ans.begin(),runnerStart);
    //printing path
    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}

// Main Execution

int main(int argc, char *argv[]) {

    // Check if next item is the end of file
    while(cin.peek() != EOF){
        // get number of unique tiles used
        string TILES_N_STRING;
        getline(cin, TILES_N_STRING);
        int TILES_N = stoi(TILES_N_STRING);

        // get weights of each tile and insert into map
        map<char, int>  weightsMap;
        for(int i = 0; i < TILES_N; i++){
            char tile, weight;
            cin >> tile;
            cin >> weight;
            pair<char, int> weightPair = make_pair(tile, (int)(weight - '0'));
            weightsMap.insert(weightPair);
        }

        // get rows and cols of table
        string rows_str, cols_str;
        cin >> rows_str;
        cin >> cols_str;
        int rows, cols;
        rows = stoi(rows_str);
        cols = stoi(cols_str);

        // constructor
        int **tileTable = new int*[rows];
        for(int i = 0; i < rows; i++){
            tileTable[i] = new int[cols];
        }

        // fill table
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                char tmp;
                cin >> tmp;
                tileTable[i][j] = weightsMap[tmp];
            }
        }

        // parse runner start and end
        pair<int,int> RUNNER_START;
        pair<int,int> RUNNER_END;

        cin >> RUNNER_START.first >> RUNNER_START.second;
        cin >> RUNNER_END.first >> RUNNER_END.second;
        cin.ignore(256,'\n');
        
        dijkstras(tileTable, RUNNER_START, RUNNER_END, cols, rows);
        
        // deconstructor
        for(int i = 0; i < rows; i++){
            delete[] tileTable[i];
        }
        delete[] tileTable;
    }

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
