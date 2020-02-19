//INSTRUCTIONS
//Your parser will read from input.txt
//input.txt consists of a series inputs that you need to read.
//each input is proceeded by a flag.
//Each flag will be either I, C, or F.
//I means int, C means char, F means float.

//So for example

//I 7963467 
//means int 7963467

//C H
//means char H

//F 0.7896
//means float 0.7896

//Your parser must read in each input, and then print it to the correct file.
//ints go in ints.txt
//chars go in chars.txt
//floats go in floats.txt

//CODE BEGINS HERE

//include fprintf and fscanf

#include <stdio.h>

//begin your main function

int main(void)
{

//open ints.txt, chars.txt, and floats.txt for writing
//open input.txt for reading
//don't forget that the file access mode is different for each!

FILE* ints  = fopen("ints.txt", "w+");
FILE* chars  = fopen("chars.txt", "w+");
FILE* floats = fopen("floats.txt", "w+");
FILE* input = fopen("input.txt", "r+");


//create a char variable to hold the flags you read	

char c[255];

//create an int, char, and float variable to hold the int, char, and float values you read

int newInt[255];
char newChar[255];
float newFloat[255];

//while fscanf does not return an EOF error

while(fscanf(input, "%s", c) != EOF)
{
switch(*c)
{
	case 'C':
		while(fscanf(input, "%s", newChar) != EOF)
		{
			fputs(newChar, chars);
			fputs(" ", chars);
			break;
		}
	break;}

	case 'I':
                while(fscanf(input, "%d", newInt) != EOF)
                {
                        fputs(newInt, ints);
                        fputs(" ", ints);
                        break;
                }
        break;

        case 'F':
                while(fscanf(input, "%f", newFloat) != EOF)
                {
                        fputs(newFloat, floats);
                        fputs(" ", floats);
                        break;
                }
        break;
}

//read in a flag from input.txt

//if it stands for an int
//read an int from input.txt
//write the int to ints.txt

//if it stands for a char
//read a char from input.txt
//write the char to chars.txt

//if it stands for a float
//read a float from input.txt
//write the float to floats.txt

//once fscanf returns and EOF error return a successful exit status

fclose(ints);
fclose(chars);
fclose(floats);
fclose(input);

return 0;

}
