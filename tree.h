#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

    #include <stdio.h>
    #include <stdlib.h>

    typedef struct node {
        int data;
        struct node *left;
        struct node *right;
    } node_t;

    /*Tree private methods.*/
    node_t* newNodePrivate(int data);
    
    node_t* minValueNodePrivate(node_t *root);
    
    node_t* maxValueNodePrivate(node_t *root);
    
    int treeSizePrivate(node_t *root);
    
    int treeMaxDepthPrivate(node_t *root);
    
    void printDepthPrivate(int depth, int cur_depth, node_t *root);
    
    
    /*Tree public methods.*/
    node_t* insert(node_t* root, int data);
    
    node_t* deleteNode(struct node* root, int data);
    
    void treeFree(node_t **tree);
    
    void printAll(node_t *root);
    
    void treeImagePrint(node_t *root);

    
    
    
    /*Iterator private methods.*/
    node_t* getParentHelperPrivate(node_t* currentRoot, node_t* child);
    
    node_t* getParentPrivate(node_t* root, node_t* child);
    
    
    /*Iterator public methods.*/
    node_t* initIterator(node_t* root);
    
    node_t* nextIterator(node_t* root, node_t* iter);
    
    node_t* resetIterator(node_t* root, node_t* iter);
    
    node_t* getFirstIterator(node_t* root, node_t* iter);
    
    
#ifdef __cplusplus
}
#endif

#endif /* TREE_H */

