#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>

struct person {
   	char name[80];
   	char surname[80];
};

struct connection {
   struct person giver;
   struct person receiver;
};

int main(int args, char* argv[]){
	FILE * fp;
	int i=0;
	int j=0;
	struct person givers[800];
	int receivers[800];
	char *gifts[]={"some chocolate","cufflinks","a CD","whoopie cushion","a lump of coal","a slinky","a lightsabre", "a book about giraffes", "crystal meth", "AIDS", "a puppy (evil)", "a mug", "a gift card (what a lazy bastard)", "a hat", "an ugly sweater"};
	int giftSize=15;

	srand(time(NULL));

	char name[80];
	char surname[80];
   	fp = fopen (argv[1], "r");
	while(fscanf(fp, "%s %s", givers[i].name,givers[i].surname)!=EOF){
		i++;
	}
	for(j=i-1;j>0;j--){
		receivers[j]=j-1;
	}
	receivers[0]=i-1;
	short b=1;
	while(b){
		b=0;
		for(j=0;j<i;j++){
			if(strcmp(givers[j].surname,givers[receivers[j]].surname)==0){
				b=1;
				int r = rand()%i;
				int temp=receivers[j];
				receivers[j]=receivers[r];
				receivers[r]=temp;
			}
		}
	}
	fclose(fp);
	for(j=0;j<i;j++){
		printf("%s %s gave %s to %s %s\n",givers[j].name,givers[j].surname,gifts[rand()%giftSize],givers[receivers[j]].name,givers[receivers[j]].surname);
	}
	
	return 0;
}
