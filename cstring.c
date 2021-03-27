#include <stdio.h>
#include <string.h>
#define SIZE 50


// Samet Enes Örsdemir This project provides to users that program can play with strings which are typed by user in txt file. 
//Program have 4 modes such as finding index, string concatenate, str. searching, letter score calculating.

struct String{ //this is struct for string inheritance.
	char sent[50];
	int length;
	
}s1,s2; //defined structs.







int charAt(struct String *s, int index){ // this is first mode. It returns the index of character which is taken from user.    
	
	
	
	if (index>=(*s).length || (*s).sent[index] == '\0' || index < 0 ){
		printf("error");
		return -1;
	}else{
		return((*s).sent[index]);	
	}
	

}


struct String *concat(struct String *sf, struct String *ss){ // this is second mode. It returns a updated string which is concatenated by func. with other string.
	char ort[100]; 
	char buf[100];
	int i=0,j=0;
	while ((*sf).sent[i] != '\0') { //scan first string
        ort[j] = (*sf).sent[i]; 
        i++; 
        j++; 
    } 
  
  
  	
    
    
    i = 0; 
    while ((*ss).sent[i] != '\0') { //scan second string
        ort[j] = (*ss).sent[i]; 
        i++; 
        j++; 
    } 
    
    ort[j] = '\0'; 
    int k;
    int u=0;
	for (k=0;(k<=(*sf).length+(*ss).length);k++,u++){ //concat.
    	if(k==(*sf).length){
    		buf[u] = ' ';
    		
    		
    		u++;
		}
		buf[u] = ort[k];
    	
	}
	strcpy((*sf).sent,buf);
	return (*sf).sent;
    
  
}



unsigned int strSearch(struct String *sff, struct String *ssq){ //this is third mode. it scan first string and return the length of initial segments that contain only the characters of the second string.

	
	
	
	int k = 0;
	int z = 0;
	unsigned int i=0;
	
	char str1[50];
	char str2[50];
	char *token;
	strcpy(str1,(*sff).sent);
	strcpy(str2,(*ssq).sent);
	
	char space[2] = " ";
	unsigned int j=0;

	int key= 1;
    
    	
    	
    	
    	
    while(key == 1 && i<strlen(str1) && j<strlen(str2)){
    	
    	if(str1[i]!= str2[j]){
    		i++;
    		j=0;
		}else if(str1[i] == str2[j]){
			i++;
			j++;
			
		}
						
    			
	}
	
	token = strtok(str1,space);
	
	while(key==1 && token != NULL ) {
	z=0;	
		 
      	while(token[z]!='\0'){
      		
			z++; 
			k++;
			if(k==i-1){
				
				key = 0;
				return strlen(token);
			}
      	
      	
	  }
    
      token = strtok(NULL, space);
   }
			
			
		
		
    	
    	
    	
	
    	
	
	
	
	
	
}


unsigned int findScore(struct String *st1){ //this is fourth mode. it calculates letters points by referencing to given alphabet score table. At the end, it returns result.
	int i = 0;
	unsigned int score = 0;
	while ((*st1).sent[i] != '\0'){
		if (tolower((*st1).sent[i]) == 'a' || tolower((*st1).sent[i] )== 'e' || tolower((*st1).sent[i] )== 'i' || tolower((*st1).sent[i] )== 'o'|| tolower((*st1).sent[i] )== 'u'|| tolower((*st1).sent[i] )== 'l'|| tolower((*st1).sent[i] )== 'n'|| tolower((*st1).sent[i] )== 'r'|| tolower((*st1).sent[i] )== 's'|| tolower((*st1).sent[i] )== 't'){
			score ++;
			
		}
		if (tolower((*st1).sent[i] )== 'd'|| tolower((*st1).sent[i] )== 'g'){
			score += 2;
		}
		if (tolower((*st1).sent[i] )== 'b'|| tolower((*st1).sent[i] )== 'c'|| tolower((*st1).sent[i] )== 'm'|| tolower((*st1).sent[i] )== 'p'){
			score += 3;
		}
		if(tolower((*st1).sent[i] )== 'f'|| tolower((*st1).sent[i] )== 'h'|| tolower((*st1).sent[i] )== 'v'|| tolower((*st1).sent[i] )== 'w'|| tolower((*st1).sent[i] )== 'y'){
			score += 4;
		}
		if(tolower((*st1).sent[i] )== 'k'){
			score += 5;
		}
		if(tolower((*st1).sent[i] )== 'j'|| tolower((*st1).sent[i] )== 'x'){
			score += 8;
		}
		if(tolower((*st1).sent[i] )== 'q'|| tolower((*st1).sent[i] )== 'z'){
			score += 10;
		}
		
		
		i++;
		
	}
	return score;
}

	
	
