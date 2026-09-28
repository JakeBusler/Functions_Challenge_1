/*
 * Name: Jake Busler
 * Date: 9/8/26
 * Purpose: Calculate the area and perimeter of geometric shapes
 *          using function overloading and input validation.
 * Assignment: Challenge 1: Geometric Calculations with Function Overloading
 */

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>

// Function Declarations (Prototypes)
double calculateArea(const double radius);
double calculateArea(const double length, const double width);
double calculatePerimeter(const double radius);
double calculatePerimeter(const double length, const double width);

// Helper Input Validation Functions
void displayMenu();
int getMenuChoice(const int minChoice, const int maxChoice);
double getPositiveDimension(const std::string& prompt);

int main()
{
    int choice = 0;

    // Menu-driven loop using do-while
    do
    {
        displayMenu();
        choice = getMenuChoice(1, 5);

        // Switch statement handling all options
        switch (choice)
        {
            case 1:
            {
                std::cout << "\n--- Calculate Area of a Circle ---\n";
                const double radius = getPositiveDimension("Enter radius: ");
                const double area = calculateArea(radius);
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Result: Circle Area = " << area << "\n\n";
                break;
            }
            case 2:
            {
                std::cout << "\n--- Calculate Perimeter of a Circle ---\n";
                const double radius = getPositiveDimension("Enter radius: ");
                const double perimeter = calculatePerimeter(radius);
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Result: Circle Perimeter (Circumference) = " << perimeter << "\n\n";
                break;
            }
            case 3:
            {
                std::cout << "\n--- Calculate Area of a Rectangle ---\n";
                const double length = getPositiveDimension("Enter length: ");
                const double width = getPositiveDimension("Enter width: ");
                const double area = calculateArea(length, width);
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Result: Rectangle Area = " << area << "\n\n";
                break;
            }
            case 4:
            {
                std::cout << "\n--- Calculate Perimeter of a Rectangle ---\n";
                const double length = getPositiveDimension("Enter length: ");
                const double width = getPositiveDimension("Enter width: ");
                const double perimeter = calculatePerimeter(length, width);
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Result: Rectangle Perimeter = " << perimeter << "\n\n";
                break;
            }
            case 5:
            {
                std::cout << "\nExiting Geometric Calculator. Goodbye!\n";
                break;
            }
            default:
            {
                std::cout << "\nError: Invalid selection. Please choose an option between 1 and 5.\n\n";
                break;
            }
        }

    } while (choice != 5);

    return 0;
}

/**
 * Calculates the area of a circle.
 * @param radius Radius of the circle (passed by value, const).
 * @return Computed area as a double, or 0.0 for non-positive input.
 */
double calculateArea(const double radius)
{
    const double PI = 3.14159;

    // Edge case guard for non-positive radius
    if (radius <= 0.0)
    {
        return 0.0;
    }

    return PI * radius * radius;
}

/**
 * Calculates the area of a rectangle.
 * @param length Length of the rectangle (passed by value, const).
 * @param width Width of the rectangle (passed by value, const).
 * @return Computed area as a double, or 0.0 for non-positive input.
 */
double calculateArea(const double length, const double width)
{
    // Edge case guard for non-positive dimensions
    if (length <= 0.0 || width <= 0.0)
    {
        return 0.0;
    }

    return length * width;
}

/**
 * Calculates the perimeter (circumference) of a circle.
 * @param radius Radius of the circle (passed by value, const).
 * @return Computed circumference as a double, or 0.0 for non-positive input.
 */
double calculatePerimeter(const double radius)
{
    const double PI = 3.14159;

    // Edge case guard for non-positive radius
    if (radius <= 0.0)
    {
        return 0.0;
    }

    return 2.0 * PI * radius;
}

/**
 * Calculates the perimeter of a rectangle.
 * @param length Length of the rectangle (passed by value, const).
 * @param width Width of the rectangle (passed by value, const).
 * @return Computed perimeter as a double, or 0.0 for non-positive input.
 */
double calculatePerimeter(const double length, const double width)
{
    // Edge case guard for non-positive dimensions
    if (length <= 0.0 || width <= 0.0)
    {
        return 0.0;
    }

    return 2.0 * (length + width);
}

/**
 * Displays the menu options for geometric calculations.
 */
void displayMenu()
{
    std::cout << "========================================\n";
    std::cout << "         GEOMETRIC CALCULATOR           \n";
    std::cout << "========================================\n";
    std::cout << "1. Area of a Circle\n";
    std::cout << "2. Perimeter of a Circle\n";
    std::cout << "3. Area of a Rectangle\n";
    std::cout << "4. Perimeter of a Rectangle\n";
    std::cout << "5. Quit\n";
    std::cout << "========================================\n";
}

/**
 * Reads and validates a menu choice integer within [minChoice, maxChoice].
 */
int getMenuChoice(const int minChoice, const int maxChoice)
{
    std::string line;
    int choice = 0;

    while (true)
    {
        std::cout << "Enter your choice (" << minChoice << "-" << maxChoice << "): ";
        if (!std::getline(std::cin, line))
        {
            return maxChoice; // Default to quit if EOF / closed stream
        }

        std::istringstream stream(line);
        char extra = '\0';

        // Ensure a valid integer is extracted with no trailing invalid characters
        if ((stream >> choice) && !(stream >> extra))
        {
            if (choice >= minChoice && choice <= maxChoice)
            {
                return choice;
            }
            std::cout << "Error: Choice must be between " << minChoice << " and " << maxChoice << ". Please try again.\n";
        }
        else
        {
            std::cout << "Error: Invalid input. Please enter a whole number between "
                      << minChoice << " and " << maxChoice << ".\n";
        }
    }
}

/**
 * Reads and validates a strictly positive double dimension (> 0.0).
 */
double getPositiveDimension(const std::string& prompt)
{
    std::string line;
    double dimension = 0.0;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, line))
        {
            return 0.0;
        }

        std::istringstream stream(line);
        char extra = '\0';

        // Ensure a valid numeric value is extracted with no trailing garbage
        if ((stream >> dimension) && !(stream >> extra))
        {
            if (dimension > 0.0)
            {
                return dimension;
            }
            std::cout << "Error: Dimension must be greater than zero. Please try again.\n";
        }
        else
        {
            std::cout << "Error: Invalid numeric input. Please enter a positive number.\n";
        }
    }
}
