#pragma once
#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H
typedef int DATA;
typedef int * PDATA;

void ProjectInterface(void); //������Ʈ �� ��� 
void IntegerContents(void);

void InputData(PDATA * data, int n);

bool Divisor_Multiple(int num1, int num2);//����� ��� �����Ǵ��� ����
void Get_Gcd(int nume1, int num2);// �ִ����� �밡�ٹ��

int Euclid_Algorithm(int a, int b);//��Ŭ���� �˰���
int Exp_Euc_Algorithm(int a, int b, int &sValue, int &tValue);//Ȯ��� ��Ŭ���� �˰���

//���� ��������� �����Ŀ��� �ظ� ���ϱ�
#define EXP_LEN 12
bool Diophantus(int a, int b, int c);

#endif