/* corpus/product-numbers.c */
/* Taken from: https://www.programiz.com/c-programming/examples/product-numbers */
#include <stdio.h>
int main() {
    double a, b, product;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);  
 
    // Calculating product
    product = a * b;

    // %.2lf displays number up to 2 decimal point
    printf("Product = %.2lf", product);
    
    return 0;
}/* ProgramSourceWild */
