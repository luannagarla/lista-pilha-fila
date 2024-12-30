// Lista Ligada

// Considere a lista ligada dinˆamica (inser ̧c ̃ao ordenada). Desejamos transfor-
// mar essa estrutura em uma estrutura duplamente ligada (isto  ́e, cada ele-
// mento apontar ́a para seu anterior e tamb ́em para seu sucessor). Em termos

// de modelagem, haver ́a apenas uma modifica ̧c ̃ao na estrutura ELEMENTO, que
// receber ́a um campo adicional chamado de ant:
// typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *ant, *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT inicio;
} LISTA;

// Duas fun ̧c ̃oes precisam ser alteradas para que todos os ponteiros da es-
// trutura fiquem consistentes: as fun ̧c ̃oes de inser ̧c ̃ao e exclus ̃ao. Para esta

// atividade, revise/atualize a fun ̧c ̃ao de inser ̧c ̃ao considerando os seguintes ca-
// sos:

// • Se o elemento a ser inserido for o primeiro da lista, o campo ant dele
// dever ́a ser NULL.

// 1

// • Caso contr ́ario, o campo ant dever ́a apontar para o elemento anterior.
// • O elemento seguinte ao novo dever ́a ter seu campo ant atualizado para
// apontar para o novo elemento.
// A assinatura da fun ̧c ̃ao  ́e:
// bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
// Observe que, no site da disciplina, j ́a est ́a dispon ́ıvel todo o c ́odigo da presente
// estrutura. No entanto, a fun ̧c ̃ao de inser ̧c ̃ao n ̃ao considera que a lista  ́e
// duplamente ligada, sendo necess ́ario alter ́a-la para atualizar o valor do campo
// ant do novo elemento que est ́a sendo inserido. Esta ser ́a uma inser ̧c ̃ao sem
// repeti ̧c ̃ao, ou seja, se um elemento com a mesma chave j ́a existir, a fun ̧c ̃ao
// dever ́a retornar false.
// Al ́em disso, ser ́a necess ́ario atualizar o campo ant do elemento que, na
// lista ordenada duplamente ligada, ser ́a o sucessor do novo elemento (caso
// este sucessor exista).
// Entregue c ́odigo completo revisado. A estrutura n ̃ao ser ́a circular e n ̃ao
// ter ́a n ́o-cabe ̧ca.