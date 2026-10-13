#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8"); // Define a localidade para português do Brasil

    printf("+==========================================+\n");
    printf("|                                          |\n");
    printf("|           >>>  FitControl  <<<           |\n");
    printf("|                                          |\n");
    printf("|  Seu app para controle de treinos        |\n");
    printf("|  e calorias                              |\n");
    printf("|                                          |\n");
    printf("+==========================================+\n\n");

    printf("Olá! Que bom ter você aqui.\n");
    printf("Saúde e bem-estar em primeiro lugar!\n\n");
    printf("Registre seus treinos e acompanhe sua\n");
    printf("queima calórica estimada.\n\n");


    int opcao = 0;

    do { // Loop principal do menu
        
        printf("*** Escolha uma opção: ***\n");
        printf("\n");
        printf("1. Registrar treino\n");
        printf("2. Consultar calorias queimadas\n");
        printf("3. Ver relatório de treinos\n");
        printf("4. Sair\n");
        printf("\n");
        printf("Opção: ");
        if (scanf("%d", &opcao) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer do teclado
            opcao = -1; // Volta para o início do loop
        }

        switch (opcao) {
            case 1:
                printf("Função de registro de treino ainda não implementada.\n");
                break;
            case 2:
                printf("Função de consulta de calorias queimadas ainda não implementada.\n");
                break;
            case 3:
                printf("Função de ver relatório de treinos ainda não implementada.\n");
                break;
            case 4:
                printf("Saindo do aplicativo. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
        printf("\n");
    } while (opcao != 4);
    return 0;
}