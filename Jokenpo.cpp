#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Nome do Jogador
char nomeJogador(char name[20]){
	
	printf("Nome de Usuario: ");
	fgets(name, 20, stdin);
	
	return name[20];
}

int escolha(int escolhaJogador){

	printf("	ATAQUES\n");
	printf("=-=-==--=-=-=-=-=-=-\n");
	printf("1 - Pedra\n");
	printf("2 - Papel\n");
	printf("3 - Tesoura\n");
	printf("=-=-==--=-=-=-=-=-=-\n");
	
	do{
		printf("Escolha: ");
		scanf("%d", &escolhaJogador);
	}while(escolhaJogador < 0 || escolhaJogador > 3);
	
	return escolhaJogador;
}

int escolhaPC(int escolha){
	
	escolha = rand() % 3;
	
	return escolha;
}

void regras(){
	
	system("cls");
	
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("		REGRAS\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("1 - PEDRA EMPATA COM PEDRA, GANHA DE TESOURA E PERDE PARA O PAPEL\n");
	printf("2 - PAPEL EMPATA COM PAPEL, GANHA DE PEDRA E PERDE PARA A TESOURA\n");
	printf("3 - TESOURA EMPATA COM TESOURA, GANHA DE PAPEL E PERDE PARA A PEDRA\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	system("pause");
}

void batalha(){
	
	system("cls");
	
	int escolhaJogador = 0, escolhaAdversario = 0;
	int encerra = 1, pontosJogador = 0, pontosAdversario = 0, rodada = 1, opcao = 0;
	
	char name[20];
	name[20] = nomeJogador(name);
	
	printf("\n\n");
	
	printf("Gostaria de ver as Regras?\n");
	printf("[1] - SIM | [2] - NAO\n");
	
	do{
		printf("Escolha:  ");
		scanf("%d", &opcao);
	}while(opcao < 0 || opcao > 2);
	
	
	if(opcao == 1){
		regras();
	}
	
	system("cls");
	
	printf("\n+-+-+-+-+-+-+-+-+-+-+--+++--+-+-+--+-+-+-+-+-+-+-+-+-+--+-+-+-+--+\n");
	printf("Lembrete: Quem Fizer os 3 pontos Primeiro Ganha o Jogo!!!\n");
	printf("+-+-+-+-+-+-+-+-+-+-+--+++--+-+-+--+-+-+-+-+-+-+-+-+-+--+-+-+-+--+\n\n");
	
	while(encerra != 0){
		
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--\n");
		printf("		PLACAR DO JOGO\n");
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--\n");
		printf(" RODADA: %d\n", rodada);
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--\n");
		printf(" %s: %d\n", name, pontosJogador);
		printf(" Adversario: %d\n", pontosAdversario);
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--\n");
		
		escolhaJogador = escolha(escolhaJogador);
		escolhaAdversario = escolhaPC(escolhaAdversario);
		
		// 1 PEDRA 2 PAPEL 3 TESOURA
		if(escolhaJogador == 1){
			if(escolhaAdversario == 1){
				printf("Empatou!!\n");
			}else if(escolhaAdversario == 2){
				printf("Adversario Ganhou!!\n");
				pontosAdversario += 1;
			}else{
				printf("%s Ganhou!!\n", name);
				pontosJogador += 1;
			}
		}else if(escolhaJogador == 2){
			if(escolhaAdversario == 1){
				printf("%s Ganhou!!\n", name);
				pontosJogador += 1;
			}else if(escolhaAdversario == 2){
				printf("Empatou!!\n");
			}else{
				printf("Adversario Ganhou!!\n");
				pontosAdversario += 1;
			}
		}else{
			if(escolhaAdversario == 3){
				printf("Adversario Ganhou!!\n");
				pontosAdversario += 1;
			}else if(escolhaAdversario == 2){
				printf("%s Ganhou!!\n", name);
				pontosJogador += 1;
			}else{
				printf("Empatou!!\n");
			}
		}
		
		if(pontosJogador == 3 || pontosAdversario == 3){
			encerra -= 1;
		}
		
		system("pause");
		system("cls");
		rodada++;
	}
	
	if(pontosJogador > pontosAdversario){
		printf("Voce Ganhou, Meus Parabens\n\n");
	}else if(pontosJogador == pontosAdversario){
		printf("Nao teve Vitoria e nem Derrota\n\n");
	}else{
		printf("Voce Perdeu, Seu Ruim\n\n");
	}
	
	system("pause");
	system("cls");
	
}

void credits(){
	
	system("cls");
	
	printf("Obrigado por Jogar <3\n");
	printf("Espero que tenha gostado da experiencia\n");
	printf("Nos vemos em outros jogos\n");
	printf("Adeus Cavaleiro\n\n");
	
	system("pause");
	printf("\n");
	
	printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
	printf("		- CREDITOS - \n");
	printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
	printf(" Desenvolvedor: DukeD\n");
	printf(" Desenvolvedor Graphics: DukeD\n");
	
	printf(" 		DK & 2022\n");
	
	printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
	
	system("pause");
	exit(1);
	
}

int main(){
	
	int opcao = 0, continuar = 0;
	
	batalha();
	
	while(continuar != 1){
		printf("Deseja Jogar Novamente ?\n");
		printf("[1] - SIM | [2] - NAO\n");
		
		do{
			printf("Escolha:  ");
			scanf("%d", &opcao);
		}while(opcao < 0 || opcao > 2);
		
		
		if(opcao == 1){
			batalha();
		}else{
			credits();
		}
	}
	
	return 0;
}
