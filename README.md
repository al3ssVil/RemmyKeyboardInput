# Piesa Game

A C++ program to simulate a game involving "piese" (pieces), with functionalities to read, validate, and sort the pieces, as well as find sequences and formations based on the pieces' numbers and colors.

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
1 albastru
2 negru
2 albastru
1 rosu
1 negru
3 albastru
10 negru
10 rosu
11 negru
10 albastru
12 rosu
8 albastru
13 negru
5 rosu
Output:
The program will:
```
Validate the input pieces.
Sort the pieces by their numbers.
Check and display any sequences or formations, including those based on number or color.
Allow the user to add a 15th piece, and then display the longest possible formation.
The output might look like:

![image](https://github.com/user-attachments/assets/2d8569ec-c16c-4ace-9d26-a44180324a58)

