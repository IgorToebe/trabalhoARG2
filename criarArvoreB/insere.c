#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAVE 5
#define erro "erro"
#define encontrado 1
#define naoEncontrado 0
#define ComPromocao 2
#define semPromocao 3
#define delimitador "|"
#define qtdDeCampos 4

int insere(int rrn_Pagina_Atual,char chave,int *pagina_filha_da_direita,int *chave_promovida, PAG pagina){
    
    PAG pagina;
    int result = 0;
    int pos = 0;

    if(rrn_Pagina_Atual == NULL){
        *chave_promovida = chave;
        *pagina_filha_da_direita = NULL;
        return ComPromocao; 
    }
    else{
        le_pagina(rrn_Pagina_Atual,pagina);
        result = busca_na_pagina(chave, pagina,&pos);
    }

    if(result == encontrado){
        printf("\nChave duplicada");
        return erro;
    }

    int pagina_filha_da_direita2,chave_promovida2;
    int retorno = insere(pagina.filhos[pos],chave,&pagina_filha_da_direita2,&chave_promovida2);

    if(retorno == ComPromocao || retorno == erro){

        return retorno;
    }
    else{
        
        if(pagina.quantidadeDeChaves <= qtdDeCampos-1){
            insere_na_pagina(chave_promovida2,pagina_filha_da_direita2,&pagina);
            escreve_pagina(rrn_Pagina_Atual,pagina);
            return semPromocao;
        }
        else{
            divide(chave_promovida2,pagina_filha_da_direita2,&pagina,chave_promovida,pagina_filha_da_direita,&novapag);
            escreve_pagina(rrn_Pagina_Atual,pagina);
            escreve_pagina(pagina_filha_da_direita,novapag);
            return ComPromocao;
        }
    }
}




