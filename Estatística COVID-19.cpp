#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <locale.h>
using namespace std;

int main(){
	setlocale(LC_ALL,"");
	double variaP=0, aux=0, diaAnt=0, diaPos=0, qtdDeath1=0, qtdDeath2=0, variaPM=0,aux2=0;
	int dia1, dia2 ,mes;
	string nome, linha;
	char s = 's';
	fstream arquivo;
	arquivo.open("Relação de estatísticas do COVID-19.txt",ios::out|ios::app|ios::in);
	
	cout<<"======================================================\n";
	cout<<"==========adm.programador@outlook.com.br==============\n";
	cout<<"======================================================\n";
	cout<<"==============By João Victor - JÃO====================\n";
	cout<<"======================================================\n\n";
	
	cout<<"Deseja vizualizar os dados do seu arquivo antes ? [s/n]: ";
	cin>>nome;
	
	if(nome == "s" || nome == "S"){
		while(getline(arquivo,linha)){
			cout<< linha <<endl;
		}
		system("pause");
		system("cls");
		arquivo.close();
		arquivo.open("Relação de estatísticas do COVID-19.txt",ios::out|ios::app);
	}
	
	cout<<"Insira o mês referente: ";
	cin>>mes;
	
	system("cls");
	
	while(s == 's' || s == 'S' || s == 'SIM'|| s == 'Sim'){
		cout<<"Insira o número do dia 1 formato 'DD': ";
		cin>>dia1;
		cout<<"Insira o número do dia 2 formato 'DD': ";
		cin>>dia2;
		cout<<"Insira a quantidade de casos do dia 1: ";
		cin>>diaAnt;
		cout<<"Insira a quantidade de mortes do dia 1: ";
		cin>>qtdDeath1;
		cout<<"Insira a quantidade de casos do dia 2: ";
		cin>>diaPos;
		cout<<"Insira a quantidade de mortes do dia 2: ";
		cin>>qtdDeath2;
		cout<<"\n\n";
		
		if(qtdDeath1 < qtdDeath2){
			aux2 = qtdDeath2 - qtdDeath1;
			variaPM = aux2*100/qtdDeath2;
		}
		
		if(diaAnt < diaPos){
			aux = diaPos - diaAnt;
			variaP = aux*100/diaPos;
			
			arquivo<<"--------------------------------------------\n";
			arquivo<<"Dados referente aos dias "<<dia1<<" e "<<dia2<<endl;
			arquivo<<dia1<<"/"<<mes<<" "<<diaAnt<<" casos - "<<qtdDeath1<<" mortes\n";
			arquivo<<dia2<<"/"<<mes<<" "<<diaPos<<" casos - "<<qtdDeath2<<" mortes\n";
			arquivo<<"Casos "<<variaP<<"%"<<endl;
			arquivo<<"Mortes "<<variaPM<<"%"<<endl;
			arquivo<<"--------------------------------------------\n\n";
			
		}
		if(qtdDeath1 > qtdDeath2){
			aux2 = qtdDeath1 - qtdDeath2;
			variaPM = aux2*100/qtdDeath1;
		}
		if(diaAnt > diaPos){
			aux = diaAnt - diaPos;
			variaP = aux*100/diaAnt;
			
			arquivo<<"--------------------------------------------\n";
			arquivo<<"Dados referente aos dias "<<dia1<<" e "<<dia2<<endl;
			arquivo<<dia1<<"/"<<mes<<" "<<diaAnt<<" casos - "<<qtdDeath1<<" mortes\n";
			arquivo<<dia2<<"/"<<mes<<" "<<diaPos<<" casos - "<<qtdDeath2<<" mortes\n";
			arquivo<<"Casos "<<variaP<<"%"<<endl;
			arquivo<<"Mortes "<<variaPM<<"%"<<endl;
			arquivo<<"--------------------------------------------\n\n";
		}
		
		fflush(stdin);
		cout<<"Deseja incluir mais dados? [s/n]:  ";
		cin>>s;
		system("cls");
	}
	arquivo.close();
	
	cout<<"======================================================\n";
	cout<<"==========Dados contidos em seu arquivo local=========\n";
	cout<<"======================================================\n";
	arquivo.open("Relação de estatísticas do COVID-19.txt",ios::in);
	
	if(arquivo.is_open()){
		//getline recebe arquivo e passa para linha, quando for false fecha.
		while(getline(arquivo,linha)){
			cout<< linha <<endl;
		}
	}else
		cout << "Não foi possível recuperar os dados"<<endl;
		
	system("pause");
 
    return 0;
}
