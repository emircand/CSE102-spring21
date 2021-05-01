#include<stdio.h>
#include<math.h>
/*definition of pi value*/
#define PI 3.14 

/*declerations of operation functions*/
void standart(int x);
void GeoCalculator(int y);
void Thermometer(int z);


int main(){

    int Calc_Type;
    /*menu on the first screen*/
    printf("Enter the Calculator Type:\n");
    printf("1. Standart Calculator\n");
    printf("2. Area & Perimeter Calculator\n");
    printf("3. Temperature Calculator\n");
    printf("--------------------------\n");
    scanf("%d",&Calc_Type);
    
    /*switch-case for menu operations*/
    switch (Calc_Type)
    {
    case 1:
        standart(1);
        break;
    case 2:
        GeoCalculator(2);
        break;
    case 3:
        Thermometer(3);
        break;
    default:
        printf("!!invalid calculator type!!");
    }
    return 0;
} 
void standart(int x){

    int Number_Type, Operator_Type;
    int number1, number2, real1, real2, i1, i2;
    
    printf("Enter the number type:\n");
    printf("1. integer\n");
    printf("2. complex\n");
    printf("--------------------------\n");
    scanf("%d",&Number_Type);

    printf("Enter the operation type:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("--------------------------\n");
    scanf("%d",&Operator_Type);

    /*nested switch-case operation to seperate number type and operation type*/
    switch (Operator_Type)
    {
    case 1:
        switch (Number_Type)
    {
        case 1:
            printf("enter the first integer:");
            scanf("%d",&number1);
            printf("enter the second integer:");
            scanf("%d",&number2);
            printf("sum of numbers: %d",number1+number2);
            break;
        case 2:
            printf("enter the first complex number (real part first):");
            scanf("%d %d",&real1, &i1);
            printf("enter the second complex number (real part first):");
            scanf("%d %d",&real2, &i2);
            printf("sum of numbers: %d + (%di)\n",real1+real2, i1+i2);
            break;
        default:
            printf("invalid number type!!\n");
    }   
        break;
    case 2:
        switch (Number_Type)
    {
        case 1:
            printf("enter the first integer:");
            scanf("%d",&number1);
            printf("enter the second integer:");
            scanf("%d",&number2);
            printf("multiplication of numbers: %d",number1*number2);
            break;
        case 2:
            printf("enter the first complex number (real part first):");
            scanf("%d %d",&real1, &i1);
            printf("enter the second complex number (real part first):");
            scanf("%d %d",&real2, &i2);
            printf("multiplication of numbers: %d + (%di)\n",real1*real2, i1*i2);
            break;
        default:
            printf("invalid number type!!\n");
    }
        break;
    default:
        printf("invalid operation type!!");
    }
}
void GeoCalculator(int y){
    int Shape_Type, radius, side1, side2, side3;
    double perimeter, area, heron;
    printf("enter the shape type:\n");
    printf("1. Rectangle\n");
    printf("2. Triangle\n");
    printf("3. Circle\n");
    printf("--------------------------\n");
    scanf("%d",&Shape_Type);

    switch (Shape_Type)
    {
    case 1:
        printf("please enter small and long side of rectangle:\n");
        scanf("%d %d",&side1, &side2);
        perimeter = 1.0*2*(side2+side1);
        area = 1.0*side1*side2;
        printf("Perimeter of Rectangle: %g\n", perimeter);
        printf("Area of Rectangle: %g\n",area);
        break;
    case 2:
        printf("please enter three sides of triangle:\n");
        scanf("%d %d %d",&side1, &side2, &side3);
        perimeter = 1.0*(side1 + side3 +side2);
        /*heron formula to find area of triangle*/
        heron = perimeter / 2;
        area = sqrt(heron*(heron-side1*1.0)*(heron-side2*1.0)*(heron-side3*1.0));
        printf("Perimeter of Triangle: %g\n", perimeter);
        printf("Area of Triangle: %g\n",area);
        break;
    case 3:
        printf("please enter radius of the circle: ");
        scanf("%d",&radius);
        perimeter = 2.0*PI*radius;
        area = 1.0*PI*radius*radius;
        printf("Perimeter of Circle: %g\n", perimeter);
        printf("Area of Circle: %g\n",area);
        break;
    default:
        printf("invalid shape type!!!");
    }
}
void Thermometer(int z){
    int Temp_Type;
    double kelvin_temp,fahr_temp;
    printf("enter the calculation type\n:");
    printf("1. Fahrenheit to Kelvin\n");
    printf("2. Kelvin to Fahrenheit\n");
    printf("--------------------------\n");
    scanf("%d",&Temp_Type);

    switch (Temp_Type)
    {
    case 1:
        printf("please enter the temperature in fahrenheit:\n");
        scanf("%lg",&fahr_temp);
        kelvin_temp = ((5/9)*(fahr_temp-32))+273.15;
        printf("Result = %g\n",kelvin_temp);
        break;
    case 2:
        printf("please enter the temperature in kelvin:\n");
        scanf("%lg",&kelvin_temp);
        fahr_temp = ((9/5)*kelvin_temp-273.15)+32;
        printf("Result = %g\n",fahr_temp);
        break;
    default:
        printf("invalid calculation type!!\n");
    }
} 