# PUC_Estruturas_De_Dados_Avan-adas_Trabalho_G1_2021.1
Primeiro trabalho da matéria de Estruturas de Dados Avançadas(INF1010), cursada no período de 2021.1 na PUC-Rio

#Grupo:
        João Gabriel Nielsen
        Bernardo Ruiz Fernandes

#Descrição:

O Banco Money gostaria de implementar um novo recurso em seu sistema de avaliação 
de crédito. Hoje, a rotina de análise de crédito é programada no sistema e a sua 
atualização só pode ser feita pelos desenvolvedores. Para diminuir o custo de 
manutenção, a diretoria do banco solicita que seja criado um campo no sistema onde 
poderão ser inseridas as expressões matemáticas que calculam cada etapa da análise de 
crédito. Assim, qualquer pessoa poderia atualizar as fórmulas de cálculo das etapas sem 
a necessidade de ter conhecimentos em programação. 
Como as fórmulas envolvem variáveis, a primeira etapa consiste em criar um programa 
que traduza as entradas de texto com operandos numéricos e calcule o resultado das 
expressões numéricas.

O Trabalho 1 consiste em implementar um interpretador que traduzirá uma string que 
representa uma equação em seu resultado numérico. Deverá ser feito em duas etapas:

        1ª etapa deverá utilizar o algoritmo Shunting Yard para traduzir a expressão do
        formato infix para o formato postfix.
        
        2ª etapa deverá receber a expressão postfix e criar uma árvore de expressão. A 
        árvore de expressão deverá ser impressa em representação aninhada.
        O programa deverá solicitar ao usuário a expressão que deseja resolver e ao final 
        apresentar o seu resultado. Serão aceitos apenas números inteiros – resultados 
        fracionários serão truncados (resultará no piso).

O trabalho poderá ser realizado individualmente ou em dupla
Serão avaliadas as seguintes expressões:
1) 3 + 2 x 3 = 9
2) 10 x 2 – 2 x 5 = 10
3) 7 + 3 ÷ 2 = 8 (o correto é 8,5 mas usaremos apenas inteiros)
4) 2 x 6 + 3 / 8 = 12 (o correto é 12,375 mas usaremos apenas inteiros)
5) 2 + (3 x (8 - 4)) = 14
6) 18 ÷ 2 x 5 + 6 – 4 = ?
7) 3 + (16 – 4 x 3) – 6 ÷ 2 = ?
8) (2 – 3 + 1) ÷ (2 - 2) = ?
9) ((18 + 3 x 2) ÷ 8 + 5 x 3) ÷ 6 = ?
10) 16 / 4 x (4) = ? (pegadinha da calculadora casio vídeo)

#Dicas:
1) Utilize o TDA de Pilhas;
2) Utilize o TDA de Árvores Binárias.
3) Explicação do algoritmo Shunting Yard (slides) (vídeo)
4) Explicação de árvores de expressão (slides) (vídeo)
#Forma de Avaliação:
  Será avaliado se:
        (1) O trabalho atendeu a todos os requisitos especificados anteriormente;
        (2) Os algoritmos foram implementados e aplicados de forma correta;
        (3) O código foi devidamente organizado;
        (4) Os resultados estão corretos;

O resultado pode ser calculado também pelo algoritmo Shunting Yard mas é 
obrigatório que o resultado final seja calculado pela árvore de expressão
