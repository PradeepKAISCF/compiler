#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 50
#define MAX_CHARS 26

int dfa[MAX_STATES][MAX_CHARS];

void initializeDFA(int numStates, int numChars) {
    // Initialize the DFA transition table with -1 (indicating no transition)
    for (int i = 0; i < numStates; ++i) {
        for (int j = 0; j < numChars; ++j) {
            dfa[i][j] = -1;
        }
    }
}

void addTransition(int currentState, char inputChar, int nextState) {
    // Add a transition to the DFA transition table if nextState is not -1
    if (nextState != -1) {
        dfa[currentState][inputChar - 'a'] = nextState;
    }
}

int isStringAccepted(const char* inputString, int initialState, int finalState) {
    // Check if the input string is accepted by the DFA
    int currentState = initialState;

    for (int i = 0; inputString[i] != '\0'; ++i) {
        int inputChar = inputString[i] - 'a';

        if (dfa[currentState][inputChar] == -1) {
            // No transition for the current input character
            return 0;  // String not accepted
        }

        currentState = dfa[currentState][inputChar];
    }

    // Check if the final state is reached after processing the entire string
    return currentState == finalState;
}

int main() {
    int numStates, numChars, numFinalStates;
    
    // Get the number of states, characters, and final states from the user
    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    printf("Enter the number of characters (assume a-z): ");
    scanf("%d", &numChars);

    printf("Enter the number of final states: ");
    scanf("%d", &numFinalStates);

    initializeDFA(numStates, numChars);

    // Get the transitions from the user
    printf("\nEnter the transitions (state input_char next_state, use -1 for non-existent state):\n");
    for (int i = 0; i < numStates; ++i) {
        for (int j = 0; j < numChars; ++j) {
            int nextState;
            printf("Transition from state %d with input '%c': ", i, 'a' + j);
            scanf("%d", &nextState);
            addTransition(i, 'a' + j, nextState);
        }
    }

    // Get the final state from the user
    int finalState;
    printf("\nEnter the final state: ");
    scanf("%d", &finalState);

    // Get the input string from the user
    char inputString[100];
    printf("\nEnter the input string (only lowercase alphabets): ");
    scanf("%s", inputString);

    // Check if the input string is accepted by the DFA
    if (isStringAccepted(inputString, 0, finalState)) {
        printf("\nThe input string is accepted by the DFA.\n");
    } else {
        printf("\nThe input string is not accepted by the DFA.\n");
    }

    return 0;
}
