/* Dynamic Programming C/C++ implementation of LCS problem */
#include <bits/stdc++.h>

int LCSubStr(char *X, char *Y, int m, int n)
{
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].

    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring

    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = std::max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
void printLcs(int **lcsDpGrid, char *X, char *Y, int m, int n)
{
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */

    int index = lcsDpGrid[m][n];

    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1]; // Put current character in result
            i--;
            j--;
            index--; // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (lcsDpGrid[i - 1][j] > lcsDpGrid[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the lcs
    std::cout << "LCS of " << X << " and " << Y << " is " << lcs << "\n";
}
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n)
{
    int **L = new int *[m + 1];
    for (int i = 0; i < m; i++)
        L[i] = new int[n + 1];
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
        }
    }

    printLcs(L, X, Y, m, n);

    return L[m][n];
}

int main()
{
    char X[] = "aaaabbbbbb";
    char Y[] = "aaaadddddbbbbb";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    printf("Length of LCSub is %d\n", LCSubStr(X, Y, m, n));

    return 0;
}