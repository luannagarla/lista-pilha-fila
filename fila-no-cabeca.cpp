// Fila com N ́o-Cabe ̧ca

// Considere a fila (implementa ̧c ̃ao dinˆamica) apresentada na aula. A imple-
// menta ̧c ̃ao utilizada anteriormente n ̃ao inclu ́ıa um n ́o-cabe ̧ca. Conforme dis-
// cutido, uma vantagem de utilizar um n ́o-cabe ̧ca  ́e garantir que todos os ele-
// mentos v ́alidos sempre ter ̃ao um anterior, e a estrutura nunca ficar ́a vazia

// (poder ́a n ̃ao conter nenhum elemento ”v ́alido”, mas n ̃ao ser ́a considerada
// vazia).
// Para esta atividade, adapte as fun ̧c ̃oes inserirNaFila e excluirDaFila

// para considerar a existˆencia de um n ́o-cabe ̧ca. Esta estrutura n ̃ao ser ́a circu-
// lar nem duplamente ligada. Apenas ser ́a adicionado um n ́o-cabe ̧ca (durante

// a inicializa ̧c ̃ao), e as fun ̧c ̃oes de inser ̧c ̃ao e exclus ̃ao dever ̃ao considerar a
// existˆencia desse elemento, que nunca dever ́a ser exclu ́ıdo.
// O esqueleto das fun ̧c ̃oes  ́e:

bool inserirNaFila(FILA *f, REGISTRO reg)
{
    /* COMPLETAR - REVISAR o c ́odigo desta fun ̧c~ao */
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA *f, REGISTRO *reg)
{
    /* COMPLETAR - REVISAR o c ́odigo desta fun ̧c~ao */
    if (f->inicio == NULL)
    {
        return false;
    }
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    return true;
}

// Estas fun ̧c ̃oes respeitam a assinatura e a funcionalidade da inser ̧c ̃ao e
// exclus ̃ao em filas: os elementos s ̃ao inseridos no final da fila e exclu ́ıdos do
// in ́ıcio.