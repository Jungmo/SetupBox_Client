#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dohelp()
{
	printf("If you run first after install SetupBox, initialize first on server-side directory.\n");
	printf("To initialize, do SetupBox --init then enter email and pw with su\n");
	printf("To start, do SetupBox --start\n");
}

int main(int argc, char **argv)
{
	int status;

	FILE* userinfo;
	FILE* pathinfo;
	char email[30];
	char password[30];
	char client[1024];
	int isgoodemail;
	char path[1024];
	char regist[1024];
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
		system("pwd > ~/pathinfo");
//		do{
			printf("Enter your email : \n");
			scanf("%s", email);
//			if(strstr(email, "@") != NULL)
//			{
//				isgoodemail = 1;
//			}
//			
//		}while(isgoodemail<0);
		
		printf("Enter your password : \n");
		system("stty -echo");
		scanf("%s", password);
		system("stty echo");
		sprintf(user,"echo \"email:%s\npassword:%s\" > ~/userinfo", email,password);
		system(user);
		printf("register success!\n");
		exit(1);
	}

	if(!strcmp(argv[1], "--clone"))
	{
			pathinfo = fopen("/home/neil/pathinfo", "r");
			if(pathinfo == NULL)
			{
				printf("Path information file open error!\n");
				dohelp();
				exit(1);
			}
			fscanf(pathinfo,"%s",path);
			sprintf(regist,"git clone %s", path);
			system(regist);
	}

	if(!strcmp(argv[1], "--start"))
	{
		userinfo = fopen("/home/neil/userinfo", "r");
			if(userinfo == NULL)
		{
			printf("User information file open error!");
			dohelp();
			exit(1);
		}
		
		fscanf(userinfo,"email:%s\npassword:%s",email, password);
		if(strlen(email) == 0 || strlen(password) == 0)
		{
			printf("User information error!\n");
			dohelp();
			exit(1);
		}
		sprintf(client, "nohup client %s %s &",email, password);
		system(client);
	}

	return 0;
}


