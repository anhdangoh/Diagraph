#include "./lib/diagraph.h"
#include <iostream>


using namespace std;

int main(){
  Diagraph graph(2);
  graph.addHeader(1);
  cout << graph.getHead()->header_node << endl;
  graph.addNode(1, 3);
  cout << graph.getHead()->next_vertex->vertex_node << endl;
  return 0;
}
