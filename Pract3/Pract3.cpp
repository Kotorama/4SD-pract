// 14. Введене речення обробити так, щоб його послідовність слів надрукувати у зворотному порядку
#include <iostream>
#include <conio.h>
#include <string.h>

void appchar(char* str, char ch) {
	int len = strlen(str);

	str[len] = ch;

	str[len + 1] = '\0';
}

int main()
{
	char inits[] = " Repetitio est, mater studiorum !";
	char result[] = "";
	int i = 0, col = 0;
	char spec[] = " ;!,.?\t";
	int strLen = strlen(inits);
	while (i < strLen)
	{
		if (!strchr(spec, inits[i]))
		{
			col++;
			char word[] = "";
			while (!strchr(spec, inits[i]) && i < strLen)
			{
				appchar(word, inits[i]);
				i++;
			}
			strcat_s(word, result);
			appchar(word, spec[0]);
			std::swap(result, word);
		}
		else
		{
			while (strchr(spec, inits[i]) && i < strLen)
				i++;
		}
	}
	std::cout << "\nWord count=" << col << '\n';
	std::cout << result << '\n';
	_getch();//затримка экрану
	return 0;
}
