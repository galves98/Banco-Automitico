#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using std::string;
using std::vector;

class Movimentacao{
	private:
	vector<string> dataMov;
	string descricao;
	char debitoCredito;
	double valor;
	friend class Conta;
	friend class Cliente;
	friend class Banco;
	friend class Interface;
	public:
	Movimentacao(string d, char op, double v);
	Movimentacao(string d, char op, double v, string ano, string mes, string dia);
	vector<string> getDataMov();
	string getDescricao();
	char getOp();
	double getValor();
	void setDescricao(string descr);
	void setOp(char db);
	void setValor(double v);
	void print();

};

#endif //MOVIMENTACAO_H
