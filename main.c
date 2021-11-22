#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void testingTerminalApp();

void testingTerminalPrint();

void helpTerminalPrint();

void kpTerminalPrint();

void companyTerminalPrint();

int main(int argc, char** argv) {
    testingTerminalApp();
    
    return 0;
}

void testingTerminalApp(){
    int choosed;
    node_t *root = NULL;
    node_t *iter = initIterator(root);
    helpTerminalPrint();
    printf("\n");
    while(1){
        printf("Your choice: ");
        scanf("%d",&choosed);
        switch(choosed){
            case 1:
                helpTerminalPrint();
                printf("\n");
                break;
            case 2:
                printf("Data for insert: ");
                scanf("%d",&choosed);
                root = insert(root, choosed);
                printf("\n");
                break;
            case 3:
                printf("Data for delete: ");
                scanf("%d",&choosed);
                root = deleteNode(root, choosed);
                printf("\n");
                break;
            case 4:
                printf("Print data: ");
                printAll(root);
                printf("\n\n");
                break;
            case 5:
                printf("Print tree graph:\n");
                treeImagePrint(root);
                printf("\n");
                break;
            case 6:
                printf("Reset iterator: ");
                iter = resetIterator(root, iter);
                printf("Done\n\n");
                break;
            case 7:
                printf("First item: ");
                iter = getFirstIterator(root, iter);
                if (iter == NULL){
                    printf("You must insert some data.\n\n");
                } else {
                    printf("%d\n\n", iter->data);
                }
                break;
            case 8:
                printf("Next item: ");
                iter = nextIterator(root, iter);
                if (iter == NULL) {
                    printf("End of data. Iterator has been reseted.\n\n");
                } else {
                    printf("%d\n\n", iter->data);
                }
                break;
            case 9:
                printf("Print for easy test all funkcionalities.");
                testingTerminalPrint();
                break;
            case 10:
                printf("Exit.\n");
                return;
                break;
            default:
                printf("Wrong choice.\n\n");
                break;
        }
    }
    return;
}

void testingTerminalPrint(){
    struct node *root = NULL;
    
    printf("Insert:\n50, 30, 20, 40, 70, 60, 80, 10, 90, 0, 100\n\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 90);
    root = insert(root, 0);
    root = insert(root, 100);

    
    printf("Print tree:\n");
    printAll(root);
    printf("\n\n");

    
    printf("Iterator:\n");
    struct node *iter = initIterator(root);
    for (int i = 0; i < 20; i++) {
        iter = nextIterator(root, iter);
        if (iter == NULL) printf("next: %p | ", (void *) iter);
        else printf("next: %d | ", iter->data);
    }
    printf("\n\n");

    
    printf("Trivial graph of tree:\n");
    treeImagePrint(root);
    printf("\n");
    
    
    root = deleteNode(root, 20);
    printf(" 20 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 70);
    printf(" 70 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 10);
    printf(" 10 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 60);
    printf(" 60 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 90);
    printf(" 90 deleted --> actual data: ");
    printAll(root);
    printf("\n");

    root = deleteNode(root, 40);
    printf(" 40 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 60);
    printf(" 60 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 30);
    printf(" 30 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 50);
    printf(" 50 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 0);
    printf("  0 deleted --> actual data: ");
    printAll(root);
    printf("\n");

    root = deleteNode(root, 100);
    printf("100 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    
    root = deleteNode(root, 80);
    printf(" 80 deleted --> actual data: ");
    printAll(root);
    printf("\n");
    printf("\n");
    
    
    treeFree(&root);
    printf("\nAfter tree_free() root is %p\n", (void *) root);

    return;
}

void helpTerminalPrint(){
    printf("\nOptions:\n");
    printf("\t 1.Help menu\n");
    printf("\t 2.Insert data\n");
    printf("\t 3.Delete data\n");
    printf("\t 4.Print sorted data\n");
    printf("\t 5.Print graph of tree\n");
    printf("\t 6.Reset iterator\n");
    printf("\t 7.Get first item\n");
    printf("\t 8.Get next item\n");
    printf("\t 9.Print fast test\n");
    printf("\t10.Exit\n");
}
