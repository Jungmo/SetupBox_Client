#include <stdio.h>
#include <string.h>

int main()
{
	char regist[1024];
	int isgood;
	char buff[1024];
	FILE *fp;
	sprintf(regist, "http -a ajm100@ajou.ac.kr:123qwe 127.0.0.1:5000/foo");
	fp = popen(regist,"r");
	fgets(buff, 1024, fp);
	
	printf("%s", buff);
	

	pclose(fp);

	return 0;
}

