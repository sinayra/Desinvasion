#include <stdio.h>
#include <stdlib.h>
#include <playAPC/playapc.h>
#include <windows.h>


int main()
{
    int fundoInicial,dialog1,dialog2;
	int grupoTelaInicial,grupoTelaPorco,grupoTelaOvelha,grupoTelaCitizen;
	Ponto pPrincipal;
		
	AbreJanela(720,480,"The Disinvasion Game - Intro");
	PintarFundo(255,255,255);
	
    pPrincipal.x = -150;
	pPrincipal.y = -100;	  
	grupoTelaInicial = CriaGrupo();
	  fundoInicial = AbreImagem("cenario_dialogo.png");
	  CriaRetangulo(300,200,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	  
	Desenha1Frame();
	
	getchar();
	
	Sleep(500);
	
	pPrincipal.x = 150-146;
	pPrincipal.y = 100-75;
	grupoTelaOvelha = CriaGrupo();
	  fundoInicial = AbreImagem("dialog1.png");
	  CriaRetangulo(146,75,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	Desenha1Frame();
	
	PlaySound("sheep.wav", NULL, SND_FILENAME);
	
	Sleep(500);
	
	pPrincipal.x = -150;
	pPrincipal.y = -100;
	grupoTelaCitizen = CriaGrupo();
	  fundoInicial = AbreImagem("dialog2.png");
	  CriaRetangulo(146,75,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	Desenha1Frame();
	
	PlaySound("citizen.wav", NULL, SND_FILENAME);
	
	Sleep(500);
	
	ApagaGrupo(grupoTelaOvelha);
	
	Sleep(50);
	
	pPrincipal.x = 150-146;
	pPrincipal.y = 100-75;
	grupoTelaOvelha = CriaGrupo();
	  fundoInicial = AbreImagem("dialogo4_Napoleon.png");
	  CriaRetangulo(146,75,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	Desenha1Frame();
	
	/*
	pPrincipal.x = -150;
	pPrincipal.y = 100-75;
	grupoTelaCitizen = CriaGrupo();
	  fundoInicial = AbreImagem("dialogo4_Napoleon.png");
	  CriaRetangulo(146,75,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	Desenha1Frame();
	*/
	
	PlaySound("pig.wav", NULL, SND_FILENAME);
	
	Desenha();
	return 0;
}
