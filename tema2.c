#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordonare_crescatoare( char d[1001][1001], int nr1, int nr2)
{
    int i, j;
    char aux[1001];
    for (i = nr1; i < nr2 ; i++){ //bubble sort 
        for(j = i+1; j <= nr2; j++){
            if( strcmp(d[i], d[j]) > 0){
                strcpy(aux, d[i]);
                strcpy(d[i], d[j]);
                strcpy(d[j], aux);
            }
        }
    }
}

void ordonare_descrescatoare( char d[1001][1001], int nr1, int nr2)
{
    int i, j;
    char aux[1001];
    for (i = nr1; i < nr2 ; i++){ //bubble sort
        for(j = i+1; j <= nr2; j++){
            if( strcmp(d[i], d[j]) < 0){
                strcpy(aux, d[i]);
                strcpy(d[i], d[j]);
                strcpy(d[j], aux);
            }
        }
    }
}

int lung_max(char d[1000][1001], int ld)
{
	//returneaza cea mai lunga linie 
    int i, maxlung=0;
    for( i = 0; i < ld; i++){
        if(strlen(d[i]) > maxlung){
            maxlung = strlen(d[i]);
        }
    }

    return maxlung;
}

void elim_spini(char *sir)
{
    char *aux = malloc(1001); 
    while(strlen(sir) > 0 && sir[0] == ' '){
        strcpy(aux, sir+1); //elimina cate un spatiu
        strcpy(sir , aux); //copiem sirul aux in sirul initial
    }     
} 

void elim_spfin(char *sir)
{
  	while (strlen(sir) > 0 && sir[strlen(sir)-1] == ' '){
        sir[strlen(sir)-1] = 0; 
    }        
}  

void parsare(char *commc, int *nr1c, int *nr2c)
{   
    char *adr, sirnr1[21], sirnr2[21]; 
   	
   	elim_spini(commc); //elimina spatiile initiale ale comenzii

    if(strlen(commc) == 0){
        *nr1c = -1; //ne arata ca nu exista nr1, respectiv nr2
        *nr2c = -1;
        return;
    }

    adr = strchr(commc , ' '); 
    //intoarce un pointer catre prima aparitie a spatiului in comanda

    if ( adr != NULL){
        strcpy(sirnr2, adr+1);
        *adr = 0;
        strcpy(sirnr1, commc);
        *nr1c = atoi(sirnr1); //converteste sirul de caractere in numar intreg
        *nr2c = atoi(sirnr2); 
        //daca exista 2 parametrii
    } 
    else {
        strcpy(sirnr1, commc);
        *nr1c = atoi(sirnr1);
        *nr2c = -1;
        //daca exista doar un parametru
    }

}

