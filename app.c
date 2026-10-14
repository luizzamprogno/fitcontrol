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
        
        // Leitura da opção do menu inicial (protegida)
        // validações de entrada de usuário
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
                // validações de entrada de usuário
                if (scanf("%d", &tipo_de_treino) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    tipo_de_treino = -1;
                }

                printf("Duração (min.): ");
                // validações de entrada de usuário
                if (scanf("%d", &duracao) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    duracao = -1;
                }

                // só para definir o fator de calorias
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
                    printf("Tipo de treino inválido. Escolha um número de 1 a 4.\n");
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
            {

                double media_calorias = 0;
                double media_minutos = 0;
                int horas = total_de_minutos / 60; // horas completas de treino
                int minutos = total_de_minutos % 60; // minutos restantes após as horas

                if (quantidade_de_treino > 0) {
                    media_calorias = total_de_calorias / quantidade_de_treino;
                    media_minutos = (double) total_de_minutos / quantidade_de_treino;
                    
                } else {
                    printf("Nenhum treino registrado ainda. Use a opção 1 para registrar.\n");
                    break;
                }

                printf("+==========================================+\n");
                printf("         SEU RELATÓRIO DE TREINOS\n");
                printf("+==========================================+\n\n");

                printf("Treinos registrados: %d\n", quantidade_de_treino);
                printf("Tempo total de treino: %dh %02dmin\n", horas, minutos);
                printf("Calorias totais: %.1f kcal\n\n", total_de_calorias);

                printf("Média por treino: %.1f min | %.1f kcal\n\n", media_minutos, media_calorias);

                
                if (total_de_calorias <= 300) {
                    printf("Nível: INICIANTE. Não desanime, continue firme!\n");

                } else if (total_de_calorias <= 1000) {
                    printf("Nível: INTERMEDIÁRIO. Você está indo bem!\n");

                } else {
                    printf("Nível: AVANÇADO. Parabéns pela dedicação!\n");
                }
                printf("+==========================================+\n");
                

                break;
            }

            case 4:
                printf("Saindo do aplicativo. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Digite um número de 1 a 4.\n");
                break;
        }
        printf("\n");
    // laço do while continua enquanto opcao é diferente de 4, reaparecendo o menu
    } while (opcao != 4);
    return 0;
}