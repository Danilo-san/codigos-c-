#include<iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#define password 2021
using namespace std;
const int n=1000;


int menu(){
	
	int op;
	cout << "********************************************"<<endl;
    cout << "*       ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    cout << "********************************************" <<endl;

	cout <<" Menu de opcoes:" <<endl <<endl;
	cout <<" 1 - Cadastrar Conta Corrente" <<endl;
	cout <<" 2 - Alterar dados de uma Conta Corrente " <<endl;
	cout <<" 3 - Excluir uma Conta Corrente " <<endl;
	cout <<" 4 - Consultar Saldo " <<endl;
	cout <<" 5 - Fazer Deposito " <<endl;
	cout <<" 6 - Realizar Saque " <<endl;
	cout <<" 7 - Transferir Valores " <<endl;
	cout <<" 8 - Mostrar todas as contas e saldos " <<endl;
	cout <<" 9 - Emitir extrato de conta " <<endl;
	cout <<" 10 - Sair" <<endl <<endl;
	cout <<" Escolha uma opcao: " ;
	cin >> op;cout<<endl;
	return op;
	
}


class conta {
	
	private:
	int numeroDAconta ;	
	int numeroDAagencia;
	char nomeTitular[50];
	char cpf[12];
	int saldoinicial;
		
	public:	
	
	conta(){
		
		
	}
	~conta(){
		
	}
				
	void setnomeroDAconta (int numeroconta){
		this->numeroDAconta= numeroconta;
	}
	
	void setnumeroDAagencia ( int numerodaagencia){
		this->numeroDAagencia = numerodaagencia;
		
	}
	
	void setnomeTitular ( char *titular){
		strcpy (this->nomeTitular , titular);
	}
	
	void setcpf( char *cpf){
		strcpy (this->cpf, cpf);
	}
	
	int setsaldoinicial( int saldoinicial){
		if ( saldoinicial > 0){
			this->saldoinicial= saldoinicial;
			
			
		}else{
			return-1;
			
			
	//	return  conta::setsaldoinicial( );
	}
		
		
	}
	
	void mostra(){
			
			cout <<"	NUMERO DA CONTA : "<<this->numeroDAconta<<endl<<"	NUMERO DA AGENCIA : "<<this->numeroDAagencia<<endl
			 <<"	NOME DO TITULAR : "<<this->nomeTitular<<endl
			 <<"	CPF : "<<this->cpf << endl <<"	SALDO DA CONTA :"<<this->saldoinicial;
			
	}
	void mostredst(){
			
			cout <<"	NUMERO DA CONTA : "<<this->numeroDAconta<<endl<<"	NUMERO DA AGENCIA : "<<this->numeroDAagencia<<endl
			 <<"	NOME DO TITULAR : "<<this->nomeTitular<<endl
			 <<"	CPF : "<<this->cpf << endl;
	}
	
	
	
	
	int getnumeroDAconta (){
		return  this->numeroDAconta;
		
	}
	
	int getnumeroDAagencia (){
		
		return this->numeroDAagencia;
	}
	
	char* getnomeTitular (){
		return this->nomeTitular;
		
	}
	
	char* getcpf (){
		
		return this->cpf;
	}
	
	int getsaldoinicial(){
		return this->saldoinicial;
	}
	
	
	
	
	
};

class listacontas{
	private:
	conta cts [n];
	
	int tm;
	
	public:
		listacontas(){
			this->tm=0;
			
		}
		
	void listarconta (conta ct){
			
			this->cts[ this->tm]= ct;
			tm++;
		}	
	void mostra(){
					
		for ( int i=0; i <tm; i++){
			
			 this->cts[i].mostra();
				cout <<endl<<endl;
		}
	}
	void mostrar(){
					
		for ( int i=0; i <tm; i++){
			 
			  //this->cts[i].mostra();
				cout <<endl<<endl;
			//	cout <<"tamanho "<<this->tm;
		}
	}
	
	int altere (int nuconta, int nuagencia){ 
	

		for ( int i = 0; i <= this->tm; i++){
			
			if ( nuconta == this->cts[i].getnumeroDAconta() && nuagencia == this->cts[i].getnumeroDAagencia()){
				
				return i;
				break;
			}
		 		
		}
	
		return -1;
	}
	
	
		
	
	void apaga( int nv ) {
		
		int ne;
		ne = nv;
		
		for ( int i =nv; i <this->tm; i++){
		
		//ne = 
			
		    cts[ne].setnomeroDAconta( cts[ne+1].getnumeroDAconta() );
			cts[ne].setnumeroDAagencia(	cts[ne+1].getnumeroDAagencia() );
				
			cts[ne].setnomeTitular( cts[ne+1].getnomeTitular()) ;
			
			cts[ne].setcpf( cts[ne+1].getcpf()) ;
		
			cts[ne].setsaldoinicial( cts[ ne+1 ].getsaldoinicial() );
			
			
			
			ne++;
		}
				
	this->tm--;
	
	
	
		
		
	}
	
	int mostarconta( int posicao){
		 this->cts[posicao].mostra();
	}
	int mostarcontas( int posicoes){
		 this->cts[posicoes].mostra();
	}
	
