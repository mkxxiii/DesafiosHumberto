#include <stdio.h>

//Definições Sistema
#define SIZE 101
#define NULL_INT -999

//Struct
struct GeradorSenha{
    int fila[SIZE];
    int posCaixa;
    int posSenha;
    char sufixo;
};

//Funções
struct GeradorSenha startStrc(char sufix){
    struct GeradorSenha obj;
    obj.posCaixa = 0;
    obj.posSenha = 0;
    obj.sufixo = sufix;

    int i;
    for(i = 0; i < SIZE; i++)
        obj.fila[i] = NULL_INT;

    return obj;
}

void InserirNovaSenha(struct GeradorSenha *obj){
    obj->fila[obj->posSenha] = obj->posSenha;
    printSenha(obj->sufixo, obj->posSenha);
    obj->posSenha++;
}

int ChamarSenha(struct GeradorSenha *obj, int codCaixa){
    if(obj->fila[obj->posCaixa] == NULL_INT)
        return 0;

    printf("Senha %c%d, favor se dirigir ao caixa %d", obj->sufixo, obj->posSenha, codCaixa);
    obj->posCaixa++;
    return 1;
}

void printSenha(char sufixo, int codigo){
    printf("\nA sua senha e: %c%d \n", sufixo, codigo);
    printf("\nExiste %d pessoas na sua frente\n", codigo);
}

void Menu(){
    printf("MENU\n Selecione uma opcao\n");
    printf("1 - Coletar Senha Preferencial\n");
    printf("2 - Coletar Senha Comum\n");
    printf("3 - Chamar Caixa Preferencial\n");
    printf("4 - Chamar Caixa Comum\n");
    printf("5 - Sair\n");
}

int ColetarInt(){
    int buff;
    scanf("%d", &buff);
    return buff;
}

int main(){
        struct GeradorSenha filaNormal = startStrc('N');
        struct GeradorSenha filaPriori = startStrc('P');

        int escape = 0;
        while(escape == 0){
            Menu();
            int opt = ColetarInt();
            system("cls");
            switch(opt){
                case 1:
                    InserirNovaSenha(&filaPriori);
                    break;
                case 2:
                    InserirNovaSenha(&filaNormal);
                    break;
                case 3:
                    if(ChamarSenha(&filaPriori) == 0){
                        if(ChamarSenha(&filaNormal) == 0)
                            printf("Não ha clientes disponiveis no momento!");
                    }
                case 4:
                    if(ChamarSenha(&filaNormal) == 0){
                        if(ChamarSenha(&filaPriori) == 0)
                            printf("Não ha clientes disponiveis no momento!");
                    }
            }
        }
        return 0;
}
