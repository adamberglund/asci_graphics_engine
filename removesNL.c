#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file, *output_file;
    char *input_filename = "input.txt";
    char *output_filename = "output.txt";
    int c;
    int newline_count = 0;

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file %s\n", input_filename);
        return 1;
    }

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file %s\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Read file character by character
    while ((c = fgetc(input_file)) != EOF) {
        if (c == '\n') {
            newline_count++;
            // Write newline only if it's an odd-numbered newline
            if (newline_count % 2 == 1) {
                fputc(c, output_file);
            }
        } else {
            fputc(c, output_file);
        }
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File processing complete. Output written to %s\n", output_filename);
    return 0;
}