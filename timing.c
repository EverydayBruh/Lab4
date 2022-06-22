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

int timing()
{
    clock_t time1;
    clock_t time2;
    char* s;
    int k;
    FILE* fb;
    Node* root = NULL;
    char* key;
    for(int n = 1; n<=3; n++)
    {
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
        }
        
        fb = fopen(s, "w");
        fprintf(fb, "Tree_Size\tTime\n");
        fclose(fb);
    }
    for(int i = 20000; i<=400000; i+=20000)
    {
        root = randTree(root, 20000);
        // printTree(root, 0);
        for(int n = 1; n<=3; n++)
        {
            switch (n)
            {
                case 1:
                    s = "timtingAdd";
                    time1 = clock();
                    for (int j = 0; j < 1000; j++)
                    {
                        addElement(root, randString(10), randString(10));
                    }
                    break;
                case 2:
                    s = "timtingFind";
                    time1 = clock();
                    for (int j = 0; j < 1000; j++)
                    {
                        key = randString(10);
                        k = 0;
                        findByKey(root, key, &k, 1);
                        free(key);
                    }
                    break;
                case 3:
                    s = "timtingDelete";
                    time1 = clock();
                    for (int j = 0; j < 1000; j++)
                    {
                        key = randString(10);
                        deleteNode(root, key, 1);
                        free(key);
                    }
                    break;
            }
            time2 = clock();
            // fprintf(fb, "%d\t%d\n", i, time2 - time1);
            fb = fopen(s, "a");
            fprintf(fb, "%d\t%f\n", i, ( (float) time2 - time1) / CLOCKS_PER_SEC);
            fclose(fb);
        }
    }
    free(s);
    freeTree(root);
    return 1;
}