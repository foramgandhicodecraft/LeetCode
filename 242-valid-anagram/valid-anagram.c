#define CHAR_COUNT 256

bool isAnagram(char* s, char* t) {
    // Create two arrays to store the character counts
    int anagram[CHAR_COUNT] = {0};
    int anagram2[CHAR_COUNT] = {0};

    // If lengths of strings are not equal, they cannot be anagrams
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Count the frequency of each character in both strings
    for (int i = 0; s[i] != '\0'; i++) {
        anagram[s[i]]++;
        anagram2[t[i]]++;
    }

    // Compare the character frequencies in both strings
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (anagram[i] != anagram2[i]) {
            return false;
        }
    }

    return true;
}