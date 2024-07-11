#include "header.h"

Token tokens[MAX_SIZE];
int TokenCount = 0;
int TokenIndex = 0;
ROOT *root;

/**
 * 
 * 
 */
int main()
{
    FILE *file;

    file = fopen("test.c", "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file for reading\n");
        return(1);
    }

    lexer(file);

    for (int i = 0; i < TokenCount; i++)
    {
        printf("%s\n", tokens[i].value);
    }
    
    fclose(file);

    parser();

    file = fopen("as.s", "w");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file for writing\n");
        return(1);
    }

    generate(file);

    free_root_node(root);

    /**for (int i < 0; i < TokenCount; i++)
    {
        free(tokens[i].value);
    }*/

    return(0);
}
