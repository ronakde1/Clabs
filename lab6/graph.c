#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) { 
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}


/* Basic Problems */

int size(Node *node) { 
  if (node == NULL) {return 0;}
  if (node -> marked){
    return 0;
  }
  node -> marked = true;
  return 1 + size(node->left) + size(node->right);
  /* TODO */

}


void unmark(Node *node) { 
  if (node == NULL) {return;}
  if (node -> marked) {
    node-> marked = false;
    unmark(node->left);
    unmark(node-> right);
  }
  return;
  /* TODO */
}

bool path_from(Node *node1, Node *node2) {
  if (node1 == NULL) {return false;}
  if (node1 == node2) {return true;}
  if (node1->marked) {return false;}
  node1->marked = true;
  return (path_from(node1->left,node2) || path_from(node1->right,node2));
  /* TODO */
}

bool on_path(Node *node, Node* path[], int path_len){
  for (int i = 0; i < path_len; i++) {

    if (path[i]==node){return true;}
  }
  return false;
}

//find a node and mark. if node is null, make node not marked 
// call function and then reset node back to unmarked 
bool cyclic_aux(Node *node, Node* path[], int path_len){

  if (node == NULL) {return false;}
  if (on_path(node,path,path_len)){
    return true;
  }
  if (node-> marked){return false;}


  
  
  path[path_len] = node;
  
   if (cyclic_aux(node->left, path, path_len + 1) || cyclic_aux(node->right, path, path_len + 1)) {
        return true;
    }
    node-> marked = true;
    return false;
}
bool cyclic2(Node *node) { 
  if (node == NULL) return false;
  unmark(node);
  int max_path = size(node);
  unmark(node);
  Node* path_stack[max_path];

  /* TODO */
  return cyclic_aux(node,path_stack,0);
}


bool cyclic(Node *node){
  if (node == NULL){return false;}
  return path_from(node->right,node) || path_from(node->left,node);
}


/* Challenge problems */

int get_nodes_aux(Node *node, Node **dest, int top){
  if (node==NULL){return top;}
  if (node->marked){return top;}
  dest[top++] = node;
  node->marked = true;
  top = get_nodes_aux(node->left, dest, top);
  top = get_nodes_aux(node->right, dest, top);
  return top;
}

void get_nodes(Node *node, Node **dest) { 
  unmark(node);
    /* TODO */
  get_nodes_aux(node, dest, 0);
}

void graph_free(Node *node) { 
  unmark(node);

  int num = size(node);
  Node* dest[num];
  unmark(node);
  int iterate = get_nodes_aux(node,dest,0);
  for (int i = 0; i < iterate;i++){
    free(dest[i]);
  }
  /* TODO */
}


