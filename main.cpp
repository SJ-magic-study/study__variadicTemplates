/************************************************************
************************************************************/
#define CHECK_PRINTF	0
#define CHECK_MIN		1
	#define CHECK CHECK_PRINTF


#if (CHECK == CHECK_PRINTF)
/************************************************************
************************************************************/
#include <stdio.h>

/************************************************************
************************************************************/

/******************************
[C++11 ~] variadic templates
******************************/
template <typename ... Args>
void my_printf(const char *format, Args const & ... args)
{
	printf(format, args ...); // int printf(const char *format, ...);
}

/******************************
[C++11 ~] variadic templates
******************************/
template <typename ... Args>
void my_fprintf(FILE* fp, const char *format, Args const & ... args)
{
	fprintf(fp, format, args ...);
}

/******************************
******************************/
int main()
{
	FILE* fp = fopen("test.txt", "w");
	
	
	int a0 = 10;
	int a1 = 20;
	
	my_printf("printf test : %d, %d\n", a0, a1);
	my_fprintf(fp, "fprintf test : %d, %d\n", a0, a1);
	
	fclose(fp);
	
	return 0;
}



#else
/************************************************************
Variadic Templatesの解説
	https://cpplover.blogspot.jp/2010/03/variadic-templates.html
		Variadic Templatesの解説とその使い方について。
		本格的に使用するのは、なかなか難しそうだが、
		simpleな使用法までは理解できる。
************************************************************/
#include <iostream>

// using namespace std;
using std::cout;

/************************************************************
************************************************************/

/******************************
******************************/
template < typename T >
T _min( T const & a, T const & b )
{
    return a < b ? a : b ;
}

/******************************
******************************/
template < typename T, typename ... Types >
T _min( T const & head, Types ... tail )
{
    return _min( head, _min( tail... ) ) ;
}

/******************************
******************************/
int main()
{
	// std::cout << _min(31, 2232, 9, 9 ) << std::endl;
	std::cout << _min(31, 2232, 9, 9 ) << std::endl;
	return 0;
}

#endif
