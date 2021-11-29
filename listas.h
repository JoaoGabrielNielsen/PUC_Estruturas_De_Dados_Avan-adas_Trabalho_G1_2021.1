typedef struct lista
{
    char info;
    struct lista *prox; 
} Lista;


Lista* lista_cria (void);

Lista* lista_insere (Lista* lista, char c);

Lista* lista_retira_primeiro (Lista* lista);

void lista_imprime (Lista* lista);

int lista_vazia (Lista* lista);

void lista_libera (Lista* lista); 
