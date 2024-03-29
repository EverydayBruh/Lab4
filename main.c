#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "InOut.h"
#include "timing.h"

void inteface(Node* root){
    int switcher = 1;
    int k = 1;
    int number;
    char* s;
    FILE* fb = NULL;
    KeyType min;
    KeyType max;
    KeyType key;
    InfoType info;
    Node* node;
    while(switcher!=9){
        printf("\n\n1. Add Element \n2. Find by key \n3. Special Search \n4. Tree Traversal \n5. Delete Element \n6. Print Tree \n7. Read frok File \n8. Timing \n9. Exit\n");
        readPositive(&switcher);
        printf("\n");

        switch(switcher){
            case 1:
                printf("Enter key:   ");
                key = readKey();
                printf("Enter info:   ");
                info = readInfo();   
                root = addElement(root, key, info);
                break;
            
            case 2:
                printf("Enter key:   ");
                key = readKey();
                printf("Enter number:   ");
                readint(&number);
                k = 0;
                node = findByKey(root, key, &k, number);
                if(node)
                   printNode(node);
                else
                    printf("No results");
                free(key);
                // newTable2 = getItems2(table2, key);
                // printTable2(newTable2);
                // delTable2(newTable2);
                break;
            
            case 3:
                printf("Enter key:   ");
                key = readKey();
                printf("Enter number:   ");
                readint(&number);
                node = spetialSearch(root, key, number);
                if(node)
                   printNode(node);
                else
                    printf("No results");
                free(key);
                // newTable2 = getItemByVer2(table2, key, release);
                // printTable2(newTable2);
                // delTable2(newTable2);
                break;

            case 4:
                printf("Enter min:   ");
                min = readKey();
                printf("Enter max:   ");
                max = readKey();
                treeTraversal(root, min, max);
                free(min);
                free(max);
                break;

            case 5:
                printf("Enter key:   ");
                key = readKey();
                printf("Enter number:   ");
                readint(&number);
                k = deleteNode(root, key, number);
                if(!k)
                    printf("Success!\n");
                else
                    printf("Can't find\n");
                free(key);
                break;

            case 6:
                printTree(root, 0);
                break;

            case 7:
                printf("File name:  ");
                s = read_line();
                fb = fopen(s, "r");
                free(s);
                if(fb != NULL)
                {
                    freeTree(root);
                    root = readFromFile(fb);
                } else {
                    printf("Can't find the file");
                }
                printTree(root, 0);
                fclose(fb);
                break;

            case 8:
                timing();
                break;

            case 9:
                freeTree(root);
                break;

            default:
                printf("Incorrect value\n");
                break;


        }
    }

}

int main(){
    Node* root = NULL;
    inteface(root);
    return 0;


}