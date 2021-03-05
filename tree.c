#include "tree.h"

/*____TREE____*/
/*PRIVATE METHODS FOR TREE.*/
node_t* newNodePrivate(int data) {
    struct node *temp = (node_t *) malloc(sizeof (struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


node_t* minValueNodePrivate(node_t *root) {
    if (root == NULL) return NULL;
    struct node* current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}


node_t* maxValueNodePrivate(node_t *root) {
    struct node *current = root;

    while (current->right != NULL) {
        current = current->right;
    }

    return current;
}


int treeSizePrivate(node_t *root) {
    int ret;
    
    if (root == NULL) {
        ret = 0;
    } else {
        ret = treeSizePrivate(root->left) + 1 + treeSizePrivate(root->right);
    }
    return ret;
    //return node == NULL ? 0 : tree_size(node->left) + 1 + tree_size(node->right);
}


int treeMaxDepthPrivate(node_t *root) {
    if (root != NULL) {
        const int left_depth = treeMaxDepthPrivate(root->left);
        const int right_depth = treeMaxDepthPrivate(root->right);
        
        if (left_depth > right_depth) {
            return left_depth + 1;
        } else {
            return right_depth + 1;
        }
        //return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    } else {
        return 0;
    }
}


void printDepthPrivate(int depth, int cur_depth, node_t *node) {
    if (depth == cur_depth) {
        if (node) {
            printf("%2d ", node->data);
        } else {
            printf(" - ");
        }
    } else if (node) {
        printDepthPrivate(depth, cur_depth + 1, node->left);
        printDepthPrivate(depth, cur_depth + 1, node->right);
    }
}


/*PUBLIC METHODS FOR TREE.*/
node_t* insert(node_t *root, int data) {
    if (root == NULL) {
        return newNodePrivate(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}


node_t* deleteNode(node_t *root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNodePrivate(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void treeFree(node_t **tree) {
    if (tree && *tree) {
        node_t * node = *tree;

        if (node->left) {
            treeFree(&(node->left));
        }

        if (node->right) {
            treeFree(&(node->right));
        }

        free(*tree);
        *tree = NULL;
    }
}


void printAll(node_t *root) {
    if (root != NULL) {
        printAll(root->left);
        printf("%d ", root->data);
        printAll(root->right);
    }
}


void treeImagePrint(node_t *node) {
    const int depth = treeMaxDepthPrivate(node);

    for (int i = 0; i <= depth; ++i) {
        printDepthPrivate(i, 0, node);
        printf("\n");
    }
}




/*____ITERATOR____*/
/*PRIVATE METHODS FOR ITERATOR.*/
node_t* getParentHelperPrivate(node_t *currentRoot, node_t *child) {
    if (currentRoot->left == child || currentRoot->right == child) {
        return currentRoot;
    }
    if (currentRoot->data < child->data) {
        return getParentHelperPrivate(currentRoot->right, child);
    } else {
        return getParentHelperPrivate(currentRoot->left, child);
    }

    return NULL;
}


node_t* getParentPrivate(struct node* root, struct node* child) {
    if (root == child || root == NULL) {
        return NULL;
    }

    return getParentHelperPrivate(root, child);
}


/*PUBLIC METHOD FOR ITERATOR.*/
node_t* initIterator(struct node* root) {
    struct node* iter = NULL;
    return iter;
}


node_t* resetIterator(struct node* root, struct node* iter) {
    iter = NULL;
    return iter;
}


node_t* getFirstIterator(struct node* root, struct node* iter) {
    iter = minValueNodePrivate(root);
    return iter;
}


node_t* nextIterator(struct node* root, struct node* iter) {
    if (root == NULL) return NULL;
    if (iter == NULL) {
        iter = minValueNodePrivate(root);
        return iter;
    }

    if (iter == maxValueNodePrivate(root)) {
        iter = NULL;
        return iter;
    }

    if (iter->right != NULL) {
        iter = iter->right;
    
        while (iter->left != NULL) {
            iter = iter->left;
        }
        
        return iter;
    } else {
        struct node *parent = getParentPrivate(root, iter);
        while (parent->right == iter) {
            iter = parent;
            parent = getParentPrivate(root, iter);
        }
        
        iter = parent;
        return iter;
    }
}
