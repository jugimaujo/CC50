// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Make a buffer to store header bytes
    uint8_t header[44];
    // There is only one header, so we just need to do this one time
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    // Create buffer with two bytes to store the audio samples
    int16_t buffer[1];
    // Read and write samples until end of audio file
    while(fread(buffer, sizeof(int16_t), 1, input) == 1)
    {
        // Multiply sample by the factor
        buffer[0] *= factor;
        fwrite((buffer), sizeof(int16_t), 1, output);
    }
    
    
    // Close files
    fclose(input);
    fclose(output);
}