int stat(char *stat_string, int wrdn){ // this is a statistical data command that counts letters and words which are taken from .txt file.
	int i = 0;	
    while(stat_string[i]!='\0')
    {
        
        if(stat_string[i]==' ' ||  stat_string[i]=='\t')
        {
            wrdn++;
        }

        i++;
    }

    
	
	return(wrdn+1);	
}

int stat_letter(char *stat_string, int ltter){ // this is coded for support the stat func.
	int i = 0;
	
    while(stat_string[i]!='\0')
    {
        if((stat_string[i]>='a' && stat_string[i]<='z') || (stat_string[i]>='A' && stat_string[i]<='Z'))
        {
            ltter++;
       
	   }

        i++;
        
    }
    
   
    return (ltter);

}







int main(int argc, char *argv[]) {
	int key, value;
	int len;
	int word_number = 0;
	int letter_number = 0;
	char user[SIZE] ;
	char words[SIZE];

	
	unsigned int mod;
	
	char val[SIZE];
	char st[SIZE] = "stat";
	char ex[SIZE] = "exit";
	char qf[SIZE];
	char sf[SIZE];
	FILE *inptr, *outptr; // file pointers.
	
	
	outptr = fopen("output.txt","w"); //output file 
	
	if ((inptr = fopen("input.txt","r")) == NULL){ //input file (with check system) 
		puts("File does not exist.");
	}else{ // if file exists --
		while(!feof(inptr)){
		
			fscanf(inptr,"%49[^:]:%d,%s",user, &mod,val); // file scanner. it takes characters before and after colon. 
		
			int i =0;
		
		
		
			sscanf(user,"%s%s",qf,sf); // this is second scanner for taken data from first scanner.
			
			
			if (strcmp(st,qf)==0){ //if data equals "stat".
				fprintf(outptr,"\nThe number of words: %d", word_number);
				fprintf(outptr,"\nThe number of letters: %d", letter_number);
				
				printf("\nThe number of words: %d", word_number);
				printf("\nThe number of letters: %d", letter_number);
			}
			if (strcmp(ex,sf)==0){ //if data equals "exit".
				fclose(inptr);
				return 0;
			}
			else{
		
				sscanf(user,"%49[^:]:%d,%s",words,&mod,val); // this is third scanner for taken data from second scanner. All of these scanners are coded for maximum filtering.
				
				
				if(mod == 1){ //if input is 1.
				
					int new_val =(int) strtol(val, (char **)NULL, 10);
					
					
					strcpy(s1.sent,words);
					int len=0;
					for (len = 0; s1.sent[len] != '\0'; ++len);
					
					s1.length = len;
					
					fprintf(outptr,"%c", charAt(&s1,new_val));
					printf("%c",charAt(&s1,new_val));
					
					word_number = stat(&s1, word_number); //this provides the sending datas to stat func. (word counting)
					
	
					letter_number = stat_letter(&s1,letter_number); //this provides the sending datas to stat func. (letter counting)
					
					
				}
				if(mod == 2){ //if input is 2.
				
					int len=0;
					
					int len1=0;
					
					
					
					strcpy(s1.sent,words);
					strcpy(s2.sent,val);
					
					for (len = 0; s1.sent[len] != '\0'; ++len);
					s1.length = len;
					
					for (len1 = 0; s2.sent[len1] != '\0'; ++len1);
					s2.length = len1;
					
					word_number = stat(&s1,word_number);
					
					word_number = stat(&s2,word_number);
					
					
	
					letter_number =stat_letter(&s1,letter_number);
					letter_number =stat_letter(&s2,letter_number);
					
					fprintf(outptr,"%s", concat(&s1,&s2));
					printf("%s",concat(&s1,&s2));
	
					
				}
				if(mod==3){ //if input is 3.
					
					strcpy(s1.sent,words);
					strcpy(s2.sent,val);
					
					for (len = 0; s1.sent[len] != '\0'; ++len);
					s1.length = len;
					int len1= 0;
					for (len1 = 0; s2.sent[len1] != '\0'; ++len1);
					s2.length = len1;
					
					fprintf(outptr,"\n%d",strSearch(&s1.sent,&s2.sent));
					printf("\n%d",strSearch(&s1.sent,&s2.sent));
	
					word_number = stat(&s1,word_number);
					word_number = stat(&s2,word_number);
	
					letter_number = stat_letter(&s1,letter_number);
					letter_number = stat_letter(&s2,letter_number);
					
				}
				if(mod==4){ //if input is 4.
					
					strcpy(s1.sent,words);
					
					fprintf(outptr,"\n%d",findScore(&s1.sent));
					printf("\n%d",findScore(&s1.sent));
	
					word_number = stat(&s1, word_number);
	
					letter_number = stat_letter(&s1,letter_number);
				}
			}
	
		

		}
	
		fclose(inptr); //file is closed.
	
		
		
		
		
		
		
		
	}
	
	

	
	
	
	
	
		
		
}
	
	
    
	
	
	
	
	
	

