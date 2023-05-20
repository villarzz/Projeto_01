#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_USERS 1000

//vetores originais
int numeroUsuarios = 0;
int vetorId[MAXIMO_USERS];
char vetorNomeCompleto[MAXIMO_USERS][50];
char vetorEmails[MAXIMO_USERS][50];
char vetorSexo[MAXIMO_USERS][10];
char vetorEndereco[MAXIMO_USERS][100];
double vetorAltura[MAXIMO_USERS];
int vetorVacina[MAXIMO_USERS];

//vetores backup
int vetorBackupId[MAXIMO_USERS];
char vetorBackupNomeCompleto[MAXIMO_USERS][50];
char vetorBackupEmails[MAXIMO_USERS][50];
char vetorBackupSexo[MAXIMO_USERS][10];
char vetorBackupEndereco[MAXIMO_USERS][100];
double vetorBackupAltura[MAXIMO_USERS];
int vetorBackupVacina[MAXIMO_USERS];

void abreMenu()
{
    printf("Digite 1 para adicionar usuario\n");
    printf("Digite 4 para buscar usuario por email\n");
    printf("Digite 5 para imprimir todos os usuarios\n");
    printf("Digite 6 para fazer o backup de  todos os usuarios\n");
    printf("Caso deseje fechar o programa tecle 0\n");
    printf("Digite a opção escolhida: ");
}

void incluiUsuario()
{
    int id, vacina;
    char nome[100], email[100], sexo[100], endereco[100];
    double altura;

    id = rand() % 1000;

    printf("Digite o nome completo do usuario:");
    fgets(nome, 50, stdin);
    strtok(nome, "\n");

    printf("Digite o email do usuario:");
    while (fgets(email, 50, stdin) != NULL)
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

        int posicao_quebra_linha = strcspn(sexo, "\n");
        sexo[posicao_quebra_linha] = '\0';

        if (strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0)
        {
            valido = 1;
        }
        else
        {
            printf("Sexo invalido, Digite 'Feminino','Masculino' ou 'Indiferente'.\n");
        }
    }

    printf("Digite o endereco do usuario:");
    fgets(endereco, 50, stdin);
    strtok(endereco, "\n");

    int altura_valida = 0;
    while (altura_valida == 0)
    {
        printf("Digite a altura do usuario:\n");
        scanf("%lf", &altura);

        if (altura >= 1.0 && altura <= 2.0)
        {
            altura_valida = 1;
        }
        else
        {
            printf("Altura invalida. Digite um valor entre 1.0 e 2.0.\n");
        }
    }

    printf("O usuario esta vacinado (digite 1 para sim e 0 para nao):\n");
    scanf("%d", &vacina);
    getchar();

    vetorId[numeroUsuarios] = id;
    strcpy(vetorNomeCompleto[numeroUsuarios], nome);
    strcpy(vetorEmails[numeroUsuarios], email);
    strcpy(vetorSexo[numeroUsuarios], sexo);
    strcpy(vetorEndereco[numeroUsuarios], endereco);
    vetorAltura[numeroUsuarios] = altura;
    vetorVacina[numeroUsuarios] = vacina;
    numeroUsuarios++;
}

void buscaPorEmail(){
    char email[100];
    printf("Digite o email que você quer buscar: ");
    scanf(" %c",email);

    for (int i = 0; i < numeroU; i++)
    {
        if(strcmp(vetorEmails[i],email)==0){
            printf("id: %d\n",vetorId[i]);
            printf("nome: %s\n",vetorNomeCompleto[i]);
            printf("sexo: %s\n",vetorSexo[i]);
            printf("endereco: %s\n",vetorEndereco[i]);
            printf("altura: %.2lf\n",vetorAltura[i]);
            printf("status de vacinação: %d\n",vetorVacina[i]);
        }
    }
}

void imprimirUsuario(){
    for (int i = 0; i < numeroUsu; i++)
    {
        printf("id: %d\n", vetorId[i]);
        printf("email: %s\n", vetorEmail[i]);
        printf("nome: %s\n", vetorNomeCompleto[i]);
        printf("sexo: %s\n", vetorSexo[i]);
        printf("endereco: %s\n", vetorEndereco[i]);
        printf("altura: %.2lf\n", vetorAltura[i]);
        printf("vacinação: %d\n", vetorVacina[i]);
    }
}

void backUpUsuarios(){
    for (int i = 0; i < numu; i++)
    {
        vetorBackupId[i] = vetorId[i];
        strcpy(vetorBackupNomeCompleto[i],vetorNomeCompleto[i]);
        strcpy(vetorBackupEmails[i],vetorEmails[i]);
        strcpy(vetorBackupSexo[i],vetorSexo[i]);
        strcpy(vetorBackupEndereco[i],vetorEndereco[i]);
        vetorBackupAltura[i] = vetorAltura[i];
        vetorBackupVacina[i] = vetorVacina[i];
    }
    
}

int main()
{
    char opcao = ' ';

    while (opcao != '0')
    {
        abreMenu();
        scanf("%c", &opcao);
        getchar();

        switch (opcao)
        {
        case '1':
            incluiUsuario();
            break;
        case '4':
            buscaPorEmail();
            break;
        case '5':
            imprimirUsuario();
            break;
        case '6':
            backUpUsuarios();
            break;
        case '0':
            printf('programa fechado')
        default:
            printf("Opção invalida");
            break;
        }
    }
}