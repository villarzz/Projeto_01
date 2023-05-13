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
        while (fgets(email[i], 50, stdin) != NULL)
        {
            if (strchr(email, '@') != NULL)
            {
                break;
            }
            else
            {
                printf("O email digitado nao contem um '@'. Digite novamente:\n");
            }
        }

        int valido = 0;
        while (valido == 0)
        {
            printf("Digite o sexo do usuario:");
            fgets(sexo, 50, stdin);

            int posicao_quebra_linha = strcspn(sexo[i], "\n");
            sexo[i][posicao_quebra_linha] = '\0';

            if (strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0)
            {
                valido = 1;
            }
            else
            {
                printf("Sexo invalido, Digite 'Feminino','Masculino' ou 'Indiferente'.\n");
            }
        }

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
    for (i = 0; i < 5; i++)
    {
        printf("%d - %s- %s- %s- %s- %.2lf- %d\n", id[i], nomeCompleto[i], email[i], sexo[i], endereco[i], altura[i], vacina[i]);
    }

    return 0;
}