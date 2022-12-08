#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define  N 100
void Insertion_sort(int *array);
void Visualizza(int *array);
void mergesort(int *array, int left, int right);
void merge(int *array, int p, int q, int r);
int main(){
 
    int array[N];
    int i,volte,j;
    int copiarray[N];
    clock_t a,c;
    float risultato,tempomedio,risTempMed,risTempMed1,risultato1,tempomedio1;
   srand((unsigned)time(NULL)); 

   printf("numero ripetizioni del ciclo");
   scanf("%d",&volte);
   for(j=0; j<volte; j++)
   {
	
    for(i=0; i<N; i++)
    {
        array[i]=rand()%N;
    }

	printf("array disordinato\n");
	Visualizza(array);// stampa vettore non ordinato
	printf("\n");
	
	//assegno ad a la funzione clock che ha il compito di contare i secondi all inizio dell era di cicli
	a=clock();
	
	for(i=0; i<N; i++)
	{
	copiarray[i]=array[i];
	}
	
	// ad a tolgo il tempo prima dell insertion sort
	a=clock()-a;

	printf("array ordinato insertion sort\n");
	Insertion_sort(array);
	Visualizza(array);// stampo vettore ordinato
	printf("\n");
	c=clock();
	

        printf("array ordinato mergesort\n");
	mergesort(copiarray,0,N-1);
	Visualizza (copiarray);
	
	printf("\n");
	//divido il tempo fratto clock per secondi in modo che mi restituisca il numero dei secondi 
	risultato= a/CLOCKS_PER_SEC;
	printf("il tempo totale espresso in secondi dell'insertion è : %f\n",risultato); 
	
	// devo calcolare il tempo medio 
	tempomedio=tempomedio+a;

	//calcolo il tempo per il mergesort 

	// a c tolgo il tempo prima del mergesort
	c=clock()-c;

	printf("\n");

	//divido il tempo fratto clock per secondi in modo che mi restituisca il numero dei secondi 
	risultato1= c/CLOCKS_PER_SEC;
	printf("il tempo totale espresso in secondi del mergesort è : %f\n",risultato1); 
	
	// devo calcolare il tempo medio 
	tempomedio1=tempomedio1+c;
      
	

   }
	
	//tempo medio da trasformare in secondi
	printf("\n");
	risTempMed=tempomedio/volte/CLOCKS_PER_SEC;
	printf("il tempo medio in secondi per l'insertion è : %f\n",risTempMed);



	//tempo medio da trasformare in secondi
	printf("\n");
	risTempMed1=tempomedio1/volte/CLOCKS_PER_SEC;
	printf("il tempo medio in secondi per il mergesort è : %f\n",risTempMed1);

	
		
	return 0;
}

	 void Insertion_sort(int *array) 
		
{
       
	int temp,i,j;

	 for (i = 0; i < N; i++)
	{
            for ( j = i+1; j<N; j++)
		{
                	if (array[i] > array[j]) 
			{
                    		temp = array[i];
                    		array[i] = array[j];
                    		array[j] = temp;
                
    			}
		}

	}

}

void Visualizza(int *array)
{
    int i;
    for(i=0; i<N; i++)
    {
	
        printf("%d ",array[i]);
	
        
    }
}

void mergesort(int *array, int left, int right)
{

	// indice dell' elemento in pozione centrale 

	int center;
	
	//controllare che ci siano almeno due elementi nel vettore 

	if(left<right)

	{

		center=(left+right)/2;// divido il vettore 

		mergesort( array, left, center); // chiamo la funzione merge per la prima parte 
	
		mergesort (array, center+1, right); // chiamo la funzione di ordinamento per la seconda parte 

		merge (array, left, center, right); // chiamo la funzione per l'unione della seconda parte da ordinare 
		

	}
}

void merge (int *array, int p , int q, int r )
{

int n1=q-p+1;//
int n2=r-q;// 
 
	int left[n1],right[n2], i=0, j=0, k=0;

	//copio la parte sinistra in left 

	for(i=0; i<n1; i++)
	{
		left[i]=array[i+p];
	}
	
	left[n1]= 2147483647; //massimo numero rappresentabile 

	// copio la parte destra in right 

	for (j=0 ; j< n2; j++)
	{
		right[j]=array[j+q+1];
	}


	right[n2]=2147483647;

	// unisco i due vettori

	i=0;
	j=0;

	for (k=p; k<=r; k++)
	{
			if(left[i]<= right[j])
			{
			array[k]=left[i];
			i++;
			}
			else 
			{
				array[k]=right[j];
				j++;
			}

	}

}





	







