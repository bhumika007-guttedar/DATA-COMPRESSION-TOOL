# DATA-COMPRESSION-TOOL

*COMPANY* : CODTECH IT SOULUTIONS

*NAME* : BHUMIKA

*INERN ID* : CT08K876

*DURATION* : 4 WEEKS

*MENTOR* : NEELA SANTOSH

Run-Length Encoding (RLE) Data Compression Tool
-------------------------------------------------
This C program (rle_compressor.c) implements a basic Run-Length Encoding (RLE) algorithm, a simple yet effective form of lossless data compression. RLE is particularly well-suited for compressing data that contains long sequences of the same repeating character (e.g., a bitmap image with large areas of solid color, or a text file with repeated whitespace). It achieves compression by replacing these consecutive identical characters with a count and a single instance of the character.

Logic:
The program is built around two primary functions: compressRLE and decompressRLE, both operating on character strings. It utilizes functions from <string.h> for string manipulation and <ctype.h> for character type checking, crucial for parsing counts during decompression.

1. compressRLE(char *input):

This function takes a null-terminated string (input) as its argument, which represents the data to be compressed.

It uses a for loop to iterate through the input string character by character (input[i]). The loop continues until the null terminator (\0) is encountered.

Inside the loop, char current = input[i]; stores the character currently being examined.

int count = 1; initializes a counter for the current run of identical characters. It starts at 1 because current is the first character in the run.

A nested while (input[i] == input[i+1]) loop is the heart of the compression. It checks if the current character input[i] is the same as the next character input[i+1].

If they are the same, count is incremented, and i is also incremented (i++). This effectively moves the main loop's index forward, skipping over the repeated characters that are part of the current run.

This inner loop continues as long as the characters are identical, allowing count to accurately represent the length of the run.

Once the inner while loop terminates (meaning input[i] is different from input[i+1], or input[i+1] is the null terminator), the run has ended.

printf("%d%c", count, current); prints the count (as an integer) followed immediately by the current character (e.g., 3A for "AAA"). This forms the compressed output.

The printf("\n"); after the loop ensures a clean newline for the output.
-------------------------------------------------------------------------------------------
2. decompressRLE(char *input):

This function takes an RLE-compressed string as its argument (e.g., "4A3B2C").

It uses a while (input[i] != '\0') loop to iterate through the compressed string.

Inside the loop, int count = 0; initializes a counter to extract the numeric part of the compressed token.

A nested while (isdigit(input[i])) loop is used to parse the numerical count. isdigit() (from ctype.h) checks if a character is a digit.

count = count * 10 + (input[i] - '0');: This line is crucial for building the integer count from its character representation. For example, if input[i] is '4', (input[i] - '0') evaluates to 4. If the next character is '2', count becomes 4 * 10 + 2 = 42.

i++; moves the index past the digit characters.

After the inner loop, count holds the integer repetition count, and input[i] points to the character that needs to be repeated.

A for (int j = 0; j < count; j++) loop then prints the character input[i] exactly count times.

i++; increments i one more time to move past the character that was just decompressed, preparing for the next count-character pair.

printf("\n"); ensures a clean newline for the output.
---------------------------------------------------------------------------------------------
Execution:

The main function provides an interactive, menu-driven command-line interface:

1.An infinite while (1) loop is used to keep the program running until the user explicitly chooses to exit.

2.It presents a menu with three options: Compress Text, Decompress Text, and Exit.

3.scanf("%d", &choice); reads the user's integer choice.

4.getchar(); is used immediately after scanf. This is important because scanf("%d", ...) reads only the integer and leaves the newline character (\n) in the input buffer. If not consumed, this newline would be read by the subsequent fgets() call, leading to unexpected behavior (e.g., fgets reading an empty line).

5.A switch (choice) statement handles the user's input:

Case 1 (Compress Text): Prompts the user to Enter the text to compress:. fgets(input, MAX, stdin) reads the entire line of text from standard input into the input buffer (including the newline character). input[strcspn(input, "\n")] = '\0'; is a robust way to remove the trailing newline character that fgets includes, ensuring the string is properly null-terminated for compressRLE. Then, compressRLE(input); is called.

Case 2 (Decompress Text): Prompts the user to Enter the text to decompress (e.g., 4A3B):. It reads the input similarly to compression, removes the newline, and calls decompressRLE(input);.

Case 3 (Exit): Prints "Exiting..." and return 0; to terminate the program.

Default: Handles any invalid menu choices.

This interactive design makes the RLE tool user-friendly and showcases its practical application in compressing and decompressing simple data streams.
-------------------------------------------------------------
Expected Output (Interactive Session):
--- Data Compression Tool (RLE) ---
1. Compress Text
2. Decompress Text
3. Exit
Enter your choice: 1
Enter the text to compress: AAABBCDDD
Compressed Output:
3A2B1C3D

--- Data Compression Tool (RLE) ---
1. Compress Text
2. Decompress Text
3. Exit
Enter your choice: 2
Enter the text to decompress (e.g., 4A3B): 3A2B1C3D
Decompressed Output:
AAABBCDDD

--- Data Compression Tool (RLE) ---
1. Compress Text
2. Decompress Text
3. Exit
Enter your choice: 3
Exiting...


OUTPUT
---------------------

<img width="1915" height="1063" alt="Image" src="https://github.com/user-attachments/assets/a691f75d-2110-4f2f-b8d8-4484e3c92679" />
