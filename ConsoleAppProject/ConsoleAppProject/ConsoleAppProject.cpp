#include <iostream>
#include "../../Pract7/Header.h"

//� ������������ ����� ���� ���������� �� N ������ ��������, �����������:
//������� �������� ������, ������ �� �; ������� �������� ������, �� ����������� ��
//������������ �� ������ ���������.����������� ����� ����� �����, ��� ��������
//��������������� �� �䒺�� ��������, � ���� � �� ������(��������, ��� 0, �������
//    ���������).

using namespace std;

int main()
{
    int mas[N];
    INPUTMAS(mas, N);
    OUTMAS(mas, N);
    COUNTBIGGER(mas, N, C);
    COUNTAFTERUMAX(mas, N);
    SORTMAS(mas, N);
    OUTMAS(mas, N);
    return 0;
}