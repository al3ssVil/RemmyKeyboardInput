# Piesa Game

A C++ program to simulate a Rummy game involving "pieces", with functionalities to read, validate, and sort the pieces, as well as find sequences and formations based on the pieces' numbers and colors.

## Description

This project is a simulation of a game involving pieces with numbers and colors. The main functionalities include:

- **Reading pieces:** It takes a list of pieces where each piece has a number and a color (blue, black, red, or yellow).
- **Validation:** It checks if the pieces' numbers are between 1 and 13 and if the colors are valid. Additionally, it ensures no piece color is repeated more than twice for the same number.
- **Sorting:** The pieces are sorted by their numbers.
- **Checking sequences:** It identifies and displays any sequences of three or more pieces with the same number or color.
- **Longest Formation:** It determines the longest possible formation of pieces by both number and color.
- **Adding a new piece:** It allows the user to input a new piece, updating the set of pieces.

### Key Features:
- Input validation for pieces' numbers and colors.
- Sorting pieces based on their numbers.
- Displaying valid sequences of pieces based on number and color.
- Functionality to display the longest formation of pieces.

## Example use

### Sample Input:
The input is a list of 14 pieces, where each piece consists of a number and a color:
```text
1 blue
2 black
2 blue
1 red
1 black
3 blue
10 black
10 red
11 black
10 blue
12 red
8 blue
4 black
5 red
```
Output:
The program will:

- Validate the input pieces.
- Sort the pieces by their numbers.
- Check and display any sequences or formations, including those based on number or color.
- Allow the user to add a 15th piece, and then display the longest possible formation.

### The output might look like:
![image](https://github.com/user-attachments/assets/4974c8ba-0a2c-4c11-ba1a-03db20f468eb)
If you put for the 15th piece `4 blue`

Or
![image](https://github.com/user-attachments/assets/5c25b94d-155c-4282-887f-a1308db40630)

If you put `5 red`

