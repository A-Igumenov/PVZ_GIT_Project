#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <algorithm>
//sdfsdfsd sdfdsf sdf sdfsdfsdf sdf sdf sdf sdf sdfsdfsdfsdfsdf f ssdf sd fsdf  sdfsdf sfs sdfsd fsdf sdf s

using namespace std;
# define N 100000 // declaration of constant N with value 25000

int main() {
    //------------------------------Creating of pointer to file with writing in it---------------------------------------------//
    FILE* F;
    F = fopen("rez.txt", "w");	// file opening for write info in it
    //-------------------------------------------------------------------------------------------------------------------------//
    //------------------------------declaration of array from N elements, N in this example is 25000---------------------------//
    int mas[N];
    //-------------------------------------------------------------------------------------------------------------------------//
    //-------------declaration of 4 int type temp_of_pointers and two pointers to int type temp_of_pointers--------------------//
    int  temp_of_pointer, temp, * pointer, * pointer_to_temp; int i, j;
    //-------------------------------------------------------------------------------------------------------------------------//
    pointer_to_temp = &temp_of_pointer;				// save in to pointer reference with address of variable temp_of_pointer
    pointer = mas;									// save in to pointer address of 0 arrays mas element (mas[0]),
                                                    //alternative: pointer=&mas[0];
    double elapsed;                                 //time counter value
    clock_t start, stop;                            //Values to get time and store it
    time_t t;
    //----------------------------------generation of array by user algorithm--------------------------------------------------//
    puts("Begin of array filling by values.");
    for (i = 0; i < N; i++)
        if (i % 2 == 0) mas[i] = i - 1000;
        else mas[i] = i + 1000;

    //----------------------------------generation of array with random number generation algorithm----------------------------//
    /*Initialization of random number generator, to generate all time different numbers, if You don't write this function You
    get on all execution time same values */
    /*
    srand((unsigned) time(&t));
    for (i=0; i<N; i++)                             //generates and fill N random numbers with values from range -5000 to 4999
        mas[i]=-5000 + rand() % 10000;
    */
    //-------------------------------------------------------------------------------------------------------------------------//
    //----------------------------------Bubble sort algorithm with simple arrays methods---------------------------------------//
    puts("Wait little longer program begins sorting operation (can request more time).");
    start = clock();                                //getting system clock value on beginning
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++)
            if (mas[i] > mas[j]) 						// if mas[i] > mas[j], algorithm change values of this elements
            {
                temp = mas[i];					//temporally save value of mas[i] element
                mas[i] = mas[j];					//rewrite value of mas[i] with value of mas[j] element
                mas[j] = temp;					//rewrite value of mas[j] with temporally value
            }
    stop = clock();                                 //getting system clock value on end
    //Time calculation
    elapsed = (double)(stop - start) / CLOCKS_PER_SEC;   //elapsed time calculation
    printf("\nTime elapsed with arrays functions in sec: %f\n\n\n", elapsed);


    //----------------------------Output arrays elements to file when it's using pointer syntax--------------------------------//
    pointer = mas;
    while (pointer <= &mas[N - 1])
    {
        fprintf(F, "%.2d\n", *pointer++);
    }
    //-------------------------------------------------------------------------------------------------------------------------//
    //----------------------------------Closing of file after end of writing operation in it----------------------------------//
    fclose(F);
    //-------------------------------------------------------------------------------------------------------------------------//
    system("pause");

    //-------------------------------------------------------------------------------------------------------------------------//
    //----------------------------------Bubble sort algorithm with pointers syntax---------------------------------------------//
    puts("Begin of array filling by values.");
    for (i = 0; i < N; i++)                             //to compare data sort by time, we must to work with same data
        if (i % 2 == 0) *(mas + i) = i - 1000;                  //repeat of array fill
        else *(mas + i) = i + 1000;
    //-----
    pointer = mas;
    puts("Wait little longer program begins sorting operation (can request more time).");
    start = clock();                                //getting system clock value on beginning
    for (i = 0; i < N -  1; i++)							// block of code then done bubble sort algorithm
        for (j = i + 1; j < N; j++)
            if (*(pointer + i) > *(pointer + j))			//if mas[i] > mas[j], algorithm change values of this elements
            {
                *pointer_to_temp = *(pointer + i);	//temporally save value of memory cell from address of pointer+i
                                                //element to pointer_to_temp
                *(pointer + i) = *(pointer + j);		//rewrite value of memory cell from address of pointer+i on value of
                                                //memory cell from address of pointer+j
                *(pointer + j) = *pointer_to_temp;	//rewrite value of memory cell from address of pointer+i on value of
                                                //memory cell from address of pointer_to_temp
            }
    stop = clock();                                 //getting system clock value on end
    //Time calculation
    elapsed = (double)(stop - start) / CLOCKS_PER_SEC;  //elapsed time calculation
    printf("\nTime elapsed with pointer functions in sec: %f\n\n\n", elapsed);
    //----------------------------Output arrays elements to file when it's using pointer syntax--------------------------------//
    pointer = mas;
    F = fopen("rez.txt", "w");
    while (pointer <= &mas[N - 1])
    {
        fprintf(F, "%.2d\n", *pointer++);
    }
    //-------------------------------------------------------------------------------------------------------------------------//
    //----------------------------------Closing of file after end of writing operation in it----------------------------------//
    fclose(F);
    //-------------------------------------------------------------------------------------------------------------------------//
    system("pause");

    //-------------------------------------------------------------------------------------------------------------------------//
    //-------------------------------------------sort algorithm with assembler-------------------------------------------------//
    puts("Begin of array filling by values.");
    for (i = 0; i < N; i++)                             //to compare data sort by time, we must to work with same data
        if (i % 2 == 0) mas[i] = i - 1000;                  //repeat of array fill
        else mas[i] = i + 1000;
    //-----
    puts("Wait little longer program begins sorting operation (can request more time).");
    start = clock();                                //getting system clock value on beginning
    //int &a = mas[0], &b = mas[1];
    pointer = mas; 
    int indexi, indexj;
    for (int i = 0; i < N -  1; i++)							// block of code then done bubble sort algorithm
      for (int j = i + 1; j < N; j++)
            if (mas[i] > mas[j])			//if mas[i] > mas[j], algorithm change values of this elements
            {
                //printf("%d %d ;", mas[i], mas[j]);//system("pause");
             /*   __asm
                    {
                    mov ecx, i                          ; save index i in ecx
                    mov edx, j                          ; save index j in edx
                    xchg eax, mas[TYPE mas * ecx]       ; exchabge mas[i] value with eax, eax = mas[i] value, mas[i] get 0
                    xchg eax, mas[TYPE mas * edx]       ; exchabge mas[j] value with eax, eax = mas[j], mas[j] get old mas[i] value from eax
                    xchg eax, mas[TYPE mas * ecx]       ; exchabge mas[i] value with eax, eax = 0, mas[i] get eax value equal to old mas[j]
                    }  
                    */           
                __asm
                    {
                        mov ecx , i                      ; save index i in ecx
                        mov edx , j                      ; save index j in edx
                        mov eax , mas[TYPE mas * ecx]    ; copy mas[i] value to eax
                        mov ebx , mas[TYPE mas * edx]    ; copy mas[j] value to ebx
                        mov mas[TYPE mas * edx] , eax    ; copy eax value to mas[j]
                        mov mas[TYPE mas * ecx] , ebx    ; copy ebx value to mas[i]                      
                    }
                //printf("%d %d \n",mas[i], mas[j]);system("pause");
            }
    stop = clock();                                 //getting system clock value on end
    //Time calculation
    elapsed = (double)(stop - start) / CLOCKS_PER_SEC;  //elapsed time calculation
    printf("\nTime elapsed with assembler in sec: %f\n\n\n", elapsed);
    //----------------------------Output arrays elements to file when it's using pointer syntax--------------------------------//
    pointer = mas;
    F = fopen("rez.txt", "w");
    while (pointer <= &mas[N - 1])
    {
        fprintf(F, "%.2d\n", *pointer++);
    }
    //-------------------------------------------------------------------------------------------------------------------------//
    //----------------------------------Closing of file after end of writing operation in it----------------------------------//
    fclose(F);
    //-------------------------------------------------------------------------------------------------------------------------//
    system("pause");

    //-------------------------------------------------------------------------------------------------------------------------//
    //-----------------------------sort algorithm with pointers and SORT algorithm library-------------------------------------//
    puts("Begin of array filling by values.");
    for (i = 0; i < N; i++)                             //to compare data sort by time, we must to work with same data
        if (i % 2 == 0) mas[i] = i - 1000;                  //repeat of array fill
        else mas[i] = i + 1000;
    //-----
    puts("Wait little longer program begins sorting operation (can request more time).");
    start = clock();                                //getting system clock value on beginning
    sort(mas, mas + N);
    stop = clock();                                 //getting system clock value on end
    //Time calculation
    elapsed = (double)(stop - start) / CLOCKS_PER_SEC;  //elapsed time calculation
    printf("\nTime elapsed with algorithms library in sec: %f\n\n\n", elapsed);


    //----------------------------Output arrays elements to file when it's using pointer syntax--------------------------------//
    pointer = mas;
    F = fopen("rez.txt", "w");
    while (pointer <= &mas[N - 1])
    {
        fprintf(F, "%.2d\n", *pointer++);
    }
    //-------------------------------------------------------------------------------------------------------------------------//
    //----------------------------------Closing of file after end of writing operation in it----------------------------------//
    fclose(F);
    //-------------------------------------------------------------------------------------------------------------------------//
    system("pause");
    return 0;
}
