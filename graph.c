/*
   
   Copyright 2023 Andrea Simonetti

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
    
*/

//Libraries 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//Constants
#define PI 3.1415926

//Modes
#define AUTOSET 0
#define WINDOWED 1

//CUSTOM PARAMETERS
//The size of the plot
#define GRAPH_WIDTH 80
#define GRAPH_HEIGHT 25

//X bounds (obligatory)
#define START_X -5
#define END_X 5

//Y bounds (only in WINDOWED mode)
#define START_Y -0.2
#define END_Y 1.5

//The mode which the program will use
#define MODE WINDOWED

//Function to show
float f(float x){

    return exp(x) / (1 + exp(x));

}
//END OF CUSTOM PARAMETERS

//Struct which handles whether I can show a *
typedef struct Vals_s {
    int val;
    int valid;
} vals_s;

//Function to show
float f(float x);
//Map function to convert ranges
float map(float val, float min1, float max1, float min2, float max2);
//Length of a float with 2 digits
int lenFloat(float val);

//Main Program
int main(){

    //Variable
    //Graph matrix
    char graph[GRAPH_HEIGHT][GRAPH_WIDTH];
    //Vector of values
    vals_s vals[GRAPH_WIDTH];

    //Counters
    int c1;
    int c2;
    float c3;

    //Interval on the X axis
    float interval;

    //Minimum and maximum of a function
    //On AUTOSET they're processed
    //On WINDOWS they're defined as START_Y and END_Y
    float min;
    float max;

    //Mode variable, can be AUTOSET or WINDOWED
    int mode;

    //Assigning the mode
    mode = MODE;

    interval = END_X - START_X;

    //Handling the modes
    switch(mode){

        case AUTOSET:
            min = INT_MAX;
            max = INT_MIN;

            for(c3 = START_X; c3 < START_X + interval; c3 += interval / GRAPH_WIDTH){

                if(f(c3) > max) max = f(c3);
                if(f(c3) < min) min = f(c3);

            }
        break;

        case WINDOWED:

            min = START_Y;
            max = END_Y;

        break;

    }

    //Calculating values of the graph matrix (with offset, 0.5)
    for(c1 = 0; c1 < GRAPH_WIDTH; c1++){

        vals[c1].val = (int) round(map(f(START_X + ((c1 + 0.5) * (interval / GRAPH_WIDTH))), min, max, GRAPH_HEIGHT - 1, 0));        
        if(vals[c1].val > GRAPH_HEIGHT || vals[c1].val < 0) vals[c1].valid = 0;
        else vals[c1].valid = 1;

    }

    //Creating the graph matrix
    for(c1 = 0; c1 < GRAPH_HEIGHT; c1++){
        for(c2 = 0; c2 < GRAPH_WIDTH; c2++){
            graph[c1][c2] = ' ';
            if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0))) graph[c1][c2] = '-';
            if(c2 == (int) round(map(0, START_X, END_X, 0, GRAPH_WIDTH - 1))) graph[c1][c2] = '|';
        }
    }

    for(c1 = 0; c1 < GRAPH_WIDTH; c1++){
        if(vals[c1].valid == 1) graph[vals[c1].val][c1] = '*';
    }


    //Printing the X scale
    printf("%.2f", map(0, 0, 1, START_X, END_X));
    for(c1 = 1; c1 < 5; c1++){
       for(c2 = 0; c2 < (int) map(0.25, 0, 1, 0, GRAPH_WIDTH - 1) - lenFloat(map(c1 * 0.25, 0, 1, START_X, END_X)); c2++) printf(" ");
       printf("%.2f", map(c1 * 0.25, 0, 1, START_X, END_X));
    }
    printf("\n");

    //Printng the Y arrow
    for(c1 = 0; c1 < (int) round(map(0, START_X, END_X, 0, GRAPH_WIDTH - 1)) - 2; c1++) printf(" ");
    printf("y ^\n");

    //Printing the graph
    for(c1 = 0; c1 < GRAPH_HEIGHT; c1++){
        for(c2 = 0; c2 < GRAPH_WIDTH; c2++){
            printf("%c", graph[c1][c2]);
        }

        //Printing the X arrow
        if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0))) printf(">");
        if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0)) + 1) printf("x");

        //Printing the Y scale
        if(c1 == (int) round(map(map(0, 0, 1, min, max), min, max, GRAPH_HEIGHT - 1, 0))){
            if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0))) printf(" %.2f", map(0, 0, 1, min, max));
            else printf("  %.2f", map(0, 0, 1, min, max));
        }

        if(c1 == (int) round(map(map(0.25, 0, 1, min, max), min, max, GRAPH_HEIGHT - 1, 0))){
            if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0))) printf(" %.2f", map(0.25, 0, 1, min, max));
            else printf("  %.2f", map(0.25, 0, 1, min, max));
        }

        if(c1 == (int) round(map(map(0.5, 0, 1, min, max), min, max, GRAPH_HEIGHT - 1, 0))){
            if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0))) printf(" %.2f", map(0.5, 0, 1, min, max));
            else printf("  %.2f", map(0.5, 0, 1, min, max));
        }

        if(c1 == (int) round(map(map(0.75, 0, 1, min, max), min, max, GRAPH_HEIGHT - 1, 0))){
            if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0))) printf(" %.2f", map(0.75, 0, 1, min, max));
            else printf("  %.2f", map(0.75, 0, 1, min, max));
        }

        if(c1 == (int) round(map(map(1, 0, 1, min, max), min, max, GRAPH_HEIGHT - 1, 0))){
            if(c1 == (int) round(map(0, min, max, GRAPH_HEIGHT - 1, 0))) printf(" %.2f", map(1, 0, 1, min, max));
            else printf("  %.2f", map(1, 0, 1, min, max));
        }

        printf("\n");
    }


    return 0;
}

//Map function to convert ranges
float map(float val, float min1, float max1, float min2, float max2){

    float dif1;
    float dif2;
    float k;
    float point1;
    float point2;

    dif1 = max1 - min1;
    dif2 = max2 - min2;

    k = dif2 / dif1;

    point1 = val - min1;
    point2 = k * point1;

    return min2 + point2;

}

//Length of a float with 2 digits
int lenFloat(float val){

    int adding;
    int f;
    adding = val < 0 ? 2 : 1;

    f = abs(val * 100);

    if(val == 0) return 3;

    return adding + (int) (log(f) / log(10)) + 1;


}
