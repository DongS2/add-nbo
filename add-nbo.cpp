#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	FILE *fp1, *fp2 = NULL;
	uint32_t n1;
	uint32_t n2;
	uint32_t sum;
	int n;
	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");
	if(fp1 == NULL || fp2 == NULL) printf("[-] FILE OPEN FAIL\n");
	else{
		fread(&n, sizeof(int), 1, fp1);
		n1 = ntohl(n);
		fread(&n, sizeof(int), 1, fp2);
		n2 = ntohl(n);
		sum = n1 + n2;
		printf("%d(0x%0x) + %d(0x%0x) = %d(0x%0x)\n", int(n1), n1, int(n2), n2, int(sum), sum);
	}
}
