//� ������������ ����� ���� ���������� �� N ������ ��������, �����������:
//������� �������� ������, ������ �� �; ������� �������� ������, �� ����������� ��
//������������ �� ������ ���������.����������� ����� ����� �����, ��� ��������
//��������������� �� �䒺�� ��������, � ���� � �� ������(��������, ��� 0, �������
//    ���������).

#include <iostream>
#include "Header.h"

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