	int mostarcontadest( int posicao){	
		 this->cts[posicao].mostredst();
	}
	void setatnome( char *nome, int ps){
		this->cts[ps].setnomeTitular(nome);
	}
	void setatcpf( char *cpff, int ps){
		this->cts[ps].setcpf(cpff);
	}
	int deposito (int valor, int posicaodeposito){
		return cts[posicaodeposito].setsaldoinicial(cts[posicaodeposito].getsaldoinicial()+valor);
		
	}
	int saque (int valor, int posi){
		
			
		 cts[posi].setsaldoinicial(cts[posi].getsaldoinicial() - valor);
		
	
	}
	int saquec ( int valor, int posic){
		for ( int i=0;i <this->tm;i++){
			if ( posic == i){
				cts[i].setsaldoinicial(0-valor);
			}
		}
				
	}
	
	//int trasferi ( int contaorig, int contadest, int valor){
	//cts[contaorig].getsaldoinicial( )
		
		
	//}
	
	int volte(){
		return	this->tm;
	}
	
	
	
	
	
	
	
	void saveaquirvo ( char *banconame){
		ofstream fout;
		fout.open( banconame, ios::binary );
		if (!fout){
			cout << " ERRO AO CRIAR ARQUIRVO"<<endl;
			return;	
		}
		fout.write( (char *)this , sizeof(listacontas) );
		fout.close();
	}
	
	void loadfromfile( char *banconame){
		ifstream fin;
		fin.open( banconame, ios::binary );
		if (!fin){
			cout << " ERRO AO ABRIR ARQUIRVO"<<endl;
			return;	
		}
		fin.read( (char *)this , sizeof(listacontas) );
		fin.close();
		
		
		
	}
	int retornasaldo ( int agencia, int conta){
    	for ( int i=0; i < this->tm; i++){
    		if ( agencia == this->cts[i].getnumeroDAagencia() && conta == this->cts[i].getnumeroDAconta()){
    			return this->cts[i].getsaldoinicial();
			}
		}
	}
		
	
};


class extrato{
	private:
	int conta;
	int agencia;
	char datamove[80];
	char historico[80];
	int valor;
	int saldo;
	int cor;
	char hora[20];
	char nome[50];
	int saldoinicial;
	public:
		
	void setconta (int contas){
		this->conta = contas;
		
	}
	void setcor(int cor){
		this->cor=cor;
	}
	void setagencia ( int agencias){
		
		this->agencia=agencias;
	}
	void setsaldoinicial ( int saldoin){
		
		this->saldoinicial=saldoin;
	}
	
	char setdatamove ( char *data){
		strcpy (datamove,data);
	}
	void sethistorico ( char *historicos){
		strcpy ( this->historico, historicos);
		
	}
	void setnome ( char *nome){
		strcpy ( this->nome, nome);
		
	}
	void sethora ( char *hora){
		strcpy ( this->hora, hora);
		
	}
	
		
	
	void setvalor ( int valora){
		this->valor=valora;
	}
	
	void setsaldo ( int saldoa){
		this->saldo = saldoa;
	}
	//
	int getconta (){
		return	this->conta;
		
	}
	int  getagencia ( ){
		
		return this->agencia;
	}
	int getcor() {
		return cor;
	}
	
	char* getdatamove (){
		return this->datamove;
	}
	char* gethistorico ( ){
		return this->historico;
		
	}
	
	int getvalor ( ){
		return this->valor ;
	}
	
	int getsaldoinicial ( ){
		return this->saldoinicial ;
	}
	
	int getsaldo ( ){
		return this->saldo;
	}
	char* getnome ( ){
		return  this->nome;
		
	}
	char* gethora ( ){
		return  this->hora;
		
	}
	
	void mostra (){
		
	cout << "***************************************************************************" << endl;
	cout << "       			   EXTRATO BANCARIO             :" << endl;
	cout <<endl;
	cout <<  "NOME: "<<this->nome<< "	CONTA: " << this->conta << "						AGENCIA: "<<this->agencia<<endl;
	cout << "DATA: "<<this->datamove<<"		"<<"						HORA:"<<this->hora<<endl;
//	cout <<"SALDO DISPONIVEL: "<<this->saldo<<" R$"<<endl;
	cout << "-----------------------------------------------------------------------------" << endl<<endl;
	
	cout << "*****************************************************************************" << endl;
	cout << "				 HISTORICO            " 	<< endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	
	cout << "DATA			HORA			LACAMANETO			VALOR (R$)			SALDO(R$)    "<<endl;
	cout <<this->datamove <<"			"<< this->hora <<"			"<< "saldo inicial" <<"			"<< this->valor <<"			"<< this->saldoinicial<<endl;
	cout <<this->datamove <<"			"<< this->hora <<"			"<< this->historico <<"			"<< this->valor <<"			"<< this->saldo<<endl;
		
	}
	
	
	
	
};

class listaextratos { 
	private:
	extrato extr[n];
	int tlh;
	
	public:
	
	listaextratos(){
		this->tlh=0;
	}
	
