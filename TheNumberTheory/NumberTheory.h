#pragma once
#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H
typedef int DATA;
typedef int * PDATA;

void ProjectInterface(void); //프로젝트 앱 목록 
void IntegerContents(void);

void InputData(PDATA * data, int n);

bool Divisor_Multiple(int num1, int num2);//약수와 배수 성립되는지 여부
void Get_Gcd(int nume1, int num2);// 최대공약수 노가다방법

int Euclid_Algorithm(int a, int b);//유클리드 알고리즘
int Exp_Euc_Algorithm(int a, int b, int &sValue, int &tValue);//확장된 유클리드 알고리즘ㄴ

//선형 디오판투스 방정식에서 해를 구하기
#define EXP_LEN 12
bool Diophantus(int a, int b, int c);

#endif