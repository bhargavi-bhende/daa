#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet
#define prime 101 // A prime number

void searchPattern(char* pattern, char* text)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%prime"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % prime;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }

    // Slide the pattern over the text one by one
    for (i = 0; i <= N - M; i++)
    {
        // Check the hash values of current window of text and pattern
        // If the hash values match, then only check for characters one by one
        if (p == t)
        {
            // Check for characters one by one
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If pattern is found at the current position, print it
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash value for the next window of text
        // Remove leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - text[i] * h) + text[i + M]) % prime;

            // If the hash value becomes negative, make it positive
            if (t < 0)
                t = (t + prime);
        }
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Matching positions: ");
    searchPattern(pattern, text);

    return 0;
}
