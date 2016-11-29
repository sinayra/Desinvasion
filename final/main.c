#include <stdio.h>
#include <stdlib.h>
#include <playAPC/playapc.h>
#include <windows.h>


int main()
{
    int fundoInicial,dialog1,dialog2;
	int grupoTelaInicial,grupoTelaPorco,grupoTelaOvelha,grupoTelaCitizen;
	Ponto pPrincipal;
		
	AbreJanela(720,480,"The Disinvasion Game - Final");
	PintarFundo(255,255,255);
	
    pPrincipal.x = -150;
	pPrincipal.y = -100;	  
	grupoTelaInicial = CriaGrupo();
	  fundoInicial = AbreImagem("Tela_final_perde.png");
	  CriaRetangulo(300,200,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	  
	Desenha1Frame();
	
	getchar();
	
//	Sleep(500);
	
	
	PlaySound("game_over.wav", NULL, SND_FILENAME);
	
	Desenha();
	return 0;
}
