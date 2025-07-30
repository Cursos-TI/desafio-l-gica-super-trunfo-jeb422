#include <stdio.h>

// Funções de pontuação simples (1 a 5)
int pontos_populacao(unsigned long p) {
	if (p < 100000) return 1;
	else if (p < 300000) return 2;
	else if (p < 700000) return 3;
	else if (p < 1500000) return 4;
	else return 5;
}

int pontos_area(float a) {
	if (a < 100) return 1;
	else if (a < 300) return 2;
	else if (a < 1000) return 3;
	else if (a < 3000) return 4;
	else return 5;
}

int pontos_PIB(double pib) {
	if (pib < 500) return 1;
	else if (pib < 1000) return 2;
	else if (pib < 2000) return 3;
	else if (pib < 5000) return 4;
	else return 5;
}

int pontos_turisticos(unsigned int pt) {
	if (pt == 0) return 1;
	else if (pt <= 40) return 2;
	else if (pt <= 100) return 3;
	else if (pt <= 200) return 4;
	else return 5;
}

int pontos_densidade(double d) {
	if (d < 100) return 5;
	else if (d < 300) return 4;
	else if (d < 1000) return 3;
	else if (d < 3000) return 2;
	else return 1;
}

int pontos_PIB_per_capita(double ppc) {
	if (ppc < 10000) return 1;
	else if (ppc < 20000) return 2;
	else if (ppc < 40000) return 3;
	else if (ppc < 70000) return 4;
	else return 5;
}

void mostrar_atributos(const char* nome, int atk, int def, int eva) {
	printf("\n--- Atributos de Combate da Carta: %s ---\n", nome);
	printf("ATK: %d\n", atk);
	printf("DEF: %d\n", def);
	printf("EVA: %d\n", eva);
	
}

