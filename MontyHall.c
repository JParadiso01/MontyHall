#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int no_change_result = 0;
int change_result = 0;
#define TRIALS 10000
#define RUNS 1000

int change_results[RUNS] = {0};
int no_change_results[RUNS] = {0};

void no_change(){
    int car = rand()%3;
    int choice = rand()%3;
    if (car == choice){
        no_change_result++;
    }
}


void change(){
    int car = rand()%3;
    int choice = rand()%3;
    int bad = (car+1)%3;

    if (choice == bad) bad++;

    choice = (choice+1)%3;
    if (choice == bad) choice = (choice+1)%3;


    if (car == choice){
        change_result++;
    }
}

void print_results(int run){
    printf("------------------------------\n");
    printf("run: %d\n", run);
    printf("No Change Results: %d out of %d trials won.\n", no_change_result, TRIALS);
    printf("Change Results: %d out of %d trials won.\n", change_result, TRIALS);
}

void reset(){
    no_change_result = 0;
    change_result = 0;
}

void print_end_results(){
    for (int i = 0; i < RUNS; i++){
        no_change_result += no_change_results[i];
        change_result += change_results[i];
    }
    printf("------------------------------\n");
    printf("Final No Change Results: %d out of %d trials won. %%%lf \n", no_change_result, TRIALS*RUNS, ((double)(no_change_result/(double)(TRIALS*RUNS))*100));
    printf("Final Change Results:    %d out of %d trials won. %%%lf \n", change_result, TRIALS*RUNS, ((double)(change_result/(double)(TRIALS*RUNS))*100));

}

int main(){
    srand(time(NULL));

    for (int run = 0; run < RUNS; run++){
        for (int trial = 0; trial < TRIALS; trial++){
            no_change();
            change();
        }
        no_change_results[run] = no_change_result;
        change_results[run] = change_result;
        //print_results(run);
        reset();
    }
    print_end_results();
    
    return 0;
}