	void add ( extrato ex) {
		this->extr[ this->tlh ]= ex;
		this->tlh++;
		
	}
	
	
	
	
	
	void tela( int contatela, int agenciatela, int posicaov){ // certo
	
		char DATA[80];
		char HORA[80];
		time_t t;
		struct tm * infotempo;
		time(&t);
		infotempo=localtime(&t);
		strftime( HORA, 80, "%I:%M" , infotempo);
		strftime( DATA,80, "%d/%m/%Y", infotempo);
		system("cls");
		//cout << buffer;
		cout << "*******************************************************************************************"<<endl;
   		cout << "*                             ARABANCO - SEMPRE COM VOCE =P      									*"<<endl;
   		cout << "********************************************************************************************" <<endl;
	
		cout << "********************************************************************************************" << endl;
		cout << "       			           EXTRATO BANCARIO             :" << endl;
		cout <<endl;
		cout << "NOME: "<<this->extr[posicaov].getnome() << "						CONTA/AGENCIA: "<< contatela <<"/"<< agenciatela<<endl;
		cout << "DATA: "<<DATA<<"					HORA: "<< HORA<<endl;
		
		cout << "---------------------------------------------------------------------------------------------" << endl<<endl;
		cout << "		  	               HISTORICO											"<<endl;
	   	cout << "---------------------------------------------------------------------------------------------" << endl;	
		cout << "   DATA		HORA		LACAMANETO			VALOR (R$)		SALDO(R$)"<<endl;
		for ( int i=this->tlh; i >=0; i--)	{
		
			if ( contatela == this->extr[i].getconta() && agenciatela == this->extr[i].getagencia()){
				cout <<this->extr[i].getdatamove() <<"	"<< this->extr[i].gethora() <<"		"<< this->extr[i].gethistorico()
				 <<"	    		"<< this->extr[i].getvalor() <<"	 			  "<< this->extr[i].getsaldo()<<"r$"<<endl;
		
			}
	
		}
	   cout << endl<<endl;
	}
	
	

	
	
	
	int posicao (int conta, int agencia ) {
		
		for (int i=0; i<this->tlh; i++){
			
			if ( this->extr[i].getagencia() == agencia && this->extr[i].getconta() == conta ){
				
				
				return i;
				
			}
		}
	return -1;
		
	 	
	}
	int mostranome(int conta,int agencia){
		
		for(int i=0; i < this->tlh; i++){
			if ( conta == this->extr[i].getconta() && agencia == this->extr[i].getagencia() ){
				return i;
				
			}
		}
	}
		
   void saveaquirvo ( char *extrato){
		ofstream fout;
		fout.open( extrato, ios::binary );
		if (!fout){
			cout << " ERRO AO CRIAR ARQUIRVO"<<endl;
			return;	
		}
		fout.write( (char *)this , sizeof(listaextratos) );
		fout.close();
	}
	
	void loadfromfile( char *extrato){
		ifstream fin;
		fin.open( extrato, ios::binary );
		if (!fin){
			cout << " ERRO AO ABRIR ARQUIRVO"<<endl;
			return;	
		}
		fin.read( (char *)this , sizeof(listaextratos) );
		fin.close();	
		
	}

	
    void altnome( char *nome, int ps){
    	this->extr[ps].setnome(nome);
	}
    
   	int listaw ( int contaht , int agenciaht, int posiname, const char HORA[80], const char DATA[80]) { //LISTA DE CONTATOS em html
	
		ofstream fout;
		fout.open("tr.html",ios::app);
		
		if (!fout){
			cout << "ERRO AO CRIAR O ARQUVO";
			system("pause");
		}											
		
		fout << "<html>";
		fout << "<head>";
	//	fout << "<title> 		EXTRATO </title>";
		fout << "</head>";
		fout << "<body bgcolor=""aliceblue"">";
		fout << "<img src=""banco.png"" width =50%"">";

	//	fout << "<h1 = color: red;  >	ETRATO </h1>"; 
		//fout << "<img src=""brasill.png" "width =""40%""> ";
		fout << "<ol>";
		fout << "<pre> ""		EXTRATO BANCÁRIO"" </pre>";
	//	fout << "<table border=" "20" "bordercolor=""green"">";
		fout << "<pre>" <<"NOME: "<<this->extr[posiname].getnome()   << "			AGENCIA/CONTA: "<<agenciaht<<"/"<<contaht << "</pre>";
		fout << "<pre>"<< "DATA: "<< DATA   << "		HORARIO: "<< HORA << "</pre>";
		fout << endl <<endl;
		fout << "<pre>" "   		       HISTORICO" "</pre>";
		
		
		fout << "<table border=" "2" "bordercolor =" "black" ">";
		
		fout << "<tr bgcolor=""SlateGray"">" "<td ""color:""Maroon"">" "DATA"  "</td>" "<td>" " HORA"  "</td>" "<td>" " LANÇAMENTO"  "</td>" "<td>" " VALOR (R$)"  "</td> " "<td>" " SALDO (R$)"  "</td>""</tr>";
		for ( int i = this->tlh;i>0 ;i--){
				
			if ( contaht ==this->extr[i].getconta() && agenciaht == this->extr[i].getagencia())	 {
			
				if ( this->extr[i].getcor() == 0 ){
					fout << "<tr>" "<td> <font color=""Crimson"">" << this->extr[i].getdatamove()<< "</td>"  <<  "<td>" "<font color=""Crimson"">"  << this->extr[i].gethora()<< "</td>" << "<td>" "<font color=""Crimson"">" << this->extr[i].gethistorico()<< "</td>"
							"<td>" "<font color=""Crimson"">" "-"<< this->extr[i].getvalor()<< "</td>" "<td>"  "<font color=""Crimson"">" << this->extr[i].getsaldo()<< "</td>" "</tr>";
				   }
				   if ( this->extr[i].getcor() == 1){
				   		fout << "<tr>" "<td> <font color=""Lime"">" << this->extr[i].getdatamove()<< "</td>"  <<  "<td>" "<font color=""Lime"">"  << this->extr[i].gethora()<< "</td>" << "<td>" "<font color=""Lime"">" << this->extr[i].gethistorico()<< "</td>"
							"<td>" "<font color=""Lime"">" << this->extr[i].getvalor()<< "</td>" "<td>"  "<font color=""Lime"">" << this->extr[i].getsaldo()<< "</td>" "</tr>";
				   	
				   }
			
			}
	   }
		fout << "</table>";
		fout << "</ol>";
		fout << "</body>";
		fout << "</html>";
		fout.close();
		
		system("tr.html");
	
			
		
		
			
		
		
	} 
    
    
    
	
};

   