int main() {
	
	char estado, estado2; // apenas uma letra
	char codigo[10], codigo2[10];
	char nome_da_cidade[20], nome_da_cidade2[20];
	unsigned long populacao, populacao2;
	float area, area2;
	double PIB, PIB2;
	unsigned int numeros_de_pontos_turisticos, numeros_de_pontos_turisticos2;
	double densidade_populacional1, densidade_populacional2;
	double PIB_per_capita1, PIB_per_capita2;
	float super_poder1, super_poder2;
	int escolha;

	printf("Olá, \nVamos coletar informaçoes para a criação de duas cartas. \nPodemos começar com a primeira Carta. \n\n");

	printf("Informe uma letra para reprensentar seu estado: \n");
	scanf(" %c", &estado);

	printf("Defina um código (ex: A01): \n");
	scanf("%3s", codigo);

	printf("Informe o Nome da Cidade: \n");
	scanf(" %[^\n]", nome_da_cidade);

	printf("Informe o número de habitantes da cidade: \n");
	scanf("%lu", &populacao);

	printf("Informe a área desta cidade (em Km²): \n");
	scanf("%f", &area);

	printf("Informe o PIB desta cidade (em milhões): \n");
	scanf("%lf", &PIB);

	printf("Informe a quantidade de pontos Turísticos: \n");
	scanf("%u", &numeros_de_pontos_turisticos);

	densidade_populacional1 = populacao / area;
	PIB_per_capita1 = (PIB * 1000000) / populacao;

	// Super Poder 1
	super_poder1 = (float)(populacao + area + PIB + PIB_per_capita1 + numeros_de_pontos_turisticos + (1.0 / densidade_populacional1));

	// Segunda carta
	printf("\nAgora as informações para a segunda Carta. \n\n");

	printf("Informe uma letra para reprensentar seu estado: \n");
	scanf(" %c", &estado2);

	printf("Defina um código (ex: B03): \n");
	scanf("%3s", codigo2);

	printf("Informe o Nome da Cidade: \n");
	scanf(" %[^\n]", nome_da_cidade2);

	printf("Informe o número de habitantes da cidade: \n");
	scanf("%lu", &populacao2);

	printf("Informe a área desta cidade (em Km²): \n");
	scanf("%f", &area2);

	printf("Informe o PIB desta cidade (em milhões): \n");
	scanf("%lf", &PIB2);

	printf("Informe a quantidade de pontos Turísticos: \n");
	scanf("%u", &numeros_de_pontos_turisticos2);

	densidade_populacional2 = populacao2 / area2;
	PIB_per_capita2 = (PIB2 * 1000000) / populacao2;
	

	// Super Poder 2
	super_poder2 = (float)(populacao2 + area2 + PIB2 + PIB_per_capita2 + numeros_de_pontos_turisticos2 + (1.0 / densidade_populacional2));

	 // Cálculo dos atributos
	int atk1 = pontos_populacao(populacao) + pontos_PIB_per_capita(PIB_per_capita1);
	int def1 = pontos_area(area) + pontos_densidade(densidade_populacional1);
	int eva1 = pontos_turisticos(numeros_de_pontos_turisticos) + pontos_PIB(PIB);

	int atk2 = pontos_populacao(populacao2) + pontos_PIB_per_capita(PIB_per_capita2);
	int def2 = pontos_area(area2) + pontos_densidade(densidade_populacional2);
	int eva2 = pontos_turisticos(numeros_de_pontos_turisticos2) + pontos_PIB(PIB2) ;

	// Exibição
	printf("\n\n--- CARTA 01 ---\n");
	printf("Estado: %c\n", estado);
	printf("Código: %s\n", codigo);
	printf("Nome da Cidade: %s\n", nome_da_cidade);
	printf("População: %lu\n", populacao);
	printf("Área: %.2f Km²\n", area);
	printf("PIB: %.2lf de reais\n", PIB);
	printf("Número de Pontos Turísticos: %u\n", numeros_de_pontos_turisticos);
	printf("Densidade populacional: %.2lf hab/km²\n", densidade_populacional1);
	printf("PIB per capita: %.2lf R$/hab\n", PIB_per_capita1);
	printf("Super Poder: %.2f\n", super_poder1);
	mostrar_atributos(nome_da_cidade, atk1, def1, eva1);

	printf("\n\n--- CARTA 02 ---\n");
	printf("Estado: %c\n", estado2);
	printf("Código: %s\n", codigo2);
	printf("Nome da Cidade: %s\n", nome_da_cidade2);
	printf("População: %lu\n", populacao2);
	printf("Área: %.2f Km²\n", area2);
	printf("PIB: %.2lf de reais\n", PIB2);
	printf("Número de Pontos Turísticos: %u\n", numeros_de_pontos_turisticos2);
	printf("Densidade populacional: %.2lf hab/km²\n", densidade_populacional2);
	printf("PIB per capita: %.2lf R$/hab\n", PIB_per_capita2);
	printf("Super Poder: %.2f\n", super_poder2);
	mostrar_atributos(nome_da_cidade2, atk2, def2, eva2);

	mostrar_atributos(nome_da_cidade2, atk2, def2, eva2);

// Verifica se todos os atributos são iguais entre as cartas
	if (atk1 == atk2 && def1 == def2 && eva1 == eva2) {
    	printf("\n--- As duas cartas têm atributos idênticos ---\n");
    	printf("Resultado: EMPATE!\n");
    return 0;  // Encerra o programa imediatamente
}

	// Jogadores escolhem os atributos para batalha
	int vida1 = 3, vida2 = 3;
	int super_ativo1 = 1, super_ativo2 = 1;
	int rodada = 1;

	while (vida1 > 0 && vida2 > 0) {
		int escolha1, escolha2;
		int usar_super1 = 0, usar_super2 = 0;

		printf("\n--- RODADA %d ---\n", rodada);

		// Jogador 1
		printf("\n%s - Vida: %d | Super Poder disponível: %s\n", nome_da_cidade, vida1, super_ativo1 ? "SIM" : "NÃO");
		printf("Carta01 - Escolha seu atributo:\n");
        printf("1 = ATK\n");
        printf("2 = DEF\n");
        printf("3 = EVA\n");
        printf("4 = SUPER\n");
		scanf("%d", &escolha1);
		if (escolha1 == 4 && super_ativo1) {
			usar_super1 = 1;
			super_ativo1 = 0;
		} else if (escolha1 == 4 && !super_ativo1) {
			printf("Super já foi usado! Escolha outro atributo: ");
			scanf("%d", &escolha1);
		}

		// Jogador 2
		printf("\n%s - Vida: %d | Super Poder disponível: %s\n", nome_da_cidade2, vida2, super_ativo2 ? "SIM" : "NÃO");
        printf("Carta02 - Escolha seu atributo:\n");
        printf("1 = ATK\n");
        printf("2 = DEF\n");
        printf("3 = EVA\n");
        printf("4 = SUPER\n");
		scanf("%d", &escolha2);
		if (escolha2 == 4 && super_ativo2) {
			usar_super2 = 1;
			super_ativo2 = 0;
		} else if (escolha2 == 4 && !super_ativo2) {
			printf("Super já foi usado! Escolha outro atributo: ");
			scanf("%d", &escolha2);
		}

		// Mostrar escolhas
		printf("\n%s escolheu: %s\n", nome_da_cidade,
			usar_super1 ? "SUPER" :
			escolha1 == 1 ? "ATK" : escolha1 == 2 ? "DEF" : "EVA");

		printf("%s escolheu: %s\n", nome_da_cidade2,
			usar_super2 ? "SUPER" :
			escolha2 == 1 ? "ATK" : escolha2 == 2 ? "DEF" : "EVA");

		// Verifica uso do super poder
		if (usar_super1 && !usar_super2) {
			printf("\n%s usou o SUPER PODER e venceu a rodada!\n", nome_da_cidade);
			vida2--;
		} else if (usar_super2 && !usar_super1) {
			printf("\n%s usou o SUPER PODER e venceu a rodada!\n", nome_da_cidade2);
			vida1--;
		} else if (usar_super1 && usar_super2) {
			printf("\nAmbos usaram o SUPER PODER! Rodada empatada, ninguém perde vida.\n");
		} else {
			// Verifica se as cartas são exatamente iguais (empate total)
			if (atk1 == atk2 && def1 == def2 && eva1 == eva2) {
				printf("\nRodada empatada! As cartas são idênticas em todos os atributos.\n");
			} else {
				int valor1 = 0, valor2 = 0;

				// Pega o atributo real escolhido por cada jogador
				switch (escolha1) {
					case 1: valor1 = atk1; break;
					case 2: valor1 = def1; break;
					case 3: valor1 = eva1; break;
				}

				switch (escolha2) {
					case 1: valor2 = atk2; break;
					case 2: valor2 = def2; break;
					case 3: valor2 = eva2; break;
				}

				if (valor1 > valor2) {
					printf("\n%s venceu a rodada com o atributo escolhido!\n", nome_da_cidade);
					vida2--;
				} else {
					printf("\n%s venceu a rodada com o atributo escolhido!\n", nome_da_cidade2);
					vida1--;
				}
			}
		}

		// Mostrar vidas
		printf("\nVidas atuais:\n");
		printf("%s: %d\n", nome_da_cidade, vida1);
		printf("%s: %d\n", nome_da_cidade2, vida2);

		rodada++;
	}

	printf("\n--- FIM DE JOGO ---\n");
	if (vida1 <= 0) {
		printf("VENCEDOR: %s \n", nome_da_cidade2);
	} else {
		printf("VENCEDOR: %s \n", nome_da_cidade);
	}
	return 0;

}
