#include <stdio.h>

char RoC (char m, char c, char message); // function defintion for rotation cipher



int main()
{
    
    FILE *input;
    FILE *output;
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    char c; //a single letter of the message to be read
    while(fscanf(input, "%c", &c) == 1){
            
        char RoC (char c) {
    
        int k = 0; //the current cipher key
        for(int k = 0; k <= 26; k++) {
         c = (c - k % 26);
         //printf("%c", &c);
        
    } 
    
    
    return k;

    }
        fprintf(output, "%c", c);
          
    }

   // printf("\n");
    

}