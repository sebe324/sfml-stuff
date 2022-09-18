#include <SFML/System.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

//this program measures how much time is needed to
// sort an array by bubblesort and quicksort

//utility functions
    void randomize(int arr[],int n){
        for(int i = 0; i<n; i++){
        arr[i]=(std::rand() % 30000)+1;
        }
    }
    void swapInt(int *xp, int *yp){
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
    }
    void printArr(int arr[], int n){
        for(int i=0; i<n-1; i++) std::cout<<arr[i]<<std::endl;
        }
//sorts

    void bubbleSort(int arr[], int n){
        for(int i = 0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swapInt(&arr[j],&arr[j+1]);
            }
        }
    }
    }


         int partitionInt(int arr[], int low, int high){
        int pivot=arr[high];
        int i = (low-1);
        for(int j = low; j<=high-1; j++){
            if(arr[j]<pivot){
                i++;
                swapInt(&arr[i], &arr[j]);
            }
        }
        swapInt(&arr[i+1], &arr[high]);
        return i+1;
    }

    void quickSort(int arr[], int low, int high){
        if(low<high){
            int index=partitionInt(arr, low, high);
            quickSort(arr, low, index-1);
            quickSort(arr,index+1,high);
        }
    }


int main(){

   sf::Time t1 = sf::microseconds(20000);
   sf::Time t2 = sf::milliseconds(20);
   sf::Time t3 = sf::seconds(0.02f);

   sf::Int64 usec = t2.asMicroseconds();
   sf::Int32 msec = t3.asMilliseconds();
   float sec = t1.asSeconds();

   sf::Time t4 = sf::milliseconds(t2.asMilliseconds()*2);
   sf::Time t5 = t1+t2;
   sf::Time t6 = -t3;

    bool b1 = (t1==t2);
    bool b2 = (t4 > t6);

    srand(time(NULL));

     int a[500];
    int asize=sizeof(a)/sizeof(int);
    randomize(a, asize);

    //start clock
    sf::Clock clock;
    bubbleSort(a,asize);
    sf::Time elapsedBubbleSort = clock.getElapsedTime();

    std::cout<<"bubble sort time : "<<elapsedBubbleSort.asMicroseconds()<<std::endl;

    randomize(a,asize);
    clock.restart(); //restart clock
    quickSort(a,0,asize-1);
    sf::Time elapsed2 = clock.getElapsedTime();

    std::cout<<"quick sort time : "<<elapsed2.asMicroseconds()<<std::endl;
return 0;
}
