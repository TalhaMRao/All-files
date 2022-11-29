## Introduction ###########################################################################
Name : Talha Rao
ID: 1088904
Assignment 4

This program takes in an "f.dat" file with that specific name that has 20x10 numbers in it. It then saves each line in a struct array with a size of 20.
This struct is utilized as a heap and the data is sorted with a downHeap algorithm.

There is no input required from the user other than a .dat file.
The output of the program is the correctly sorted struct heap.

## Sample input ###########################################################################
1) make
2) ./a4

## Sample output ##########################################################################

26 28 10 23 3 32 65 61 28 95 
25 0 54 25 19 25 81 21 2 78 
30 73 12 75 14 85 72 60 91 42 
10 56 17 24 47 2 35 45 19 51 
19 9 89 77 80 75 91 34 61 24 
83 46 3 67 90 48 4 74 41 52 
77 7 34 93 4 19 10 44 76 19 
31 44 21 79 68 97 32 13 62 80 
68 37 41 12 6 85 51 85 60 56 
99 30 0 91 26 9 91 70 21 14 
77 51 28 24 77 2 36 64 32 5 
66 63 94 42 77 64 56 80 63 14 
36 42 65 18 81 93 72 34 59 37 
62 30 46 71 41 38 80 60 99 5 
19 48 83 98 11 30 41 72 9 31 
86 18 40 47 13 94 98 22 79 94 
61 69 82 25 62 12 83 35 56 19 
62 74 67 19 41 35 38 16 9 80 
47 44 85 30 84 53 28 42 7 65 
3 98 29 5 60 15 98 86 4 61 

## What it should look like when you run it ###############################################

PS C:\Users\talha\Desktop\All-files\C\VS Code\CIS2520\A4> make
cc     a4.c   -o a4
PS C:\Users\talha\Desktop\All-files\C\VS Code\CIS2520\A4> .\a4  

26 28 10 23 3 32 65 61 28 95
25 0 54 25 19 25 81 21 2 78
30 73 12 75 14 85 72 60 91 42
10 56 17 24 47 2 35 45 19 51
19 9 89 77 80 75 91 34 61 24
83 46 3 67 90 48 4 74 41 52
77 7 34 93 4 19 10 44 76 19
31 44 21 79 68 97 32 13 62 80
68 37 41 12 6 85 51 85 60 56
99 30 0 91 26 9 91 70 21 14
77 51 28 24 77 2 36 64 32 5
66 63 94 42 77 64 56 80 63 14
36 42 65 18 81 93 72 34 59 37
62 30 46 71 41 38 80 60 99 5
19 48 83 98 11 30 41 72 9 31
86 18 40 47 13 94 98 22 79 94
61 69 82 25 62 12 83 35 56 19
62 74 67 19 41 35 38 16 9 80
47 44 85 30 84 53 28 42 7 65
3 98 29 5 60 15 98 86 4 61

PS C:\Users\talha\Desktop\All-files\C\VS Code\CIS2520\A4>