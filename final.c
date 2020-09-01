#include <stdio.h>
#include<string.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void Longswap(long int *xp, long int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
int partition (long int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);  
    for (int j = low; j <= high- 1; j++) 
    { 
    
        if (arr[j] <= pivot) 
        { 
            i++;    
            Longswap(&arr[i], &arr[j]); 
        } 
    } 
    Longswap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void quickSort(long int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void printLongArray(long int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%ld ", arr[i]); 
    printf("n"); 
} 
int main()
{int n;
    printf("select your option\n 1.sort train numbers\n2.sort train names\n3.sort passenger names\n4.sort PNR numbers\n5.exit\n");
    int ch;
    do{
       scanf("%d",&ch);
       if(ch==1)
           
          { printf("enter number of trains\n");
           scanf("%d",&n);
           printf("enter train numbers\n");
           int a[n];
           for(int i=0;i<n;i++)
           scanf("%d",&a[i]);
            bubbleSort(a, n); 
            printf("Sorted train numbers: \n"); 
            printArray(a, n); }
      if(ch==2)
     
       { char name[100][100], tname[100][100], temp[100];
        int i, j, n;
        printf("Enter number of train names\n");
        scanf("%d", &n);
        printf("Enter %d names \n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%s", name[i]);
            strcpy(tname[i], name[i]);
        }
        for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(name[i], name[j]) > 0)
                {
                    strcpy(temp, name[i]);
                    strcpy(name[i], name[j]);
                    strcpy(name[j], temp);
                }
            }
        }
        printf("\n----------------------------------------\n");
        printf("Input NamestSorted names\n");
        printf("------------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("%s\t\t%s\n", tname[i], name[i]);
        }
        printf("------------------------------------------\n");
       } 
       if(ch==3)
       {
           char name[100][100], tname[100][100];
        int i, j, n;
        printf("Enter number of passengers \n");
        scanf("%d", &n);
        printf("Enter %d names \n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%s", name[i]);
            
        }
        for (i = 1; i < n  ; i++)
        {
            j=i-1;
            strcpy(tname[i], name[i]);
            
                while (j>=0&&name[j]>tname[i])
            {
                strcpy(name[j+1], name[j]);
             j=j-1;            
            }
            strcpy(name[j+1],tname[i]);
 
        }
        printf("\n----------------------------------------\n");
        printf("Input NamestSorted names\n");
        printf("------------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("%s\t\t%s\n", tname[i], name[i]);
        }
        printf("------------------------------------------\n");
    }
    if(ch==4)
    {
        int num;
        printf("enter number of PNR numbers to be sorted\n");
        scanf("%d",&num);
        long int a[n];
        printf("enter PNR numbers\n");
        for(int i=0;i<num;i++)
        scanf("%ld",&a[i]);
        quickSort(a, 0, num-1); 
        printf("Sorted PNR numbers: \n"); 
        printLongArray(a, num); 
    }
       
    
}while(ch<=5);
return 0;}
