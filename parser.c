#include "header.h"

//Token tokens[MAX_SIZE];
//int TokenCount = 0;
//int TokenIndex = 0;

typedef struct ExpressionNode 
{
    Token token;
    struct ExpressionNode *child;
} ExpressionNode;

typedef struct TokenNode 
{
    Token token;
    struct TokenNode *next;
} TokenNode;

ExpressionNode *create_expression_node(Token token, ExpressionNode *child)
{
    ExpressionNode *node = (ExpressionNode *)malloc(sizeof(ExpressionNode));
    if (node == NULL)
    {
        perror("Failed to allocate memory for ExpressionNode");
        exit(EXIT_FAILURE);
    }

    node->token = token;
    node->child = child;

    return(node);
}

TokenNode *create_token_node(Token token, TokenNode *next)
{
    TokenNode *node = (TokenNode *)malloc(sizeof(TokenNode));
    if (node == NULL)
    {
        perror("Failed to allocate memory for TokenNode");
        exit(EXIT_FAILURE);
    }

    node->token = token;
    node->next = next;

    return(node);
}

/**
 * parser - The Main Parser Function
 */
void parser()
{
}



void parse_return ()
{

    if (TokenIndex >= TokenCount)
    {
        fprintf(stderr, "Error: Reached end of tokens :')\n");
        return;
    }

    if (strcmp(tokens[TokenIndex].value, "return") == 0)
    {
        Token retToken = {TOKEN_RETURN, "return"};

        ExpressionNode *ret = create_expression_node(retToken, NULL);
        TokenIndex++;

        if (TokenIndex >= TokenCount)
        {
            fprintf(stderr, "Error: Unexpected end of tokens :')\n");
            return;
        }

        if (strcmp(tokens[TokenIndex].value, "(") == 0)
        {
            Token openParenToken = {TOKEN_OPEN_PAREN, "("};

            TokenNode *openParen = create_token_node(openParenToken, NULL);
            TokenIndex++;

            if (TokenIndex >= TokenCount)
            {
                fprintf(stderr, "Error: Unexpected end of tokens :')\n");
                return;
            }

            if (tokens[TokenIndex].type == TOKEN_LITERAL_INT)
            {
                Token valToken = {TOKEN_LITERAL_INT, tokens[TokenIndex].value};

                TokenNode *val = create_token_node(valToken, NULL);
                TokenIndex++;

                if (TokenIndex >= TokenCount)
                {
                    fprintf(stderr, "Error: Unexpected end of tokens :')\n");
                    return;
                }

                if (strcmp(tokens[TokenIndex].value, ")") == 0)
                {
                    Token closeParenToken = {TOKEN_CLOSE_PAREN, ")"};

                    TokenNode *closeParen = create_token_node(closeParenToken, NULL);
                    TokenIndex++;

                    if (TokenIndex >= TokenCount)
                    {
                        fprintf(stderr, "Error: Unexpected end of tokens :')\n");
                        return;
                    }

                    if (strcmp(tokens[TokenIndex].value, ";") == 0)
                    {
                        Token scolonToken = {TOKEN_SEMICOLON, ";"};

                        TokenNode *scolon = create_token_node(scolonToken, NULL);

                        openParen->next = val;
                        val->next = closeParen;
                        closeParen->next = scolon;
                        ret->child = (ExpressionNode *) openParen;
                        
                        printf("Correct Return Statment horaaaaay!!\n");
                        return;
                    }
                }
            }
        }
    }

    fprintf(stderr, "Syntax Error: Invalid Return Statment :')\n");
}


void parse_main()
{
    if (TokenIndex >= TokenCount)
    {
        fprintf(stderr, "Error: Reached end of tokens :')\n");
        return;
    }

    if (strcmp(tokens[TokenIndex].value, "int") == 0)
    {
        Token INT_Token = {TOKEN_INT, "int"};

        ExpressionNode *INT = create_expression_node(INT_Token, NULL);
        TokenIndex++;

        if (TokenIndex >= TokenCount)
        {
            fprintf(stderr, "Error: Reached end of tokens :')\n");
            return;
        }

        if (strcmp(tokens[TokenIndex].value, "main") == 0)
        {
            Token MAINToken = {TOKEN_MAIN, "main"};

            TokenNode *MAIN = create_token_node(MAINToken, NULL);
            TokenIndex++;

            if (TokenIndex >= TokenCount)
            {
                fprintf(stderr, "Error: Reached end of tokens :')\n");
                return;
            }

            if (strcmp(tokens[TokenIndex].value, "(") == 0)
            {
                Token openParenToken = {TOKEN_OPEN_PAREN, "("};

                TokenNode *openParen = create_token_node(openParenToken, NULL);
                TokenIndex++;

                if (TokenIndex >= TokenCount)
                {
                    fprintf(stderr, "Error: Reached end of tokens :')\n");
                    return;
                }

                if (strcmp(tokens[TokenIndex].value, ")") == 0)
                {
                    Token closeParenToken = {TOKEN_CLOSE_PAREN, ")"};

                    TokenNode *closeParen = create_token_node(closeParenToken, NULL);
                    TokenIndex++;

                    if (TokenIndex >= TokenCount)
                    {
                        fprintf(stderr, "Error: Reached end of tokens :')\n");
                        return;
                    }

                    if (strcmp(tokens[TokenIndex].value, "{") == 0)
                    {
                        Token openCurlyToken = {TOKEN_OPEN_CURLY_PAREN, "{"};

                        TokenNode *openCurly = create_token_node(openCurlyToken, NULL);
                        
                        MAIN->next = openParen;
                        openParen->next = closeParen;
                        closeParen->next = openCurly;
                        INT->child = (ExpressionNode *) MAIN;
                        
                        printf("Correct main Statment horaaaaay!!\n");
                        return;
                    }
                }
            }
        }
    }
}
