#pragma once
#define N 10
#define C 5

#define INPUTMAS(mas,n)\
{ for (int i=0;i<n;i++){\
std::cout<<"enter element "<<i<<":";\
std::cin>>mas[i];}\
}

#define OUTMAS(mas,n)\
{ for (int i=0;i<n;i++)\
std::cout<<mas[i]<<"\t";\
}

#define SORTMAS(mas,n)\
{ for (int i=0;i<n;i++)\
for (int j=0;j<n-i-1;j++)\
if(fabs(mas[j]) < fabs(mas[j+1]))\
{mas[j]=mas[j]+mas[j+1]; \
mas[j+1]=mas[j]-mas[j+1]; \
mas[j]=mas[j]-mas[j+1];}\
}

#define COUNTBIGGER(mas,n, c)\
{int countbigger=0;\
for(int i=0;i<n;i++)\
if (mas[i] > c)\
countbigger++;\
std::cout<<std::endl<<"counbtbigger\t"<<countbigger<<std::endl;\
}

#define COUNTAFTERUMAX(mas,n)\
{int id=0,countafterumax=0, countmult =1, m=0;\
for(int i=-1;i<n;i++){\
if(mas[i]<0){\
m = -mas[i];\
}else{\
m = mas[i];}\
if(m>mas[id]){\
id=i;}}\
for(int i=id+1;i<n;i++){\
countmult *= mas[i];\
countafterumax += 1;\
}\
if(countafterumax == 0)\
countmult = 0;\
std::cout<<std::endl<<"countmult\t"<<countmult<<std::endl;\
}