int main( ){
	
	
	char nomme;		
		
	int retorno;
	char arquivo[] = "tr.html";
	
	
	
	char pl;
    int op;
	conta ct;
	listacontas cts;
	int agencia;
	int ne;
	char cpf[15];
	int contadest;
	int agenciadest;
	int conta;
	int nu;
	int saldo;
	char nome[50];
	int valor;
	int senha;
	char DATA[80];
	char HORA[80];
	time_t t;
	struct tm * infotempo;
	time(&t);
	infotempo=localtime(&t);
	strftime( HORA, 80, "%I:%M" , infotempo);
	strftime( DATA,80, "%d/%m/%Y", infotempo);
	
	extrato x;
	listaextratos etx;




	
	
	do{
	system( "cls" );
//	cts.saveaquirvo("BANCODEDADOS");
//	cts.loadfromfile("BANCODEDADOS");
	op = menu();	
 	cts.loadfromfile("bancodado.dat");
 	etx.loadfromfile("voi.dat");
	//etx.loadfromfile("extrato.dat");
	switch (op ){
		
		case 1:
			system("cls");
			//cout << buffer;
			cout << "********************************************"<<endl;
    		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl;
			cout <<" 	BEM VINDO AO CADASTRO DO ARABANCO"<<endl<<endl;
			cout << "	CADASTRO DA CONTA "<<endl<<endl;
			cout << "	DIGITE NUMERO DA CONTA: ";
			
			cin >> conta;cout <<endl;
			ct.setnomeroDAconta(conta);
			
			cout << "	DIGITE NUMERO DA AGENCIA: "; 
			cin >> agencia;cout<<endl;
			ct.setnumeroDAagencia( agencia);
			if(cts.altere(conta, agencia) > -1){
				cout << " CONTA JA EXISTENTE!! "<<endl;
				cout << " TENTE NOVAMENTE! "<<" VERIFIQUE SE OS DADOS DIGITADO ESTAO CORRETOS "<<endl<<endl;
				system("pause");
				break;
				
			}
			cout << "	DIGITE NOME DO TITULAR: ";
			cin >> nome;cout<<endl;
			ct.setnomeTitular(nome);
			
			cout << "	DIGITE O CPF DO TITULAR :";
			cin >> cpf;cout <<endl;
			ct.setcpf(cpf);
			
			cout << "	DIGITE SEU SALDO INICIAL: ";
			cin >> saldo;cout <<endl;
			ct.setsaldoinicial(saldo);
			if ( 0 > ct.setsaldoinicial(saldo)){
				system("cls");
				cout << "********************************************"<<endl;
    			cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl;
				cout << "	O SALDO NAO PODE SER NEGATIVO "<<endl<<endl;
				system("pause");
				break;
			}
			
			
			
			cout <<"	AGUARDANDO RESPOSTA ";
			for ( int i =0; i < 5;i++){
				
				cout <<"	AGUARDANDO RESPOSTA ...!!";
				system("cls");
			}
			
			cts.listarconta(ct);
			
			cout << "********************************************"<<endl;
    		cout << "*     ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
   			cout << "********************************************" <<endl;
			cout << "	SUA CONTA FOI CRIADA COM SUCESSO!! "<<endl<< endl<< "	BEM VINDO ARABANCO"<< endl<<endl<<"	 EXIBINDO DADOS DA CONTA "<<endl<<endl;
			cts.saveaquirvo("bancodado.dat");
			x.setagencia(agencia);
			x.setconta(conta);
			x.setdatamove(DATA);
			x.sethistorico("saldo inicial");
			x.sethora(HORA);
			x.setnome(nome);
			x.setvalor(saldo);
			x.setsaldo(saldo);
			x.setcor(1);
			etx.add(x);
			etx.saveaquirvo("voi.dat");
		
			//cts.loadfromfile(" vida.txt");
		 	ct.mostra();
			
			cout << endl;
			system("pause");
			break;
			
		case 2:
			cout << "********************************************"<<endl;
  		    cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl;
			if(cts.volte() > 0){
				system("cls");
				cout << "********************************************"<<endl;
    			cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl;
				
				
				cout << "	ALTERAR DADOS DA CONTA"<<endl<<endl;
			//	cout <<"teset "<<cts.volte();
				cout << "	DIGITE O NUMERO DA CONTA :";
				cin >> conta;
				cout <<endl<< "	 DIGITE O NUMERO DA AGENCIA :";
				cin >> agencia;	
				cout <<endl;
				
					//cout << "	posicacao "<< cts.altere(conta,agencia);
					//system("pause");
				if (cts.altere(conta, agencia)  > -1){
					system("cls");
					cout << "********************************************"<<endl;
  		 		    cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    				cout << "********************************************" <<endl;
				
					//cout << " posicaçao"<< cts.altere(nu,na);
					cout << "	DIGITE O NOVO NOME DO TITULAR: ";
					cin  >>nome;cout <<endl;
					cts.setatnome(nome, cts.altere( conta, agencia)); 
					etx.altnome(nome,  etx.posicao(conta, agencia));
					etx.saveaquirvo("voi.dat");
					cout <<"	DIGITE O NOVO CPF!: ";
					cin >> cpf;cout <<endl;
					cts.setatcpf(cpf, cts.altere( conta, agencia));
					system("cls");
					cout << "********************************************"<<endl;
  		 		    cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    				cout << "********************************************" <<endl;
					
					cout <<"	SEUS DADOS FORAM ALTERADOS COM SUCESSO !"<<endl<<endl;
					cts.saveaquirvo("bancodado.dat");
					
					
					cts.mostarconta(cts.altere(conta, agencia));
					
					//cout <<" tamo indo";
				}
				else{
					system("cls");
					cout << "********************************************"<<endl;
  		 		    cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    				cout << "********************************************" <<endl;
    				
					cout <<endl<<"	DADOS INCORRETOS ! POR FAVOR INSIRA NOVAMNETE"<<endl;
					
				}
				cout << endl;
				system("pause");
				break;	
			
			}else{
				system("cls");
				
				cout << "********************************************"<<endl;
  		 	    cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl;
				cout << "	NAO A CONTA EXISTENTE! IMPOSSIVEL FAZER ALTERACOES "<< endl<<endl;
				cout << "	VOLTE AO MENU PRINCIPAL ESCOLHA A OPCAO 1 E FACA SEU CADASTRO "<<endl;
				system("pause");
				break;	
			}	
			
			
			
		case 3:
			
			system("cls");
			
			cout << "********************************************"<<endl;
  		    cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl;
			cout << " INFORME SEUS DADOS PARA  APAGAR SUA CONTA !!"<<endl<<endl;
			cout << " DIGITE O NUMERO DA CONTA :";
			cin >> conta;cout <<endl;
			cout << " DIGITE O NUMERO DA AGENCIA :";
			cin >> agencia;	
			cout <<endl;
			cts.altere(conta, agencia);
			
			if ( cts.altere(conta, agencia) < 0){
				system("cls");
				cout << "********************************************"<<endl;
  		 	    cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl;
				cout  << "	conta inexistente "<<endl<<endl;
				cout <<"	VERIFIQUE SE OS DADOS INSERIDOS ESTAO CORRETO, VOLTE AO MENU PRINCIPAL "<<endl<<endl;
				system("pause");
					break;
			}
			system("cls");
			cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl;
			cts.apaga(	cts.altere(conta, agencia));
			cout << " INFORME SEUS DADOS PARA  CONFIRMA !!"<<endl<<endl;
			cout << " DIGITE O NUMERO DA CONTA :";
			cin >> conta;cout << endl;
			cout << " DIGITE O NUMERO DA AGENCIA :";
			cin >> agencia;	
			cout <<endl;
			
			if(cts.altere(conta, agencia) < 0){
				
				cout <<"	SUA CONTA FOI EXCLUIDA !!"<<endl<<endl;
				cts.saveaquirvo("bancodado.dat");
			}
			
			
			system("pause");
			
			break;
		case 4:
			system("cls");
			cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << " 	CONSULTA DE SALDO"<<endl;
    		cout << "	DIGITE O NUMERO DA CONTA :"; cin >> conta; cout <<endl;
    		cout << "	DIGITE O NUMERO DA AGENCIA :"; cin >> agencia; cout << endl;
    		
    		system("cls");
			cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cts.loadfromfile("bancodado.dat");
    		cts.altere(conta, agencia);
    		if ( 0 > cts.altere(conta, agencia )){
    			system("cls");
    			cout <<cts.altere(conta, agencia);
				cout << "********************************************"<<endl;
  		 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl<<endl;
    			cout << " ESSA CONTA NAO EXIXTE!  VOLTE AO MENU ESCOLHA OPCAO 1 E FASSA SEU CADASTRO! "<<endl<<endl;
    			system("pause");
    			break;
			}
			cout << "  	EXIBINDO CONSULTA "<<endl<< endl;
			cts.mostarconta(cts.altere(conta, agencia));
			cout <<endl<<endl;
			system("pause");
			
			break;
			
		case 5:
			system("cls");
			cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "	DEPOSITO "<<endl<<endl;
    		cout << "	INFORME O NUMERO DA CONTA :"; cin >> conta; cout << endl;
    		cout << "	INFORME O NUMERO DA AGENCIA :"; cin >> agencia; cout << endl;
    		if(cts.altere(conta, agencia) < 0){
				
				cout <<"	ESTA CONTA NAO EXISTE !!"<<endl<<endl;
				system("pause");
				break;
			}
    		system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "	VERIFIQUE SE OS DADOS ESTAO CORRETOS "<<endl<<endl;
    		cts.mostarcontadest(cts.altere(conta, agencia));
    		cout <<endl<<endl<<"   OS DADOS ESTAO CORRETOS S/N ? "; cin >> pl;
    		if ( pl == 's'|| pl== 'S'){
    			cout << "	INFORME O VALOR DO DEPOSITO "<<endl;
    			cout << "R$: ";cin >> valor;
    			cts.deposito(valor, cts.altere(conta, agencia));
    			system("cls");
    			cout << "********************************************"<<endl;
  		 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl<<endl;
    			cout << "       VALOR DEPOSITADO COM SUCESSO ! "<<endl<<endl;
    			x.setagencia(agencia);
				x.setconta(conta);
				x.setdatamove(DATA);
				x.sethistorico("Deposito");
				x.sethora(HORA);
				x.setnome(nome);
				x.setvalor(valor);
				x.setsaldo(cts.retornasaldo(agencia,conta ) );
				x.setcor(1);
				etx.add(x);
				etx.saveaquirvo("voi.dat");
    	
    		
    			cts.saveaquirvo("bancodado.dat");
    		//	cts.mostarconta(cts.altere(conta, agencia));
    			
    			cout << endl<<endl;
    			cout << system("pause");
    			break;
			}else{
				system("cls");
				cout << "********************************************"<<endl;
  		 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl<<endl;
    			cout << "        "<<endl<<endl;
    			cout << " VOLTE AO INICIO E REPITA A OPERACAO!"<<endl<<endl;
    			system("pause");
    			break;
    		
				
			}
			
		case 6:
			system("cls");
			cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "       SAQUE "<<endl<<endl;
    		cout << "	INFORME O NUMERO DA CONTA :"; cin >> conta; cout << endl;
    		cout << "	INFORME O NUMERO DA AGENCIA :"; cin >> agencia; cout << endl;
    		if(cts.altere(conta, agencia) < 0){
				
				cout <<" ESTA CONTA NAO EXISTE !!"<<endl<<endl;
				system("pause");
				break;
			}
    		system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "	VERIFIQUE SE OS DADOS ESTAO CORRETOS "<<endl<<endl;
    		cts.mostarconta(cts.altere(conta, agencia));
    		cout <<endl<<endl<<"  OS DADOS ESTAO CORRETOS S/N ? "; cin >> pl;
    		if ( pl == 's'|| pl== 'S'){
    			cout << "	INFORME O VALOR DO SAQUE "<<endl;
    			cout << "R$: ";cin >> valor;
    			if (cts.saque(valor,cts.altere(conta,agencia)) == -1){
    				
    				system("cls");
    				system("cls");
					cout << "********************************************"<<endl;
    				cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    				cout << "********************************************" <<endl;
    				cout <<"	O VALOR A SER RETIRADO NAO E PERMITIDO POIS SUA CONTA FICARA ZERADA "<<endl<<endl<< "	VOLTE AO MENU E TENTE NOVAMENTE "<<endl<<endl;
    				system("pause");
    				break;
				}
			
    		cts.saquec(valor, cts.altere(conta, agencia));
    		cts.saveaquirvo("bancodado.dat");
    			system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "       VALOR RETIRADO COM SUCESSO ! "<<endl<<endl;
    		x.setagencia(agencia);
			x.setconta(conta);
			x.setdatamove(DATA);
			x.sethistorico("saque	");
			x.sethora(HORA);
			x.setnome(nome);
			x.setvalor(valor);
			x.setsaldo(cts.retornasaldo(agencia,conta ));
			x.setcor(0);
			etx.add(x);
			etx.saveaquirvo("voi.dat");
    		cout << endl<<endl;
    		cout << system("pause");
    		break;
			}
			else{
				system("cls");
    			cout << "********************************************"<<endl;
  		 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl<<endl;
				cout << " POR FAVOR VOLTE AO MENU PRINCIPAL E REPITA A OPERACAO "<<endl;
				
				system("pause");
				break;
				}
				break;
		case 7:
			system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "       TRASFERIR VALORES      ! "<<endl<<endl;
    		cout << " INFORME DADOS DA CONTA ORIGEM  "<<endl;
    		cout << " NUMERO DA CONTA : "; cin >> conta ; cout << endl; cout << "	NUMERO DA AGENCIA :" ; cin >> agencia; cout << endl;
    		if(cts.altere(conta, agencia) < 0){
			cout <<" 	ESTA CONTA NAO EXISTE !! VERIFIQUE OS DADOS DIGITADOS TENTE NOVAMENTE"<<endl<<endl;				system("pause");
				break;
			}
    		cout << "	INFORME DA DADOS DA CONTA DESTINO: "<<endl<<endl;
			cout << "	NUMERO DA CONTA: "; cin >> contadest; cout << "	NUMERO DA AGENCIA: "; cin >> agenciadest; cout << endl;
			if(cts.altere(contadest, agenciadest) < 0){
			cout <<" 	ESTA CONTA NAO EXISTE !! VERIFIQUE OS DADOS DIGITADOS TENTE NOVAMENTE"<<endl<<endl;				system("pause");
				break;
			}
    			system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "       EXIBINDO DADOS ORIGEM  ! "<<endl<<endl;
    		cts.mostarconta(cts.altere(conta, agencia));
    		cts.saveaquirvo("bancodado.dat");
    		cout <<endl<<endl;
    	
    	//	cout << "********************************************"<<endl;
  		 //	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    	//	cout << "********************************************" <<endl<<endl;
    		cout << "       EXIBINDO DADOS CONTA DESTINO   ! "<<endl<<endl;
    		cts.mostarcontadest(cts.altere(contadest, agenciadest));
    			//cts.saveaquirvo("bancodado");
    		
			system("pause");
			if(cts.altere(conta, agencia) < 0){
				
				cout <<" ESTA CONTA NAO EXISTE !!"<<endl<<endl;
				system("pause");
				break;
			}
    		system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "	VERIFIQUE SE OS DADOS ESTAO CORRETOS "<<endl<<endl;
    		cts.mostarconta(cts.altere(conta, agencia));
    		cout <<endl<<endl<<"  OS DADOS ESTAO CORRETOS S/N ? "; cin >> pl;
    		if ( pl == 's'|| pl== 'S'){
    			cout << "	INFORME O VALOR DA TRASFERENCIA "<<endl;
    			cout << "R$: ";cin >> valor;
    			if (cts.saque(valor,cts.altere(conta,agencia)) == -1){
    				
    				system("cls");
    				system("cls");
					cout << "********************************************"<<endl;
    				cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    				cout << "********************************************" <<endl;
    				cout <<"	O VALOR A SER RETIRADO NAO E PERMITIDO POIS SUA CONTA FICARA ZERADA "<<endl<<endl<< "	VOLTE AO MENU E TENTE NOVAMENTE "<<endl<<endl;
    				system("pause");
    				break;
				}
    			cts.saque(valor, cts.altere(conta, agencia));
    			system("cls");
			}
			if ( pl == 'n' || pl == 'N'){
				system("cls");
				cout << "********************************************"<<endl;
    			cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl;
				cout << "  VOLTE AO MENU E REPITA A OPERACAO !"<<endl;
				system("pause");
				break;
			}
    	//	cout <<endl<<endl<<"  OS DADOS ESTAO CORRETOS S/N ? "; cin >> pl;
    	//	if ( pl == 's'|| pl== 'S'){
    		//	cout << "	INFORME O VALOR DO DEPOSITO "<<endl;
    		//	cout << "R$: ";cin >> valor;
    		
    		system("cls");
    		cout << "********************************************"<<endl;
  	 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
   			cout << "********************************************" <<endl<<endl;
   			cout << "       VALOR  TRASFERIDO COM SUCESSO ! "<<endl<<endl;    		
			system("pause");
   			
    		cts.deposito(valor, cts.altere(contadest, agenciadest) );
    		cts.saveaquirvo("bancodado.dat");
    		cts.saque( valor, cts.altere(conta, agencia));
    		cts.saveaquirvo("bancodado.dat");
    		system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "        CONTA ORIGEM ATUALIZADO  ! "<<endl<<endl;
    		cts.mostarconta(cts.altere(conta, agencia));
    		cts.saveaquirvo("bancodado.dat");
    		cout <<endl<<endl;
    		x.setagencia(agenciadest);
			x.setconta(contadest);
			x.setdatamove(DATA);
			x.sethistorico("Transf recebida");
			x.sethora(HORA);
			x.setnome(nome);
			x.setvalor(valor);
			x.setsaldo(cts.retornasaldo(agenciadest,contadest ) );
			x.setcor(1);
			etx.add(x);
			etx.saveaquirvo("voi.dat");
			x.setagencia(agencia);
			x.setconta(conta);
			x.setdatamove(DATA);
			x.sethistorico("Trasf enviada");
			x.sethora(HORA);
			x.setnome(nome);
			x.setvalor(valor);
			x.setsaldo(cts.retornasaldo(agencia,conta ) );
			x.setcor(0);
			etx.add(x);
			etx.saveaquirvo("voi.dat");
    		system("pause");
			break;
				
    	//	cts[cts.altere(contadest, agenciadest)].listarconta(ct);
    	//	cts.saveaquirvo("bancodado");	
    	
    		
    		
    		if (cts.saque( valor, cts.altere( conta, agencia  ) < 0)){
    				
    				system("cls");
    				
    			cout << "********************************************"<<endl;
  		 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl<<endl;
    			cout << "       NAO E POSSIVEL TRASFERIR O VALOR TOTAL  ! "<<endl<<endl<< "			TENTE NOVAMENTE ! "<<endl<<	"		EXIBINDO CONTA ORIGEM ATUALIDADA "<<endl;
    			cts.mostarconta(cts.altere(conta, agencia));
    			cout <<endl<<endl;
    			system("pause");
    			break;
    		
			}
			
    		
			
			
		case 8:
			system("cls");
    		cout << "********************************************"<<endl;
  		 	cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    		cout << "********************************************" <<endl<<endl;
    		cout << "    EXIBIBIR TODAS AS CONTAS ! "<<endl<<endl;
    		cout << "    DIGITE A SENHA DE GERENTE :"; cin >> senha;
    		if ( senha - password == 0){
    				system("cls");
    			cout << "********************************************"<<endl;
  		 		cout << "*       ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl<<endl;
    			cout << "        acesso permitido ! "<<endl<<endl;
    			cout <<endl<<endl;
    			cout << "  EXIBINDO TODAS AS CONTAS"<<endl<<endl;
    			for ( int i =0; i < cts.volte(); i++){
    				cout <<"_______________________________________________________________"<<endl;
    				cout <<"	 EXIBINDO CONTA "<<i + 1<< endl<<endl;
    			
    				
    				cout <<endl<<cts.mostarconta(i )  ;
    		
    				
    				cout << endl<<"--------------------------------------------------------"<<endl;
				}
    			
    			system("pause");
    			break;
			}else{
				
				system("cls");
    			cout << "********************************************"<<endl;
  		 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
    			cout << "********************************************" <<endl<<endl;
    			cout << "       ACESSO NEGADO SENHA INCORRETA  ! "<<endl<<endl;
    			cout <<endl<<endl;
    			cout << "	VEREFIQUE SE A SENHA DIGITA ESTA CORRETA !"<<endl<<endl;
    			system("pause");
    			break;	
			}
    		
		
		case 9:
			system("cls");
    		cout << "********************************************"<<endl;
  	 		cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
   			cout << "********************************************" <<endl;
   			cout << "       EXTRATO BANCARIO    ! "<<endl;    		
			cout << "INFORME A OPCAO ABAIXO PARA OBTER O EXTRATO "<<endl<<endl;
			cout << "1: EXTRATO EM TELA"<<endl;
			cout << "2: EXTRADO EM ARQUIVO "<<endl<<endl;
			cout << "INFORME A OPCAO: ";cin >> ne;
			if ( ne == 1 ){
				
				system("cls");
    			cout << "********************************************"<<endl;
  	 			cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
   				cout << "********************************************" <<endl;
   				cout << "       EXTRATO BANCARIO    ! "<<endl;    			
				cout << "INFORME CONTA: ";cin >> conta;
				cout <<endl<< "INFORME AGENCIA: ";cin >> agencia;
				if ( cts.altere( conta, agencia) < 0 ){
					system("cls");
					cout << "********************************************"<<endl;
  	 				cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
   					cout << "********************************************" <<endl;
   					cout << "       EXTRATO BANCARIO    ! "<<endl<<endl;    
   					cout << "ESSA CONTA NAO EXISTE!  VOLTE AO MENU  E REPITA A OPERACAO!!"<<endl<<endl;
   					system("pause");
   					break;
				
				}
		    
			etx.tela(conta, agencia, etx.mostranome(conta,agencia));
			system("pause");
	   		break;
			
				
					
			}	
			if ( ne == 2 ){
				
				system("cls");
    			cout << "********************************************"<<endl;
  	 			cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
   				cout << "********************************************" <<endl;
   				cout << "       EXTRATO BANCARIO    ! "<<endl;    			
				cout << "INFORME CONTA: ";cin >> conta;
				cout <<endl<< "INFORME AGENCIA: ";cin >> agencia;
				if ( cts.altere( conta, agencia) < 0 ){
					system("cls");
					cout << "********************************************"<<endl;
  	 				cout << "*      ARABANCO - SEMPRE COM VOCE =P      *"<<endl;
   					cout << "********************************************" <<endl;
   					cout << "       EXTRATO BANCARIO    ! "<<endl<<endl;    
   					cout << "ESSA CONTA NAO EXISTE!  VOLTE AO MENU  E REPITA A OPERACAO!!"<<endl<<endl;
   					system("pause");
   					break;
				
			}
			
			etx.listaw(conta,agencia,etx.mostranome(conta,agencia),HORA,DATA);
			
			system("pause");
			remove(arquivo);
   			break;
				
			
		}
			
		
		case 10:
			break;	
		
						
	}
		
	} while ( op != 10 ); //opçao 10 sair
	cts.saveaquirvo("bancodado.dat");
	etx.saveaquirvo("voi.dat");
	return 0;
}
