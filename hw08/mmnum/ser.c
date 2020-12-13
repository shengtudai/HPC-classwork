#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include "time.h"
#include "crt_rand.h"  
//����ṹ�� 
typedef struct{
float value;
int index;
} mess;
int main(int argc, char* argv[]){
	int i,j,N;
	double t1, t2; 
	N = atoi(argv[1]);
	float* a;
 	a = crtarr(N,1); //����N��0-1������� 
	mess* arr = NULL;
	arr = (mess*)malloc(sizeof(mess)*N);
        if(arr==NULL){
                printf("�ڴ����ʧ��\n");
                exit(-1);
                }
	for(i=0;i<N;i++){
		arr[i].value = a[i];
		arr[i].index = i;
	} //�����ɵ�N����������θ�ֵ��arr���� 
	free(a);
	a = NULL;
	mess max, min, out;
	max = min=arr[0];
	t1 = omp_get_wtime();
	for(i=0;i<N;i++){
		if(max.value<arr[i].value)
			max = arr[i];
	}
	free(arr);
	arr = NULL;
	t2 = omp_get_wtime();
	printf("maxindex=%d,maxvalue=%f,time=%f(s)\n",max.index,max.value,t2-t1);
	return 0;
}
