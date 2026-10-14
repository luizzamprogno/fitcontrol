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
    int quantidade_de_treino = 0;
    int total_de_minutos = 0;
    double total_de_calorias = 0;

    do { // Loop principal do menu
        
        printf("\n*** Escolha uma opção: ***\n\n");
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
            case 1:{

                int tipo_de_treino = 0;
                int duracao = 0;
                double fator = 0; // kcal por minuto; 0 = tipo inválido
                double calorias_treino = 0;

                printf("Qual é o tipo de treino? \n\n");
                printf("1. Caminhada\n");
                printf("2. Corrida\n");
                printf("3. Musculação\n");
                printf("4. Bicicleta\n\n");

                printf("Tipo de treino: ");
                if (scanf("%d", &tipo_de_treino) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    tipo_de_treino = -1;
                }

                printf("Duração (min.): ");
                if (scanf("%d", &duracao) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    duracao = -1;
                }

                // só definir o fator
                // estimativas para uma pessoa de 70kg

                if (tipo_de_treino == 1){
                    fator = 4; // caminhada
                } else if (tipo_de_treino == 2){
                    fator = 11; // corrida
                } else if (tipo_de_treino == 3){
                    fator = 6; // musculação
                } else if (tipo_de_treino == 4){
                    fator = 8; // bicicleta
                }

                // validar o fator antes de calcular
                if (fator == 0){
                    printf("Tipo de treino inválido.\n");
                } else if ( duracao <= 0) {
                    printf("Duração inválida, Digite um número maior que zero.\n");
                } else {
                    calorias_treino = duracao * fator;

                    quantidade_de_treino += 1;
                    total_de_minutos += duracao;
                    total_de_calorias += calorias_treino;

                    printf("Treino registrado! Calorias queimadas : %.1f kcal\n", calorias_treino);
                }
                

                break;
            }


            case 2:

                printf("Calorias totais queimadas: %.1f", total_de_calorias);

                break;
            case 3:

                printf("*** Seu relatório de treino: ***\n\n");
                printf("Média de calorias gastas por treino: %.1f", total_de_calorias/quantidade_de_treino);
                
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