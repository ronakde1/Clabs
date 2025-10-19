#include <stdlib.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) { 
  if (tree == NULL){
    return 0; 
    }
  if (x == tree-> value){
    return 1;
  }
  else if (x < tree->value) {
    return tree_member(x,tree->left);
    }
  else {
    return tree_member(x,tree->right);
    }
  
  /* TODO */
  return 0;
}

Tree *tree_insert(int x, Tree *tree) { 
  /* TODO */
  if (tree == NULL){
    Tree *tree = malloc(sizeof(Tree));
    *tree = (Tree) { .left = NULL, .value = x, .right = NULL };
    return tree;
  }
  else if (x < tree->value) {
    tree-> left = tree_insert(x,tree->left);
    }
  else {
     tree-> right = tree_insert(x,tree->right);
    }
  return tree;
}

void tree_free(Tree *tree) { 
  if (tree == NULL){ return;}
  else {
    tree_free(tree->left);
    tree_free(tree->right);
    free(tree);
  }
  /* TODO */
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
  /* TODO */
  if (tree == NULL) {
    *new_tree = NULL;
    return;
  } 
  if (tree->left == NULL) {
        *min = tree->value;
        *new_tree = tree->right;
        free(tree);
        return;
    }
    pop_minimum(tree->left, min, &(tree->left));
    *new_tree = tree;
}

Tree *tree_remove(int x, Tree *tree) { 
    if (tree == NULL) {
        return tree; 
    }

    if (x == tree->value) {
        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            return NULL;
        }
        else if (tree->left == NULL) {
            Tree *right = tree->right;
            free(tree);
            return right;
        }
        else if (tree->right == NULL) {
            Tree *left = tree->left;
            free(tree);
            return left;
        }
        else {
            int min;
            Tree *new_right;
            pop_minimum(tree->right, &min, &new_right);
            tree->value = min;
            tree->right = new_right;
            return tree;
        }
    } 
    else if (x < tree->value) {
        tree->left = tree_remove(x, tree->left);
    } 
    else {
        tree->right = tree_remove(x, tree->right);
    }

    return tree;
}