int main(int argc, char *argv[])
{   
    char s[1000][1001]; //sursa
    char d[1000][1001]; //destinatia
    char spatiu[1000], spatiu2[1000], comm[201], aux[1001];
    char literac, tip, car, tipord;
    char *commc, *adr;

    int i=0, j, k, nrlins, nrlind, maxlung, nrcentru, nr;
    int dif, nr1, nr2, nrsp;
          
    FILE *in = fopen(argv[2],"r");
    FILE *out = fopen(argv[3],"w");
    strcpy(comm, argv[1]);
    while(fgets(s[i], 1001, in))
    {
        s[i][strlen(s[i])-1] = 0;
        strcpy(d[i], s[i]); 
        //pentru comenzile L consideram destinatia egala cu sursa
        i++;
    }

    nrlind = i; //numara linii destinatie
    nrlins = i;  //numara linii sursa
   
    fclose(in);

    nrsp = 0;

    commc = strtok(comm , ","); //imparte sirul in functie de virgula
    while(commc != NULL){
        elim_spini(commc);
        literac = commc[0]; //retine litera din comanda
        strcpy(commc, commc + 1);
        elim_spini( commc);

        switch(literac)
        {
            case 'W': 
                        maxlung = atoi(commc);//max_line_lenght 
                        j=0; //linia curenta din textul destinatie
                        i=0; //linia curenta din textul sursa
                        do{
                            strcpy(d[j], ""); 
                            //sirul destinatie este initial sirul vid
                            while(i < nrlins && strlen(s[i])>0 && 
                             strlen(d[j]) + strlen(s[i]) <= maxlung){
                                elim_spini(s[i]);
                            	elim_spfin(d[j]);
                            	/* elimina spatiile initiale liniei curente
                            	 din textul sursa
                            	elimina spatiile finale liniei curente din
                            	 textul destinatie */
                            	 
                                if(strlen(d[j]) > 0){ 
                                //daca nu s-au terminat liniile
                                	strcat( d[j], " ");
                                }
                                strcat(d[j], s[i]);

                                //printf( "%d %s\n", j, d[j]);
                                i++; //trecem la linia urmatoare
                            }
                           	// printf( "%s %d\n", d[j], j );
                            if( i >= nrlins){
                                break;
                            } 
							
							if(strlen(s[i]) > 0){
                                elim_spfin(d[j]);
                                elim_spini(s[i]);
                                if(strlen( d[j]) > 0){
                                    strcat(d[j], " ");
                                }

                                dif = maxlung - strlen(d[j]);
                                while(dif >= 0 && s[i][dif] != ' '){
                                    dif--;
                                    //cate caractere se gasesc pana la spatiu
                                }
                                if( dif > 0 ){
									k = strlen(d[j]);
                                    strncat(d[j], s[i], dif);
                                    d[j][k+dif] = 0;
                                    //printf( "%s\n", s[i] );
                                    strcpy(aux, s[i]+ dif);
                                    strcpy(s[i], aux);
                                   // printf( "%s\n", s[i] ); 
                                }
                                else{
                                    d[j][strlen(d[j])-1] = 0;
                                /*sterge spatiul adaugat in cazul in care
                                 mai este ceva de concatenat */
                                }
                            }
                            else{
								i++;
                                j++;
                                strcpy( d[j], "");
                            }

                            j++;

                        } while(i < nrlins);
                        nrlind = j+1;
                       
            break;        

            case 'w': 
                    
                        maxlung = atoi( commc);
                        j=0; //linia curenta din textul destinatie
                        i=0; //linia curenta din textul sursa
                        do{
                            strcpy(d[j], "");
                            while( i < nrlins && strlen(s[i])>0 && 
                             strlen(d[j])+ strlen(s[i]) <= maxlung){
                                elim_spini(s[i]);
                                elim_spfin(d[j]);
                                if( strlen(d[j]) >0){
                                    strcat( d[j], " ");
                                }
                                strcat(d[j], s[i]);

                               // printf( "%d %s\n", j, d[j]);
                                i++;
                            }
                           // printf( "%s %d\n", d[j], j );
                            if( i >=nrlins){
                                break;
                            }


                            if( strlen(s[i]) > 0){
                                elim_spfin(d[j]);
                                elim_spini(s[i]);
                                if ( strlen( d[j]) >0)
                                    strcat(d[j], " ");
                                dif = maxlung - strlen(d[j]);
                               // printf( "%s & %s %d %d\n", d[j], s[i], dif, strlen(d[j]));
                                while(  dif>=0 && s[i][dif] != ' '){
                                    dif--;
                                }
                                if( dif > 0 ){

                                    k = strlen(d[j]);
                                    strncat( d[j], s[i], dif);
                                    d[j][k+dif] = 0;
                                    //printf( "%s\n", s[i] );
                                    strcpy(aux,s[i]+ dif);
                                    strcpy( s[i], aux);
                                   // printf( "%s\n", s[i] ); 
                                }
                                else{
                                    d[j][strlen(d[j])-1] = 0;//am sters spatiul adaugat crezand ca mai este ceva de concatenat

                                }
                            }
                            else{

                                i++;
                                j++;
                                strcpy( d[j], "");
                            }

                            j++;

                        } while( i<nrlins);
                        nrlind = j+1;
                       
            break;
                         
            case 'L': 
	                parsare(commc, &nr1, &nr2);
	                if(nr1 == -1){
	                    nr1=0;
	                }
	                if(nr2 == -1){
	                    nr2 = nrlind-1;
	                }

	                for(i=0; i < nrlind; i++){
	                    if(i >= nr1 && i <= nr2){
	                        elim_spini(d[i]);
	                    }
	                    elim_spfin(d[i]);
	                }

          	break;

            case 'l': 
	                parsare(commc, &nr1, &nr2);
	                if(nr1 == -1){
	                    nr1=0;
	                }
	                if(nr2 == -1){
	                    nr2 = nrlind-1;
	                }

	                for (i=0;i < nrlind; i++){
	                    if( i>=nr1 && i<=nrlind-1){
	                        elim_spini(d[i]);
	                    }
	                    elim_spfin(d[i]);
	                }    		
	                
            break; 
                
            case 'R':
	                parsare(commc, &nr1, &nr2);
	                if( nr1 == -1){
	                    nr1 = 0;
	                }
	                if( nr2 == -1 ){
	                    nr2 = nrlind-1;
	                }

	                maxlung = lung_max(d, nrlind);
	                //ca referinta linia cea mai lunga
	                
	                for(i = nr1; i <= nr2; i++){
	                	elim_spini(d[i]);
	                    elim_spfin(d[i]);
	                    if(strlen(d[i]) != 0){
	                        nr = maxlung - strlen(d[i]);
	                        //cate spatii sa aduge
	                    	for(j = 0; j < nr; j++){
	                        	spatiu[j]=' ';
	                        }
	                    
    	                    spatiu[nr] = 0;
    	                    strcat(spatiu, d[i]);
    	                    strcpy(d[i], spatiu);
                        }
	                }

            break;    
           
            case 'r':
		           parsare(commc, &nr1, &nr2);
			                if( nr1 == -1){
			                    nr1 = 0;
			                }
			                if( nr2 == -1 ){
			                    nr2 = nrlind-1;
			                }

			                maxlung = lung_max(d, nrlind);
			                //ca referinta linia cea mai lunga
			                
			                for(i = nr1; i <= nr2; i++){
			                	elim_spini(d[i]);
			                    elim_spfin(d[i]);
			                    if(strlen(d[i]) != 0){
			                        nr = maxlung - strlen( d[i]);
			                        //cate spatii sa aduge
			                    	for(j = 0; j < nr; j++){
			                        	spatiu[j]=' ';
			                        }
			                    
    			                    spatiu[nr] = 0;
    			                    strcat(spatiu, d[i]);
    			                    strcpy(d[i], spatiu);
			                    }
                            }    

		    break;            

            case 'C':
					parsare(commc, &nr1, &nr2);
	                if(nr1 == -1){
	                    nr1 = 0;
	                }
	                if(nr2 == -1){
	                    nr2 = nrlind-1;
	                }

	                maxlung = lung_max( d, nrlind);

	                for( i=nr1 ; i<=nr2; i++){   
	                    if(strlen(d[i]) !=0 ){
	                        dif = maxlung - strlen(d[i]);
	                        nrcentru = (dif+1)/2;
	                        
		                    for ( j=0; j < nrcentru; j++){
		                        spatiu[j]= ' ';
		                    }

		                    spatiu[nrcentru]=0;
		                    strcat(spatiu, d[i]);
		                    strcpy( d[i], spatiu);
		                }
	                }

	        break; 

            case 'c':
            		parsare(commc, &nr1, &nr2);
	                if(nr1 == -1){
	                    nr1 = 0;
	                }
	                if(nr2 == -1){
	                    nr2 = nrlind-1;
	                }

	                maxlung = lung_max( d, nrlind);

	                for( i=nr1 ; i<=nr2; i++){   
	                    if(strlen(d[i]) !=0 ){
	                        dif = maxlung - strlen(d[i]);
	                        nrcentru = (dif+1)/2;
	                        
		                    for ( j=0; j < nrcentru; j++){
		                        spatiu[j]= ' ';
		                    }

		                    spatiu[nrcentru]=0;
		                    strcat(spatiu, d[i]);
		                    strcpy( d[i], spatiu);
		                }
	                }

	        break; 
			
			case 'P':
	                adr = strchr( commc, ' ');
	                if (adr != 0){
	                    nr= adr - commc + 1; 
	                    //numarul de caractere reprezentand indent length
	                }
	                else{
	                    nr = strlen(commc);
	                }
					
					strncpy( spatiu, commc, nr); 
	                spatiu[nr] = 0;
	                strcpy(aux, commc+nr);
	                strcpy(commc, aux);
	                nr = atoi(spatiu); //indent length
	                for(i=0; i < nr; i++){
	                    spatiu[i]=' ';
	                }
	                spatiu[nr] = 0;

					parsare(commc, &nr1, &nr2);
	                if(nr1 == -1){
	                    nr1 = 0;
	                }
	                if(nr2 == -1){
	                    nr2 = nrlind-1;
	                    //nu pot fi mai multe paragrafe decat linii
	                }
	                
	                int prima=1; //semnalizator
	                for(i = 0; i <= nrlind; i++){
	                    if( strlen(d[i]) == 0){
	                        prima = 1;
	                    }
	                    else if(i >= nr1 && i <= nr2 && prima ==1){
	                            strcpy( spatiu2, spatiu);

	                            strcat( spatiu2, d[i]);
	                            strcpy( d[i], spatiu2);
	                            prima=0;
	                    }
	                }

            break;

            case 'I':
	                tip = commc[0]; //list_type 
                    car = commc[2]; //special_character
                    strcpy(aux, commc + 3);
                    strcpy(commc, aux);
                    parsare(commc, &nr1, &nr2);
                    if( nr1 == -1){
                        nr1 = 0;
                    }
                    if(nr2 == -1){
                        nr2 = nrlind-1; 
                    }

                    j=1; //numarator
                    for(i = nr1; i<=nr2; i++){
                        if(tip == 'n'){
                            sprintf(spatiu, "%d", j );
                            //in locul functiei itoa()
                             
                            k = strlen(spatiu);
                            spatiu[k] = car;
                            spatiu[k+1] = ' ';
                            spatiu[k+2] = 0;
                        }
                        else if(tip == 'b'){
                            spatiu[0] = car;
                            spatiu[1] = ' ';
                            spatiu[2]= 0;
                        } 
                        else{
                            spatiu[0] = tip+j-1;
                            spatiu[1] = car;
                            spatiu[2] = ' ';
                            spatiu[3] = 0;
                        }

                        strcat(spatiu,d[i]);
                        strcpy(d[i], spatiu);
                        j++; //daca este cazul numaratorul creste cu o unitate 
                    }
            break;
            case 'O':
            		tip = commc[0]; //list_type 
	                car = commc[2]; //special_character
                    tipord = commc[4]; //ordering
	                strcpy(aux, commc + 5);
	                strcpy(commc, aux);
	                parsare(commc, &nr1, &nr2);
	                if( nr1 == -1){
	                    nr1 = 0;
	                }
	                if(nr2 == -1){
	                    nr2 = nrlind-1; 
	                }
                 
                
	                if ( tipord == 'a'){
	                     ordonare_crescatoare(d, nr1, nr2);
	                }
	                else{
	                    ordonare_descrescatoare(d, nr1, nr2);
	                }

	                j=1; //numarator
	                for(i = nr1; i<=nr2; i++){
	                    if(tip == 'n'){
	                        sprintf(spatiu, "%d", j );
	                        //in locul functiei itoa()
	                         
	                        k = strlen(spatiu);
							spatiu[k] = car;
	                        spatiu[k+1] = ' ';
	                        spatiu[k+2] = 0;
	                    }
	                    else if(tip == 'b'){
	                        spatiu[0] = car;
	                        spatiu[1] = ' ';
	                        spatiu[2]= 0;
						} 
	                    else{
	                        spatiu[0] = tip+j-1;
	                        spatiu[1] = car;
	                        spatiu[2] = ' ';
	                        spatiu[3] = 0;
	                    }

	                    strcat(spatiu,d[i]);
						strcpy(d[i], spatiu);
	                    j++; //daca este cazul numaratorul creste cu o unitate 
					}
            break;

        }

		commc = strtok(NULL, ",");
    }
    
    for(i=0; i<nrlind; i++){
        fputs(d[i],out);
        fprintf(out,"\n");
    }

    fclose(out); 
    return 0;
}

