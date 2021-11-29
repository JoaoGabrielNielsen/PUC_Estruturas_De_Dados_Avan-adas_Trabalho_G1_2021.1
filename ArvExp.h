struct avrExp {
    int tipo;
    int valor;
    char oper;
    struct avrExp* esq;
    struct avrExp* dir;
    struct avrExp* pai;
};
typedef struct avrExp AvrExp;

int calc_tipo(char o);
AvrExp *cria_no(char c);
AvrExp faz_arvExp(char *postfix);
int avr_valorEA (arvExp* arv);