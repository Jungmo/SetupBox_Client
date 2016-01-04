#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define AUTHSERVER "127.0.0.1:5000/authTest"
#define GOODMESSAGE "LOGIN GOOD"

int authentication()
{
	char auth[1024];
	FILE *fp;
	int isgood=0;
	char email[50];
	char password[30];

	printf("Enter your email : \n");
	scanf("%s", email);
	
	printf("Enter your password : \n");
	system("stty -echo");
	scanf("%s", password);
	system("stty echo");

	sprintf(auth, "http -a %s:%s %s", email, password, AUTHSERVER);
	fp = popen(auth,"r");
	fgets(auth, 1024, fp);
	if(!strcmp(auth, GOODMESSAGE))
	{
		isgood = 1;
	}
	
	if(isgood == 1)
	{
		printf("authentication success!\n");
	}
	else if(isgood == 0)
	{
		printf("register ID first in webpage!\n");
		exit(1);
	}

	pclose(fp);

	return isgood;
}

int init()
{
	/*
	system("mkdir ~/.setupbox");
	system("cd ~/.setupbox");
	system("git init");
	system("git config receive.denyCurrentBranch ignore");
	system("git add . --all");
	system("git commit -m \"initialize git\"");
	*/
	system("mkdir ~/.setupbox");
	system("cd ~/.setupbox\ngit init\ngit config receive.denyCurrentBranch ignore\ngit add . --all\ngit commit -m \"initialize git\"");
	
}	

int clone()
{
	char target_path[1024];
	FILE* get_target_path;
	char clone[1024];

	get_target_path = popen("echo \"/home/$USER/.setupbox SetupBox\"", "r");
	fgets(target_path,1024, get_target_path);
		
	sprintf(clone,"git clone %s", target_path);
	system(clone);
	pclose(get_target_path);
}

int start()
{
	char client[100];
	sprintf(client, "cd SetupBox\nnohup SetupBox_client &> ~/.setupbox/.log.txt &");
	system(client);
}

int install()
{
	system("echo \"authentication\"");
	authentication();
	system("echo \"initialization\"");
	init();
	system("echo \"clone\"");
	clone();
	system("echo \"start\"");
	start();
}
int main(int argc, char **argv)
{
	if(!strcmp(argv[1], "--install"))
	{
		install();
	}
	else
	{
		printf("SetupBox --install");
	}

	return 0;
}

