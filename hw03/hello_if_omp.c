#include <stdio.h>
#include <omp.h>
int main(){
	#ifdef _CN
	#pragma omp parallel
	{
	int ID = omp_get_thread_num();
	printf("���(%d)",ID);
	printf("����(%d)\n",ID);
	}
	#else
	#pragma omp parallel
	{
	int ID = omp_get_thread_num();
	printf("Hello(%d)",ID);
	printf("World(%d)\n",ID);
	}
	#endif
return 0;}
