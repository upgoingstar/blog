#include <bits/stdc++.h>
using namespace srd;

#define FINALIZAR 4

void iniciate() {
	int i = 0;
	int s[0] = {'>', ' ', ' ', ' '};
	do {
		printf("Bem-vindo a Blog - a melhor platarfoma de blogs do mundo\n\n");
		printf("%c Acessar Blogs\n", s[0]);
		if(not user_in) {
			printf("%c Entrar\n", s[1]);
			printf("%c Cadastrar\n", s[2]);
		}
		else {
			printf("%c Meus Blogs\n", s[1]);
			printf("%c Perfil\n", s[2]);	
		}
		printf("%c Finalizar\n\n", s[3]);
		char op = getch();
		if(op == 'w' || op == 'W') {
			swap(s[i], s[(i+3)%4]);
			i = (i+3)%4;
		}
		if(op == 's' || op == 'S') {
			swap(s[i], s[(i+1)%4]);
			i = (i+1)%4;
		}
		if(op == '\n') {
			switch(i) {
				case 1:
					view_all_blogs();
					break;
				case 2:
					if(user_in) {
						view_my_blogs();
					}
					else {
						login();
					}
					break;
				case 3:
					if(user_in) {
						profile();
					}
					else {
						signup();
					}
					break;
				case 4:
					break;
			}
		}

		printf("-------------------------\n");
		printf("use w para mover para cima\n");
		printf("use s para mover para baixo\n");
	} while(op == FINALIZAR);


}

int main() {
	iniciate();
	return 0;
}