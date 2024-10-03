
// void addToken(TokenArray *tokenArray, Token *token) {

//     reallocTokenArray(tokenArray);
//     tokenArray->tokens[tokenArray->count] = token;
//     tokenArray->count++;
// }

// void reallocTokenArray(TokenArray *tokenArray) {
//     if (tokenArray->count >= tokenArray->capacity) {
//         tokenArray->capacity *= 2;

//         Token **temp = (Token **)realloc(tokenArray->tokens, tokenArray->capacity * sizeof(Token *));

//         if (temp == NULL) {
//             printf("Reallocation failed\n");
//             return;
//         }

//         tokenArray->tokens = temp;
//     }
// }

// TokenArray *createTokenArray() {
//     TokenArray *tokenArray = (TokenArray *)malloc(sizeof(TokenArray));
//     if (tokenArray == NULL)
//         return NULL;

//     tokenArray->capacity = 10;
//     tokenArray->count = 0;
//     tokenArray->tokens = (Token **)malloc(tokenArray->capacity * sizeof(Token *));
//     return tokenArray;
// }
