#include <cs50.h>
#include <stdio.h>

float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);
int is_prime(int number);
float calculate_cgpa(float grades[], int size);
void configuration(int password);

int main(void)
{
    int choice;
    int number;
    int password = 1234;
    int courses;
    int course;
    float first;
    float second;
    float answer;

    printf("========================================\n");
    printf("         WELCOME TO MATHBOT\n");
    printf("========================================\n");
    printf("Hello! I am MathBot.\n");
    printf("I am your personal mathematical assistant.\n");
    printf("What can I help you calculate today?\n");

    do
    {
        printf("\n============== MAIN MENU ==============\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Prime Number Checker\n");
        printf("6. CGPA Calculator\n");
        printf("0. Configuration\n");
        printf("7. Exit\n");
        printf("=======================================\n");

        choice = get_int("Enter your choice: ");

        if (choice == 1)
        {
            printf("\nADDITION\n");
            first = get_float("Enter first number: ");
            second = get_float("Enter second number: ");

            answer = addition(first, second);
            printf("Answer = %.2f\n", answer);
        }
        else if (choice == 2)
        {
            printf("\nSUBTRACTION\n");
            first = get_float("Enter first number: ");
            second = get_float("Enter second number: ");

            answer = subtraction(first, second);
            printf("Answer = %.2f\n", answer);
        }
        else if (choice == 3)
        {
            printf("\nMULTIPLICATION\n");
            first = get_float("Enter first number: ");
            second = get_float("Enter second number: ");

            answer = multiplication(first, second);
            printf("Answer = %.2f\n", answer);
        }
        else if (choice == 4)
        {
            printf("\nDIVISION\n");
            first = get_float("Enter first number: ");
            second = get_float("Enter second number: ");

            if (second == 0)
            {
                printf("MathBot cannot divide by zero!\n");
            }
            else
            {
                answer = division(first, second);
                printf("Answer = %.2f\n", answer);
            }
        }
        else if (choice == 5)
        {
            printf("\nPRIME NUMBER CHECKER\n");
            number = get_int("Enter an integer: ");

            if (is_prime(number) == 1)
            {
                printf("%d is a PRIME number.\n", number);
            }
            else
            {
                printf("%d is NOT a prime number.\n", number);
            }
        }
        else if (choice == 6)
        {
            printf("\nCGPA CALCULATOR\n");
            courses = get_int("How many courses do you have? ");

            float grades[courses];

            for (course = 0; course < courses; course++)
            {
                printf("Enter grade for course %d: ", course + 1);
                grades[course] = get_float("");
            }

            printf("\nYour grades:\n");
            for (course = 0; course < courses; course++)
            {
                printf("Course %d = %.2f\n", course + 1, grades[course]);
            }

            answer = calculate_cgpa(grades, courses);
            printf("\nYour CGPA = %.2f\n", answer);
        }
        else if (choice == 0)
        {
            configuration(password);
        }
        else if (choice == 7)
        {
            printf("Exiting MathBot...\n");
        }
        else
        {
            printf("Invalid choice!\n");
            printf("Please select an option from the menu.\n");
        }

    } while (choice != 7);

    printf("========================================\n");
    printf("Thank you for using MathBot!\n");
    printf("Goodbye! Keep calculating!\n");
    printf("========================================\n");

    return 0;
}

float addition(float a, float b)
{
    return a + b;
}

float subtraction(float a, float b)
{
    return a - b;
}

float multiplication(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    return a / b;
}

int is_prime(int number)
{
    int divisor;

    if (number < 2)
    {
        return 0;
    }

    for (divisor = 2; divisor < number; divisor++)
    {
        if (number % divisor == 0)
        {
            return 0;
        }
    }

    return 1;
}

float calculate_cgpa(float grades[], int size)
{
    int course;
    float sum = 0;

    for (course = 0; course < size; course++)
    {
        sum = sum + grades[course];
    }

    return sum / size;
}

void configuration(int password)
{
    int entered_password;
    int choice;

    entered_password = get_int("Enter the configuration password: ");

    while (entered_password != password)
    {
        printf("Incorrect password!\n");
        entered_password = get_int("Try again: ");
    }

    printf("Access Granted!\n");

    do
    {
        printf("\n========== CONFIGURATION ==========\n");
        printf("1. Bot information\n");
        printf("2. Return to main menu\n");
        printf("===================================\n");

        choice = get_int("Enter your choice: ");

        if (choice == 1)
        {
            printf("\n========== BOT INFORMATION ==========\n");
            printf("Name: MathBot\n");
            printf("Version: 1.0\n");
            printf("Purpose: Mathematical Assistant\n");
            printf("\nAvailable functions:\n");
            printf("- Addition\n");
            printf("- Subtraction\n");
            printf("- Multiplication\n");
            printf("- Division\n");
            printf("- Prime Number Checker\n");
            printf("- CGPA Calculator\n");
            printf("=====================================\n");
        }
        else if (choice == 2)
        {
            printf("Returning to main menu...\n");
        }
        else
        {
            printf("Invalid configuration choice!\n");
        }

    } while (choice != 2);
}
