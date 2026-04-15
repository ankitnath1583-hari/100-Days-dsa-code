#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[100][50];
    char unique[100][50];
    int count[100] = {0};
    int uniqueCount = 0;

    // Read names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Count frequency
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount]++;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
