#include <stdio.h> 
#include <stdlib.h>
char RoCE (char *message, int k, int length); //function defintion for rotation cipher encryption
char RoCD (char *message, int k, int length); //function defintion for rotation cihper decryption


int main()
{
    
    //FILE *input;
    //FILE *output;
    
   // input = fopen("input.txt", "r");
   // output = fopen("output.txt", "w");
    
    char message[] = "HELLO THERE"; //hardcoded message
    int k = 0; //the current cipher key from 1 to 25
    int l = sizeof(message)/sizeof(message[0]); //sets the size of the array into l
    int option; //
    //while(fscanf(input, "%c", &c) == 1){
        
    //printf("Enter a message to encrypt: ");

    //scanf("%s", message);
            
do {
    printf("Select one: Rotation Encrypt(1), Rotation Decrypt(2), Exit(0)");
    scanf("%d", &option); 
    switch (option) {
    
        case 1: RoCE(message, k, l);
            break;   
        
        case 2: for(k = 0; k < 26; k++) {
            RoCD(message, k, l);
           
            
            }    
   }
   //message[i] = ch;
   //fprintf(output, "%c", c);
        
    return 0;
    
    } 
        while (option != 0);

    }
    
    
    //printf("\n");
char RoCE (char *message, int k, int length) {
             
        int i; //the current postion of a indiviual character being read
        char ch; //single character of the message to be read
        char result[length]; 
        
        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];
            if (message[i] >= 65 && message[i] <= 90) { //checks for non-alphabet characters like the space character
                ch = (ch + k - 65) % 26 + 65; 
            }
        result[i] = ch;
        }
        result[length] = '\0';
            
        printf("Encrypted message: %s", result);

   return 0; 
}

char RoCD (char *message, int k, int length) {
    
    int i; //the current postion of a indiviual character being read
    char ch; //single character of the message to be read
    char result[length];
    int e_count = 0;
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if (message[i] >= 65 && message[i] <= 90) { //checks for non-alphabet characters like the space character
            ch = (ch - k - 65 + 26) % 26 + 65;
        }
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            e_count++;
        }
        result[i] = ch;
        }
        result[length] = '\0';
            
        printf("e's: %d, Decrypted message: %s", e_count, result);
    
    return 0;
}


