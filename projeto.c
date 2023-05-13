#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incluiUsuario(int *id, char nomeCompleto[][50], char email[][50], char sexo[][50], char endereco[][50], double *altura, int *vacina)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        id[i] = rand() % 1000;

        printf("Digite o nome completo do usuario:");
        fgets(nomeCompleto[i], 50, stdin);
        strtok(nomeCompleto[i], "\n");

        printf("Digite o email do usuario:");
        while (fgets(email, 50, stdin) != NULL)
        {
            if (strchr(email, '@') != NULL)
            {
                printf("O email digitado contem um '@'\n");
                break;
            }
        }

        // printf("Digite o sexo do usuario:\n");
        // fgets(sexo[i], 50, stdin);
        // strtok(sexo[i], "\n");
        // int nome_certo = 0;
        // for (int j = 0; j < strlen(sexo[i]); j++)
        // {
        //     if (sexo[i][j] == 'Feminino' || sexo[i][j] == 'Masculino' || sexo[i][j] == 'Indiferente')
        //     {
        //         nome_certo = 1;
        //         break;
        //     }
        //     else if (nome_certo == 0)
        //     {
        //         printf("Só são aceitas as palavras: Feminino, Masculino ou Indiferente.\n");
        //         continue; // volta para o inicio do loop
        //     }
        // }

        // printf("Digite o endereco do usuario:");
        // fgets(endereco[i], 50, stdin);
        // strtok(endereco[i], "\n");

        // printf("Digite a altura do usuario:\n");
        // scanf("%lf", &altura[i]);
        // getchar();

        // printf("O usuario esta vacinado:\n");
        // scanf("%d", &vacina[i]);
        // getchar();
    }
}

int main()
{
    int id[5], i;
    char nomeCompleto[5][50];
    char email[5][50];
    char sexo[5][50];
    char endereco[5][50];
    double altura[5];
    int vacina[5];

    incluiUsuario(id, nomeCompleto, email, sexo, endereco, altura, vacina);
    // for(i=0;i<5;i++){
    //     printf("%d - %s- %s- %s- %s- %.2lf- %d\n", id[i], nomeCompleto[i], email[i], sexo[i], endereco[i], altura[i], vacina[i]);
    // }

    return 0;
}