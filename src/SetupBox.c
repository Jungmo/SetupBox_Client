#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define AUTHSERVER "127.0.0.1:5000/foo"
#define GOODMESSAGE "LOGIN GOOD"
void dohelp()
{
	printf("If you run first after install SetupBox, initialize first on server-side directory.\n");
	printf("To initialize, do SetupBox --init then enter email and pw with su\n");
	printf("To start, do SetupBox --start\n");
}

int authentication(char* email, char* password)
{
	char auth[1024];
	FILE *fp;
	int isgood=0;
	sprintf(auth, "http -a %s:%s %s", email, password, AUTHSERVER);
	fp = popen(auth,"r");
	fgets(auth, 1024, fp);
	if(!strcmp(auth, GOODMESSAGE))
	{
		isgood = 1;
	}
	return isgood;
}

int main(int argc, char **argv)
{
	int status;

	FILE* userinfo;
	FILE* pathinfo;
	char email[30];
	char password[30];
	char client[1024];
	int isgood;
	char path[1024];
	char clone[1024];
	char user[1024];

	if(!strcmp(argv[1], "--help"))
	{
		dohelp();
		exit(1);
	}

	if(!strcmp(argv[1], "--init"))
	{
		system("git init");
		system("git config receive.denyCurrentBranch ignore");
		system("git add . --all");
		system("git commit -m \"initialize git\"");
		system("mkdir ~/.SetupBox");
		system("pwd > ~/.SetupBox/pathinfo");

		printf("Enter your email : \n");
		scanf("%s", email);
		printf("Enter your password : \n");
		system("stty -echo");
		scanf("%s", password);
		system("stty echo");
		isgood = authentication(email, password);
		if(isgood == 1)
		{
			printf("register & authentication success!\n");
		}
		else if(isgood == 0)
		{
			printf("register ID first in webpage!\n");
		}
		exit(1);
	}

	if(!strcmp(argv[1], "--clone"))
	{	
		printf("Enter your email : \n");
		scanf("%s", email);
		printf("Enter your password : \n");
		system("stty -echo");
		scanf("%s", password);
		system("stty echo");

		isgood = authentication(email, password);
		if(isgood == 1)
		{
			printf("authentication success!\n");
		}
		else if(isgood == 0)
		{
			printf("register ID first in webpage!\n");
			exit(1);
		}
		
		pathinfo = popen("cat ~/.SetupBox/pathinfo", "r");
		fgets(path,1024, pathinfo);
		
		if(strlen(path) == 0)
		{
			printf("Path information file open error!\n");
			dohelp();
			exit(1);
		}
		sprintf(clone,"git clone %s", path);
		system(clone);
	}

	if(!strcmp(argv[1], "--start"))
	{
		printf("Enter your email : \n");
		scanf("%s", email);
		printf("Enter your password : \n");
		system("stty -echo");
		scanf("%s", password);
		system("stty echo");

		isgood = authentication(email, password);
		if(isgood == 1)
		{
			printf("authentication success!\n");
		}
		else if(isgood == 0)
		{
			printf("register ID first in webpage!\n");
			exit(1);
		}
	
		sprintf(client, "nohup client > ~/.SetupBox/log.txt");
		system(client);
	}

	return 0;
}


