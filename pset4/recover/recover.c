#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check if there are two line arguments
    if (argc != 2)
    {
        printf("./recover imagem\n");
        return 1;
    }
    
    // Declare variable to read the memory card
    FILE *file = fopen(argv[1], "r");
    
    // Check if card can be opened
    if (!file)
    {
        printf("Não foi possível abrir");
        return 2;
    }
    
    // Create array to store the images bytes
    BYTE buffer[512];
    // Create counter for number of images
    int counter = 0;
    FILE *img = NULL;
    char filename[8];
    
    while(fread(buffer, sizeof(BYTE), 512, file))
    {
        // Check if first bytes of the buffer are valid for jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If it is the first image
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
            }
            // If it's not the first found image, close the current one and create another 
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
            }
            
            // Increment to the image counter
            counter ++;
        }
        
        // If it isn't a jpeg, but we are already reading one, keep writing the image
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(BYTE), 512, img);
        }
    }
    
    // Close files
    fclose(img);
    fclose(file);
}
