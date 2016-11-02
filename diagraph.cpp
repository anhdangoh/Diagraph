#include "../lib/diagraph.h"
#include <iostream>

vertex::vertex(int node_to_add){
  vertex_node = node_to_add;
  next_vertex = 0;
}

vertex* vertex::getTail(vertex* object){
  vertex* current = object;
  return current;
}

void vertex::addNext(int node_to_add){
  if (!next_vertex){
    next_vertex = new vertex;
    next_vertex->vertex_node = node_to_add;
    next_vertex->next_vertex = 0;
  }else{
    std::cout << "Current vertex is not the tail. No vertex added.";
  }
}


Diagraph::Diagraph(int num_of_vertex){
  this->num_of_vertex = num_of_vertex;
  head = 0;
}

void Diagraph::setHead(header* head){
  this->head = head;
}

void Diagraph::setEdges(int* edges_array, int array_size){
  for (int i = 0; i < array_size; i++){
    edges.push_back(edges_array[i]);
  }
}

//Add a new header of a specific number to the end
void Diagraph::addHeader(int new_header){
  if (!head){
    head = new header;
    head->header_node = new_header;
    head->next_vertex = 0;
    head->next_header = 0;
    return;
  }else{
    header* current = head;
    while (current->next_header){
      //traverse to the end
      current = current->next_header;
    }
    current->next_header = new header;
    current->next_header->header_node = new_header;
    current->next_header->next_header = 0;
    current->next_header->next_vertex = 0;
  }
}


//Add a new vertex of a specific number to a given header
//Input: header number, vertex number
void Diagraph::addNode(int at_header, int node_to_add){
  //Traverse to the given header
  header* current_header = head;
  while (current_header->next_header && current_header->header_node != at_header ){
    current_header = current_header->next_header;
  }
  if (!current_header->next_vertex){  //if this header has no vertex yet
    //add new vertex as the 1st
    current_header->next_vertex = new vertex;
    current_header->next_vertex->vertex_node =  node_to_add;
  }else{  //add after end node
    //traverse to end node
    vertex* current_vertex = current_header->next_vertex;
    while (current_vertex->next_vertex){
      current_vertex =current_vertex->next_vertex;
    }
    current_vertex->next_vertex = new vertex;
    current_vertex->next_vertex->vertex_node = node_to_add;
    current_vertex->next_vertex->next_vertex = 0;
  }
}


void Diagraph::setFullList(){
  //Do nothing and print error message if the graph is not empty
  if (!head){
    std::cout << "The graph is not empty.";
    return;
  }
  //set a new graph's list
  //add all headers
  for (int i = 0; i < num_of_vertex; i++){
    addHeader(i+1);
  }
  //add vertices
  for (int i = 0; i < edges.size(); i++){
    addNode(edges.at(2*i), edges.at(2*i+1));
  }
}


//ACCESS GRAPH
int Diagraph::getNumOfVertex(){
  return num_of_vertex;
}

header* Diagraph::getHead(){
  return head;
}


//PRINT GRAPH
//print a branch (of a header)
void Diagraph::printBranch(int at_header){
//vertex* current_node =
}
