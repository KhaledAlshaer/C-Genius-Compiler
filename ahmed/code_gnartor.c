#include "header.h"

void generat()
{
    FILE *file = fopen("as.s", "w");
    ExpressionNode *cur = root->child;
    while (cur != NULL)
    {
        if (cur->token.type ==)
        {
        }
    }
}

void generat_main(ExpressionNode *cur, FILE *f)
{

    fprintf(f, "\
.global main\n\
.intel_syntax noprefix\n\
main:\n\
");
}
void generat_return(ExpressionNode *cur, FILE *f)
{
    fprintf(f, "\
\tmov rax, 60\n\
\tmov rdi, %s\n\
\tsyscall\n\
",
            cur->next->next->token.value);
}

int main()
{
    generat();
}
