# graph

A simple C program which displays a function by hard coding it.



# How it works

There's no need to pass any arguments, because everything is hard-coded. In order to change the parameters, you have to edit the code.



## Set the custom parameters

In the very first few lines of code, you'll find a highlighted section called CUSTOM PARAMETERS.

```c
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
```

- **GRAPH_WIDTH** and **GRAPH_HEIGHT** will determine how wide will be the plot in the stdout in terms of pixels. By default, 80x25.

- **START_X** and **END_X** define the bounds of the function on the X axis.

- **START_Y** and **END_Y** define the bounds of the function on the Y axis. Note that they are useful in WINDOWED mode only.

- The **MODE** defines whether graph will run in **WINDOWED** mode or **AUTOSET** mode.
  
  - **WINDOWED** mode: graph will follow the Y axis bounds defined by the user.
  
  - **AUTOSET** mode: graph will automatically find the values covered in the Y axis by the function over the X axis interval defined by the user.
    
    It's suggested to use the **WINDOWED** mode when the Y axis bounds tend to infinity.

- The **f** function defines which is the function to plot. In this case, it's the logistic curve.
  
  

## Compile and execute

If you're confident to compiling C programs, it'll be very easy, since only the math library is requested by default.

In UNIX-like environment:

```shell
gcc graph.c -lm -o graph; ./graph
```

In Windows Powershell environment (make sure to have Visual Studio Build Tools, and LLVM installed):

```powershell
clang graph.c -o graph; .\graph
```





# A few examples of outputs

## The sine wave

```c
//The size of the plot
#define GRAPH_WIDTH 40
#define GRAPH_HEIGHT 20

//X bounds (obligatory)
#define START_X -PI
#define END_X PI

//The mode which the program will use
#define MODE AUTOSET

//Function to show
float f(float x){
    return sin(x);
}
```

```
-3.14    -1.57      0.00     1.57     3.14
                  y ^
                    |       ****          1.00
                    |     **    **
                    |    *        *
                    |   *          *
                    |
                    |  *            *     0.50
                    | *              *
                    |*                *
                    |
                    *                  *
*------------------*|-------------------> 0.00
                    |                   x
 *                * |
  *              *  |
   *            *   |                     -0.50
                    |
    *          *    |
     *        *     |
      **    **      |
        ****        |                     -1.00
```

## 

## The logistic curve

```c
//The size of the plot
#define GRAPH_WIDTH 40
#define GRAPH_HEIGHT 20

//X bounds (obligatory)
#define START_X -4
#define END_X 4

//Y bounds (only in WINDOWED mode)
#define START_Y -0.2
#define END_Y 1.5

//The mode which the program will use
#define MODE WINDOWED

//Function to show
float f(float x){
    return exp(x) / (1 + exp(x));
}
```

```
-4.00    -2.00      0.00     2.00     4.00
                  y ^
                    |                     1.50
                    |
                    |
                    |
                    |
                    |                     1.08
                    |           ********
                    |       ****
                    |    ***
                    |  **
                    |**                   0.65
                   **
                  * |
                **  |
             ***    |                     0.23
          ***       |
 *********          |
*-------------------|------------------->
                    |                   x
                    |                     -0.20
```



## The hyperbola

```c
//The size of the plot
#define GRAPH_WIDTH 40
#define GRAPH_HEIGHT 20

//X bounds (obligatory)
#define START_X -2
#define END_X 2

//Y bounds (only in WINDOWED mode)
#define START_Y -3
#define END_Y 3

//The mode which the program will use
#define MODE WINDOWED

//Function to show
float f(float x){
    return 1 / x;
}
```

```
-2.00    -1.00      0.00     1.00     2.00
                  y ^
                    |  *                  3.00
                    |
                    |   *
                    |
                    |    *
                    |     **              1.50
                    |       ***
                    |          *****
                    |               ****
                    |
--------------------|-------------------> 0.00
****                |                   x
    *****           |
         ***        |
            **      |                     -1.50
              *     |
                    |
               *    |
                    |
                *   |                     -3.00
```


