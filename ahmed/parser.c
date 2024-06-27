#include "compiler.h"
/*
change child paramter to root for link parser tree
*/
ExpressionNode *create_expression_node(Token token, ExpressionNode *root)
{
	ExpressionNode *node = (ExpressionNode *)malloc(sizeof(ExpressionNode));
	if (node == NULL)
	{
		perror("Failed to allocate memory for ExpressionNode");
		exit(EXIT_FAILURE);
	}
	root->child = node;
	node->token = token;
	node->next = NULL;
	return (node);
}

// change next paramter to prev for link  tokens
TokenNode *create_token_node(Token token, TokenNode *prev)
{
	TokenNode *node = (TokenNode *)malloc(sizeof(TokenNode));
	if (node == NULL)
	{
		perror("Failed to allocate memory for TokenNode");
		exit(EXIT_FAILURE);
	}

	node->token = token;
	prev->next = node;

	return (node);
}

/**
 * parser -
 */
void parser()
{
}
void parse_return()
{
	int start_token = TokenIndex;
	if (TokenIndex >= TokenCount)
	{
		fprintf(stderr, "Error: Reached end of tokens :')\n");
		return;
	}

	if (strcmp(tokens[TokenIndex].value, "return") == 0)
	{
		TokenIndex++;

		if (TokenIndex >= TokenCount)
		{
			fprintf(stderr, "Error: Unexpected end of tokens :')\n");
			return;
		}

		if (strcmp(tokens[TokenIndex].value, "(") == 0)
		{
			TokenIndex++;

			if (TokenIndex >= TokenCount)
			{
				fprintf(stderr, "Error: Unexpected end of tokens :')\n");
				return;
			}

			if (tokens[TokenIndex].type == TOKEN_LITERAL_INT)
			{
				TokenIndex++;

				if (TokenIndex >= TokenCount)
				{
					fprintf(stderr, "Error: Unexpected end of tokens :')\n");
					return;
				}

				if (strcmp(tokens[TokenIndex].value, ")") == 0)
				{
					TokenIndex++;

					if (TokenIndex >= TokenCount)
					{
						fprintf(stderr, "Error: Unexpected end of tokens :')\n");
						return;
					}

					if (strcmp(tokens[TokenIndex].value, ";") == 0)
					{
						// printf(";\n");
						TokenIndex++;
						ExpressionNode *child;
						TokenNode *cur;
						TokenNode *prev;

						Token token_exit = {EXIT, NULL};
						child = create_expression_node(token_exit, root);
						prev = create_token_node(token_exit, child->next);
						for (int i = start_token; i < TokenIndex; i++)
						{
							cur = create_token_node(tokens[start_token], prev);
							prev = cur;
						}
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
		TokenIndex++;

		if (TokenIndex >= TokenCount)
		{
			fprintf(stderr, "Error: Reached end of tokens :')\n");
			return;
		}

		if (strcmp(tokens[TokenIndex].value, "main") == 0)
		{
			TokenIndex++;

			if (TokenIndex >= TokenCount)
			{
				fprintf(stderr, "Error: Reached end of tokens :')\n");
				return;
			}

			if (strcmp(tokens[TokenIndex].value, "(") == 0)
			{
				TokenIndex++;

				if (TokenIndex >= TokenCount)
				{
					fprintf(stderr, "Error: Reached end of tokens :')\n");
					return;
				}

				if (strcmp(tokens[TokenIndex].value, ")") == 0)
				{
					printf("Correct main Statment horaaaaay!!\n");
					return;
				}
			}
		}
	}
}