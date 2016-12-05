#include <stdio.h>
#include <stdlib.h>
#include <playAPC/playapc.h>
#include <windows.h>

int grupo1,grupo2,grupo3,grupo4;

void setOvelhasRestantes(int qt)
{
	int fundoInicial,dialog1,dialog2;
	Ponto pPrincipal;
	int dez, uni;
	
	dez = qt / 10;
	uni = qt - (dez * 10);
	
	printf("%d  %d\n",dez, uni);
	
	pPrincipal.x = 120;
	pPrincipal.y = 80;
	grupo3 = CriaGrupo();
	fundoInicial = AbreImagem("0.png");
	CriaRetangulo(10,15,pPrincipal);
	
	switch(dez)
	{
	case 0: fundoInicial = AbreImagem("0.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 1: fundoInicial = AbreImagem("1.png");
	  			CriaRetangulo(7,15,pPrincipal);
				break;	
		case 2: fundoInicial = AbreImagem("2.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 3: fundoInicial = AbreImagem("3.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 4: fundoInicial = AbreImagem("4.png");
	  			CriaRetangulo(11,15,pPrincipal);
				break;	
		case 5: fundoInicial = AbreImagem("5.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 6: fundoInicial = AbreImagem("6.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 7: fundoInicial = AbreImagem("7.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 8: fundoInicial = AbreImagem("8.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 9: fundoInicial = AbreImagem("9.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		
	}
	
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	  
	Desenha1Frame();
	
    pPrincipal.x = 133;
	pPrincipal.y = 80;
	grupo4 = CriaGrupo();
	
	switch(uni)
	{
		case 0: fundoInicial = AbreImagem("0.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 1: fundoInicial = AbreImagem("1.png");
	  			CriaRetangulo(7,15,pPrincipal);
				break;	
		case 2: fundoInicial = AbreImagem("2.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 3: fundoInicial = AbreImagem("3.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 4: fundoInicial = AbreImagem("4.png");
	  			CriaRetangulo(11,15,pPrincipal);
				break;	
		case 5: fundoInicial = AbreImagem("5.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 6: fundoInicial = AbreImagem("6.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 7: fundoInicial = AbreImagem("7.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 8: fundoInicial = AbreImagem("8.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		case 9: fundoInicial = AbreImagem("9.png");
	  			CriaRetangulo(10,15,pPrincipal);
				break;	
		
	}
	
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	  
	Desenha1Frame();
	

	getchar();
	
}

int main()
{
    int fundoInicial,dialog1,dialog2;
	Ponto pPrincipal;
		
	AbreJanela(720,480,"The Disinvasion Game");
	PintarFundo(0,0,0);
	
	pPrincipal.x = 100;
	pPrincipal.y = 79;
	grupo1 = CriaGrupo();
	  fundoInicial = AbreImagem("ovelha.png");
	  CriaRetangulo(10,11,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	  
	Desenha1Frame();

	pPrincipal.x = 111;
	pPrincipal.y = 82;
	grupo2 = CriaGrupo();
	  fundoInicial = AbreImagem("x.png");
	  CriaRetangulo(5,5,pPrincipal);
	  Pintar(255,255,255);
	  AssociaImagem(fundoInicial);
	  
	Desenha1Frame();
		
	for(int i=35;i>=0;i--){
		setOvelhasRestantes(i);
		ApagaGrupo(grupo4);
	}	
	
	
	Desenha();
	return 0;
}
