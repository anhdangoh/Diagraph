#include <vector>

class vertex{
public:
  int vertex_node;
  vertex* next_vertex;

  vertex(int);
  vertex* getTail(vertex*);
  void addNext(int);
};


class header{
public:
  int header_node;
  header* next_header;
  vertex* next_vertex;

  header(int);
  header* getTail(header*);
  void addNext(int);
};


class Diagraph{
  int num_of_vertex;
  std::vector <int> edges;
  header* head;

public:
  //SET GRAPH
  Diagraph(int);
  void setHead(header*);  //set the head to an existing list
  //Assign the whole array of edges to edges vector
  //Input: array, num of edges
  void setEdges(int*, int);
  void addHeader(int);  //add a new header at the back with node number
  //add a new vertex on a given header branch
  //Input: header number, vertex number
  void addNode(int, int);
  //Create a linked list of all nodes
  void setFullList(); //create the whole adjacency linked list from edges

  //ACCESS GRAPH
  int getNumOfVertex();
  header* getHead();

  //PRINT GRAPH
  //print a branch, input: header number
  void printBranch(int);
  //print the whole linked list of graph
  void printFullList();

  //operations of graph
  int** adjacencyMatrix();

  //Return corresponding parent array of a given root
  //Input: vertex number as given root
  int* parentInBreadth(int);
  int* parentOutBreadth(int);
  int* parentInDepth(int);
  int* parentOutDepth(int);

};
