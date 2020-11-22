#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "mlib.h"

void main(int argc,char *argv[])
{
	bool ifPause=true;
	int runTimes=0;
	int iptf=-1,ipte;
	char fmk[30]="fmk.exe",fa[30]="ans.exe",fm[30]="my.exe",ck[30]="fc";
	for(int i=1;i<argc;i++)
	{
		char *p=argv[i];
		if(p[0]!='-')
			continue;
		switch (p[1])
		{
			case 'a':
				runTimes=-1;
				break;
			case 't':
				sscanf(argv[++i],"%d",&runTimes);
				break;
			case 'i':
				iptf=i+1;
				sscanf(argv[++i],"%d",ipte);
				ipte+=iptf;
				if(ipte>argc)
				{
					printf("ERROR!\n");
					return;
				}
				i=ipte;
			case 'g':
				sscanf(argv[++i],"%s",fmk);
				break;
			case 'c':
				sscanf(argv[++i],"%s",fa);
				break;
			case 'm':
				sscanf(argv[++i],"%s",fm);
				break;
			case 'k':
				sscanf(argv[++i],"%s",ck);
			default:
				break;
		}
	}
	for(int i=0;i<runTimes||runTimes==-1;runTimes==-1?0:i++)
	{
		printf("State %d:\n",i);
		char cache[50];
		sprintf(cache,"%s",fmk);
		for(int j=iptf;i<ipte;i++)
			sprintf(cache+strlen(cache)," %s",argv[i]);
		system(cache);
		clock_t start,end;
		start=clock();
		system(fa);
		end=clock();
		printf("Ans:%dms\n",end-start);
		start=clock();
		system(fm);
		end=clock();
		printf("My:%dms",end-start);
		sprintf(cache,"%s %s %s",ck,fa,fm);
		system(cache);
		if(ifPause)
			system("pause");
	}
	return;
}
