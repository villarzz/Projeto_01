#include <stdio.h>

void incluiUsuario(int *id, char *nomeCompleto,char *email, char *sexo, char *endereco, double *altura, int *vacina){
    int i;
    for (i = 0; i <= 5; i++){
        printf("Digite o codigo do usuario:\n");
        scanf("%d", &id[i]);

        printf("Digite o nome completo do usuario:\n");
        scanf("%s", &nomeCompleto[i]);

        printf("Digite o email do usuario:\n");
        scanf("%s", &email[i]);

        printf("Digite o sexo do usuario:\n");
        scanf("%s", &sexo[i]);

        printf("Digite o endereco do usuario:\n");
        scanf("%s", &endereco[i]);

        printf("Digite a altura do usuario:\n");
        scanf("%lf", &altura[i]);

        printf("O usuario esta vacinado:\n");
        scanf("%d", vacina[i]);
    }
    
}

int main(){
    int id[5];
    char nomeCompleto[5][40];
    char email[5][50];
    char sexo[5][11];
    char endereco[5][50];
    double altura [5];
    int vacina[5][1];
}