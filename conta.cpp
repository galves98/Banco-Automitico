#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "movimentacao.h"
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
using namespace std;

void Conta::print(){
		cout << "numero = " << numConta << endl;
		cout << "cliente:" << endl;
		cliente->print();
		cout << "saldo = " << saldo << endl;
		cout << "movimentacao tamanho: ";
		cout << movimentacoes.size()<< endl;
}

int Conta::proximoNumConta = 0;

bool Conta::debitar(double v, string d){
	if(saldo - v >= 0){
		Movimentacao mov(d,'D',v);
		saldo -= v;
		movimentacoes.push_back(mov);
		for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
			cout << "mov descricao :  "<< i->descricao << endl;
		}
		return true;
	}
	else{
		cout << "Saldo insuficiente" << endl;
		return false;
	}
}

bool Conta::debitar(double v,Movimentacao mov){
	if(saldo - v >= 0){
		saldo -= v;
		movimentacoes.push_back(mov);
		for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
			cout << "mov descricao :  "<< i->descricao << endl;
		}
		return true;
	}
	else{
		cout << "Saldo insuficiente" << endl;
		return false;
	}
}



void Conta::creditar(double v, string d){
	Movimentacao mov(d,'C',v);
	saldo += v;
	movimentacoes.push_back(mov);
	for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
		 cout << "mov descricao :  "<< i->descricao << endl;
	}
}



// Conta::Conta(){}
Conta::Conta(Cliente *c){
	saldo = 0.0;
	cliente = c;
	proximoNumConta++;
	numConta = proximoNumConta;
}
int Conta::getNumConta(){ return numConta; }
double Conta::getSaldo(){ return saldo; }
Cliente* Conta::getCliente(){ return cliente; }
//list<Movimentacao> Conta::getMovimentacoes(){ return movimentacoes;}



list<Movimentacao> Conta::extrato(){
	if (!movimentacoes.empty()) {
		time_t rawtime;
		string a, m;
		struct tm* timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 80, "%Y", timeinfo);
		a = buffer;
		strftime(buffer, 80, "%m", timeinfo);
		m = buffer;
		list<Movimentacao> res;
		for (list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++) {
			if (it->dataMov[0] == a  && it->dataMov[1] == m) {
				res.push_back(*it);
			}
		}
		if (!res.empty()) {
			return res;
		}
		else {
			cout << "O extrato esta vazio para o mes corrente." << endl;
		}
	}
	else { cout << "A conta nao tem movimentacoes." ;}
}

list<Movimentacao> Conta::extrato(vector<string> di){
	list<Movimentacao> res;
	if (!movimentacoes.empty()) {
		for (list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++) {
			if (it->dataMov[0] >= di[0] && it->dataMov[1] >= di[1] && it->dataMov[2] >= di[2]) {
				res.push_back(*it);
			}
		}
		if (!res.empty()) {
			return res;
		}
		else {
			cout << "O extrato esta vazio a partir da data selecionada." << endl;
			return res;
		}
	}
	else {
		cout << "A conta nao tem movimentacoes." ;
		return res;
	}
}
/////////////////////////////////Se o ano e o mes forem difernetes da erro na validaçao dos dias
// list<Movimentacao> Conta::extrato(vector<string> di, vector<string> df){
// 	list<Movimentacao> res;
// 	int aux123=0;
// 	if(!movimentacoes.empty()){
// 		for(list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++){
// 			cout << "dataMov0 " << it->dataMov[0]<<"  dataMov1 " << it->dataMov[1]<< "   dataMov2 " << it->dataMov[2]<<endl;
// 			// if (it->dataMov[0] >= di[0] && it->dataMov[1] >= di[1] && it->dataMov[2] >= di[2] && it->dataMov[0] <= df[0]
// 			// 	&& it->dataMov[1] <= di[1] && it->dataMov[2] <= di[2]){
// 			if(it->dataMov[0] >= di[0] && it->dataMov[0] <= df[0]){
// 				cout << "asldkfjals" << endl; ////////////
// 				if(di[0]==df[0] && it->dataMov[1] >= di[1] && it->dataMov[1] <= df[1]){
// 					cout << "if 2" << endl; ///////
// 						if((di[1]==df[1]) && (it->dataMov[2] >= di[2] && it->dataMov[2] <= df[2])){
// 							cout << "valor:: "<< it->valor << endl ;
// 							res.push_back(*it);
// 						}
// 						else if(di[1]<df[1]){
//
// 						}
// 					}
// 				}
// 			}
//
//
// 		if (!res.empty()) {
// 			return res;
// 		}
// 		else {
// 			cout << "O extrato esta vazio a partir da data selecionada." << endl;
// 			return res;
// 		}
// 	}
// 	else {
// 		cout << "A conta nao tem movimentacoes." ;
// 		return res;
// 	}
// }




Conta::~Conta(){}
