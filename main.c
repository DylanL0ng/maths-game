/*

Author:			Dylan Hussain
Description:	This is my first assignment for my programming module.
                This is a menu driven program that will ask the user
                a number of maths questions which will be given by
                the user each round, and it will keep track of how
                many questions the user got right or wrong each
                round incase the user decides that they want the
                program to display their stats via a menu option.
Date:			10/11/21

*/

#include <stdio.h>

// The range of the max amount of questions that are stored.
#define AMOUNT_OF_QUESTIONS 5

// Suffixs before output messages.
#define ERROR_SUFFIX "[ERROR]"   // Suffix before error messages.
#define OUTPUT_SUFFIX "[OUTPUT]" // Suffix before basic output messages.

// The error messages that are outputted to the user.
#define ERROR_NON_NUMERIC "You must enter a numeric value, please try again."
#define ERROR_QUIZ_NOT_STARTED "You need to start the quiz first to print results."
#define ERROR_OUT_OF_RANGE_4 "The number you entered is not between 1 - 4, please try again."
#define ERROR_OUT_OF_RANGE_5 "The number you entered is not between 1 - 5, please try again."
#define ERROR_QUESTIONS_NOT_SET "You need to enter the amount of question(s) you want per round first."

int main()
{
    int user_input; // Asks for the users input for entering amount of questions and entering the maths answer.

    int questions_per_round = 0;
    int incorrect_answers = 0;

    int correct_answers = -1; // Initialised to -1 as a way of telling if the user attempted any questions

    // Maths questions stored in a 2 dimensional char array
    // With 10 characters it bugs out but with 11 it works fine due to the end of file character.
    char math_questions[AMOUNT_OF_QUESTIONS][11] = {
        "2 + 2",
        "4 + 4",
        "2 / 1",
        "10 * 2 / 5",
        "20 * 2 / 2"
    };
    // Math answers stored in an integer array
    int math_answers[AMOUNT_OF_QUESTIONS] = {
        4,
        8,
        2,
        4,
        20
    };

    do
    {
        // Gets and validates the menu option inputed by the user.

        do
        {
            // Prints the menu options and asks for use input.

            printf(
                "\n"
                "1. Enter Questions per Round\n"
                "2. Start Quiz\n"
                "3. Print Results\n"
                "4. Quit\n");

            printf("\n> ");

            // If scanf returns 0, then the scanf is invalid meaning someone entered a character.
            if (!scanf("%d", &user_input))
            {
                // Print error message stating that the input wasn't a numeric value.
                printf("\n%s %s\n", ERROR_SUFFIX, ERROR_NON_NUMERIC);

            } // end if
            else if (user_input < 1 || user_input > 4)
            {
                // If the number is out of range display an error message stating so.
                printf("\n%s %s\n", ERROR_SUFFIX, ERROR_OUT_OF_RANGE_4);

            } // end if

            // Flush the input buffer to 0, this prevents extra unwanted input being caught.
            fflush(stdin);

        } while (user_input < 1 || user_input > 4); // end do while

        // Checking user input and performing the task that corresponds with the number entered.
        switch (user_input)
        {
        case 1: // Enter the amount of questions per round.

            do
            {
                // Checking user input for questions per round and validating it.

                printf("\n%s Enter your desired questions per round between 1 - %d.\n", OUTPUT_SUFFIX, AMOUNT_OF_QUESTIONS);
                printf("\n> ");

                if (!scanf("%d", &user_input))
                {
                    // Print error message stating that the input wasn't a numeric value.
                    printf("\n%s %s\n", ERROR_SUFFIX, ERROR_NON_NUMERIC);
                }
                else if (user_input < 1 || user_input > AMOUNT_OF_QUESTIONS)
                {
                    // If the number is out of range then display the error message stating so.
                    printf("\n%s %s\n", ERROR_SUFFIX, ERROR_OUT_OF_RANGE_5);
                }
                else
                {
                    questions_per_round = user_input; // If the user input is between the range, set the questions per round.

                } // end if

                // Flush the input buffer to 0, this prevents extra unwanted input being caught.
                fflush(stdin);
                
            } while (questions_per_round < 1 || questions_per_round > 5); // end do while

            user_input = -1; // Reset the attempt input so that it can be used again in validation.
            break;

        case 2: // Start the quiz.

            // Reset variable when user starts the quiz again.
            correct_answers = -1;

            if (questions_per_round != 0)
            {
                // Resets the incorrect and correct answers to 0 so that it can be counted correctly.
                correct_answers = 0;
                incorrect_answers = 0;

                // Iterate through each round.
                for (int i = 0; i < questions_per_round; i++)
                {

                    // Reset variable to -1 so that the program doesn't think the user wants to quit if they input 4.
                    user_input = -1;

                    do
                    {

                        // Display the maths question.
                        printf("\n%s = ?\n", math_questions[i]);
                        printf("\n> ");

                        // Check if the input is valid or not.
                        if (!scanf("%d", &user_input))
                        {
                            // Print error message stating that the input wasn't a numeric value.
                            printf("\n%s %s\n", ERROR_SUFFIX, ERROR_NON_NUMERIC);
                        }
                        // Checks if the user guessed the answer right.
                        else if (math_answers[i] == user_input)
                        {
                            // If they were right, increment the correct_answers paramater, and output a message.
                            printf("\n%s You entered: %d - Right !!\n", OUTPUT_SUFFIX, user_input);
                            correct_answers++;
                        }
                        else
                        {
                            // If they were wrong, increment the incorrect_answers paramater, and output a message.
                            printf("\n%s You entered: %d - Wrong !! The correct answer: %d.\n", OUTPUT_SUFFIX, user_input, math_answers[i]);
                            incorrect_answers++;

                        } // end if

                        // Flush the input buffer to 0, this prevents extra unwanted input being caught.
                        fflush(stdin);

                    } while (user_input == -1); // end do while

                } // end for
            }
            else
            {
                // Output an error message stating that the amount of questions to display weren't set.
                printf("\n%s %s\n", ERROR_SUFFIX, ERROR_QUESTIONS_NOT_SET);

            } // end if

            // Reset the attempt input so that it can be used again.
            user_input = -1;
            break;

        case 3: // Print the results.

            if (correct_answers != -1)
            {
                // Displays the users stats, instead of storing the amount of incorrect answers I just took the correct answers from the amount of questions per round.
                printf("\n%s You entered %d question(s) correctly, and %d question(s) incorrectly.\n", OUTPUT_SUFFIX, correct_answers, incorrect_answers);
            }
            else
            {
                // Output an error message stating the player needs to start the game to print results.
                printf("\n%s %s\n", ERROR_SUFFIX, ERROR_QUIZ_NOT_STARTED);

            } // end if

            // Reset the attempt input so that it can be used again.
            user_input = -1;
            break;

        } // end switch

    } while (user_input != 4); // end do while

    return 0;
} // end main()