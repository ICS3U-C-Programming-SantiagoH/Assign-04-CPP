// Copyright (c) 2023 Santiago Hewett All rights reserved.
//
// Created by: Santiago Hewett
// Date: Nov 27, 2023
// Simulates rolling two dice until doubles are obtained,
// calculates the percentage chance of rolling doubles and
// the average number of rolls across multiple test cases,
// using the Mersenne Twister random number generator.

#include <iostream>
#include <random>

// Function to simulate rolling 2 dice
int rollDie(const std::mt19937& rng) {
    // Mersenne Twister random number generator
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(rng);
}

// Function to simulate rolling 2 dice until doubles are obtained
void simulateDiceRolls() {
    std::random_device rd;
    std::mt19937 rng(rd());  // Mersenne Twister PRNG

    // initialize variables
    int totalRolls = 0;
    int successfulRuns = 0;
    int testCases = 3;  // Number of times to run the simulation

    // for loop for test cases
    for (int testCase = 1; testCase <= testCases; ++testCase) {
        std::cout << "\nTest Case " << testCase << ":\n";

        int rolls = 0;

        // while true for dice rolls
        while (true) {
            // Simulate rolling 2 dice
            int dice1 = rollDie(rng);
            int dice2 = rollDie(rng);

            // Display the roll
            std::cout << "Roll " << rolls + 1 << ": " << dice1 << "  "
            << dice2 << std::endl;

            // Check for doubles
            if (dice1 == dice2) {
                if (rolls == 0) {
                    std::cout << "Doubles obtained in the first roll!\n\n";
                } else {
                    std::cout << "Doubles obtained in " << rolls + 1
                    << " rolls!\n\n";
                }
                successfulRuns++;
                break;  // Exit the loop when doubles are obtained
            }

            rolls++;
        }

        totalRolls += rolls;
    }

    // Calculate and display the percentage chance and average rolls
    int percentageChance = (successfulRuns * 100) / testCases;
    int averageRolls = (totalRolls + testCases - 1) / testCases;
    std::cout << "Percentage chance of rolling doubles: "
    << percentageChance << "%\n";
    std::cout << "Average number of rolls: " << averageRolls << std::endl;
}

int main() {
    // Call the main simulation function
    simulateDiceRolls();
}
