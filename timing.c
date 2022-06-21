#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "InOut.h"

char *randString(int length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789               ";
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            for (int i = 0;i < length;i++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[i] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}

Node* randTree(Node* root, int size)
{
    KeyType key;
    InfoType info;

    for(int i = 0; i < size; i++)
    {
        key = randString(10);
        info = randString(10);
        root = addElement(root, key, info);
    }
    return root;
}

int timing(int n)
{
    clock_t time1;
    clock_t time2;
    char* s;
    Node* root = NULL;
    switch (n)
    {
    case 1:
        s = "timtingAdd";
        break;
    case 2:
        s = "timtingFind";
        break;
    case 3:
        s = "timtingDelete";
        break;

    default:
        printf("Wrong timing code\n");
        break;
    }
    FILE* fb = fopen(s, "w");
    fprintf(fb, "Tree_Size\tTime\n");

    for(int i = 100000; i<=2000000; i+=100000)
    {
        root = randTree(root, 100000);
        // printTree(root, 0);
        switch (n)
        {
            case 1:
                time1 = clock();
                for (int j = 0; j < 100000; j++)
                {
                    addElement(root, randString(10), randString(10));
                }
                break;
            case 2:
                time1 = clock();
                int k = 0;
                for (int j = 0; j < 100000; j++)
                {
                    findByKey(root, randString(10), &k, 1);
                }
                break;
            case 3:
                time1 = clock();
                for (int j = 0; j < 100000; j++)
                {
                    deleteNode(root, randString(10), 1);
                }
                break;
        }
        time2 = clock();
        // fprintf(fb, "%d\t%d\n", i, time2 - time1);
        fprintf(fb, "%d\t%f\n", i, ( (float) time2 - time1) / CLOCKS_PER_SEC);
        
    }
    freeTree(root);
    fclose(fb);
    return 1;
}