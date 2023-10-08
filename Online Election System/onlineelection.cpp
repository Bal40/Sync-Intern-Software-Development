#include <iostream>
using namespace std;

int nda = 0, india = 0, others = 0;

void electionResult() {
    int wonByVote;
    if (nda > india && nda > others) {
        cout << "\n**NDA won the Lok Sabha election**\n\n";
        cout << "Total vote of NDA: " << nda << endl;
        wonByVote = nda - india;
        cout << "NDA won by " << wonByVote << " votes to INDIA" << endl;
        wonByVote = nda - others;
        cout << "NDA won by " << wonByVote << " votes to OTHERS" << endl;
    } else if (india > others) {
        cout << "\n**INDIA won the Lok Sabha election**\n\n";
        cout << "Total vote of INDIA: " << india << endl;
        wonByVote = india - nda;
        cout << "INDIA won by " << wonByVote << " votes to NDA" << endl;
        wonByVote = india - others;
        cout << "INDIA won by " << wonByVote << " votes to OTHERS" << endl;
    } else if (nda == india && nda == others) {
        cout << "\nNo one won the Lok Sabha election\n\n";
        cout << "            NDA---INDIA---OTHERS\n";
        cout << "Total Vote   " << nda << "       " << india << "        " << others << endl;
    } else {
        cout << "\n**OTHERS won the Lok Sabha election**\n\n";
        cout << "Total vote of OTHERS: " << others << endl;
        wonByVote = others - india;
        cout << "OTHERS won by " << wonByVote << " votes to INDIA" << endl;
        wonByVote = others - nda;
        cout << "OTHERS won by " << wonByVote << " votes to NDA" << endl;
    }
}

void calculateVote(int vote) {
    switch (vote) {
        case 1:
            nda += 1;
            break;
        case 2:
            india += 1;
            break;
        case 3:
            others += 1;
            break;
    }
}

int main() {
    int choose, numParties;
    
    cout << "\n****Welcome to the Lok Sabha election system****\n\n";
    cout << "Enter the number of parties participating: ";
    cin >> numParties;
    
    if (numParties < 2) {
        cout << "At least two parties are required for an election." << endl;
        return 1;
    }
    
    cout << "*********************\n";
    for (int i = 1; i <= numParties; i++) {
        cout << "|           " << i << ". Party " << i << "          ";
    }
    cout << "|\n*********************\n\n";
    
    do {
        cout << "Press 1 to vote for NDA\n";
        cout << "Press 2 to vote for INDIA\n";
        for (int i = 3; i <= numParties; i++) {
            cout << "Press " << i << " to vote for Party " << i << endl;
        }
        cout << "Press " << numParties + 1 << " to show election result\n";
        cout << "Please choose: ";
        cin >> choose;
        
        if (choose == numParties + 1) {
            electionResult();
        } else if (choose >= 1 && choose <= numParties) {
            calculateVote(choose);
        } else {
            cout << "Invalid choice. Please choose a valid option.\n";
        } 
        cout << "\n";
    } while (choose != numParties + 1);

    return 0;
}
