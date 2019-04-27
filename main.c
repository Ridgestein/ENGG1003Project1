#include <stdio.h> 
#include <stdlib.h>
char ROCE (char *message, int k, int length); //function defintion for rotation cipher encryption
char ROCD (char *message, int k, int length); //function defintion for rotation cihper decryption
char SUBCE (char *message, char *subK, int k, int length); //the function definiton for substitution cipher encryption
//char SUBCD


int main()
{
    
    //FILE *input;
    //FILE *output;
    
   // input = fopen("input.txt", "r");
   // output = fopen("output.txt", "w");
    
    char message[] = "HELLO THERE"; //hardcoded message to be translated 
    int k = 10; //the current cipher key from 1 to 25
    char subK[] = "PHQGIUMEAYLNOFDXJKRCVSTZWB"; //the key specifically for the substitution cipher  
    int l = sizeof(message)/sizeof(message[0]); //allows the changing size of the message array to be updated when the message is changed
    int option; //allows for the user interface to be interacted with 
    //while(fscanf(input, "%c", &c) == 1){
        
    //printf("Enter a message to encrypt: ");

    //scanf("%s", message);
            
do {
    printf("Select one: Rotation Encrypt(1), Rotation Decrypt(2), Exit(0)");
    scanf("%d", &option); 
    switch (option) { 
    
        case 1:
            ROCE(message, k, l);
            break;  
        
        case 2:
            for(k = 0; k < 26; k++) {
                ROCD(message, k, l); 
            }   
            break;
    }
   
   //fprintf(output, "%c", c);
        
   
    
    } while (option != 0);

return 0;
}
    
    
    //printf("\n");
char ROCE (char *message, int k, int length) {
             
        int i; //the current postion of a indiviual character being read
        char ch; //single character of the message to be read
        char result[length]; //variable for the final encrypted/decrypted message to be stored in
        
        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];
            if (message[i] >= 65 && message[i] <= 90) { //checks for non-alphabet characters e.g. the space character
                ch = (ch + k - 65) % 26 + 65; 
            }
        result[i] = ch;
        }
       // result[length] = '\0';
            
        printf("Encrypted message: %s\n", result);

   return 0; 
}

char ROCD (char *message, int k, int length) {
    
    int i; 
    char ch; 
    char result[length];
    int e_count = 0;
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if (message[i] >= 65 && message[i] <= 90) { 
            ch = (ch - k - 65 + 26) % 26 + 65;
        }
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') { //checks for vowels and adds them to a counter, making it easier to tell if a decrypted message is the right one
            e_count++;  
        }
        result[i] = ch;
    }
        //result[length] = '\0';
            
        printf("Vowels: %d, Decrypted message: %s\n\n", e_count, result);
    
    return 0;
    
}

char SUBCE (char *message, char *subK, int k, int length) {
    
    int i; 
    int x; //the current position of 
    char ch; 
    char result[length]; 
    //char subK[] = "PHQGIUMEAYLNOFDXJKRCVSTZWB";
    char nAlpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXZY";
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if (nAlpha[i] != ch) {
            nAlpha[i] = subK[i];
        }

        if (message[i] >= 65 && message[i] <= 90) { 
           // ch = (ch + k - 65) % 26 + 65; 
        }   
        result[i] = ch;
    }
        //result[length] = '\0';
        
        printf("Encrypted message: %s\n", result);
        
    return 0;
}
