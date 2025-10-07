#include <stdio.h>   // Biblioteca padrão para entrada e saída (printf, scanf)
#include <stdlib.h>  // Biblioteca usada para funções utilitárias como rand() e srand()
#include <time.h>    // Biblioteca usada para obter o tempo atual (semente para números aleatórios)

// ============================================================================
// Objetivo: Criar o jogo Jokenpo (Pedra, Papel e Tesoura)
// Autor: Thiago Zimermann Ferrari
// Data: Outubro de 2025
// Descrição: O programa apresenta um menu interativo e permite jogar contra o computador,
// que escolhe sua opção de forma aleatória.
// ============================================================================

// Estrutura (struct) que armazena as variáveis principais do jogo
typedef struct {
    int menu_iniciar;          // Armazena a opção escolhida no menu principal
    int iniciar;               // Indica se o jogo deve ser iniciado (1 = sim, 0 = não)
    int aleatorio_computador;  // Guarda a jogada aleatória do computador (1 a 3)
    int numero_jogador;        // Guarda a jogada escolhida pelo jogador (1 a 3)
} Jokenpo;

// ============================================================================
// Função: menu_interativo
// Objetivo: Exibe o menu principal e armazena a escolha do usuário.
// Parâmetro: ponteiro para struct Jokenpo, que guarda a escolha.
// ============================================================================
void menu_interativo(Jokenpo *resultado) {

    resultado->iniciar = 0;

    printf("Bem-vindo ao Jokenpo!\n");
    printf("Digite o número da ação desejada:\n");
    printf("1 - Iniciar jogo\n");
    printf("2 - Ver regras\n");
    printf("3 - Sair\n");
    scanf("%d", &resultado->menu_iniciar);

    // Processa a escolha do menu
    switch (resultado->menu_iniciar) {
        case 1:
            resultado->iniciar = 1; // Marca que o jogo será iniciado
            break;

        case 2:
            // Exibe as regras do jogo
            printf("===== REGRAS DO JOGO =====\n");
            printf("1. Cada opção corresponde a um número:\n");
            printf("   1 = Pedra\n");
            printf("   2 = Papel\n");
            printf("   3 = Tesoura\n\n");
            printf("2. Comparação das escolhas:\n");
            printf("   Pedra (1) vence Tesoura (3)\n");
            printf("   Papel (2) vence Pedra (1)\n");
            printf("   Tesoura (3) vence Papel (2)\n\n");
            printf("3. Resultado:\n");
            printf("   - Números iguais -> Empate\n");
            printf("   - Jogador vence se seguir as regras acima\n");
            printf("   - Caso contrário, o computador vence\n");
            break;

        case 3:
            printf("Saindo do jogo...\n");
            break;

        default:
            printf("Digite um número válido (1, 2 ou 3).\n");
    }
}

// ============================================================================
// Função: jogo_interativo
// Objetivo: Executa o jogo, sorteia a jogada do computador e compara com a do jogador.
// Parâmetro: ponteiro para struct Jokenpo (contém as jogadas e controle do jogo).
// ============================================================================
void jogo_interativo(Jokenpo *resultado) {

    // Verifica se o jogador escolheu iniciar o jogo
    if (resultado->iniciar == 1) {

        // Gera número aleatório com base no tempo atual (evita repetições)
        srand(time(0));
        resultado->aleatorio_computador = rand() % 3 + 1; // Valores possíveis: 1, 2 ou 3

        // Exibe o menu de jogadas
        printf("\nEscolha uma opção para jogar:\n");
        printf("1 - Pedra\n");
        printf("2 - Papel\n");
        printf("3 - Tesoura\n");
        printf("4 - Sair\n");
        scanf("%d", &resultado->numero_jogador);

        // Mostra a escolha do jogador
        switch (resultado->numero_jogador) {
            case 1:
                printf("Jogador: Pedra\n");
                break;
            case 2:
                printf("Jogador: Papel\n");
                break;
            case 3:
                printf("Jogador: Tesoura\n");
                break;
            case 4:
                printf("Saindo...\n");
                return; // Encerra o jogo imediatamente
            default:
                printf("Digite um número válido (1, 2, 3 ou 4)\n");
                return;
        }

        // Mostra a escolha do computador
        switch (resultado->aleatorio_computador) {
            case 1:
                printf("Computador: Pedra\n");
                break;
            case 2:
                printf("Computador: Papel\n");
                break;
            case 3:
                printf("Computador: Tesoura\n");
                break;
        }

        // Compara as escolhas e exibe o resultado
        if (resultado->numero_jogador == resultado->aleatorio_computador) {
            printf("Empate!\n");
        } 
        else if (
            (resultado->numero_jogador == 1 && resultado->aleatorio_computador == 2) || 
            (resultado->numero_jogador == 2 && resultado->aleatorio_computador == 3) ||
            (resultado->numero_jogador == 3 && resultado->aleatorio_computador == 1)
        ) {
            printf("Você Perdeu!\n");
        } 
        else {
            printf("Você Ganhou!\n");
        }
    }
}

// ============================================================================
// Função principal: main
// Responsável por iniciar o programa, chamar o menu e o jogo.
// ============================================================================
int main() {

    Jokenpo resultado; // Declara a struct que armazenará as variáveis do jogo

    menu_interativo(&resultado); // Exibe o menu principal
    jogo_interativo(&resultado); // Executa o jogo se o jogador escolheu iniciar

    return 0; // Encerra o programa com sucesso
}
