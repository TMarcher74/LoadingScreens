#include <stdio.h>
#include <windows.h>

#define PROGRESS_BAR_SIZE 75    //int PROGRESS_BAR_SIZE = 50; also works

void print_n_chars(int n, int c) {
    while (n-- > 0) putchar(c);
}

void display_progress_bar(int p) {
    putchar('\r');  
    //\r is what prints the characters in the same line.
    putchar('[');
    print_n_chars(PROGRESS_BAR_SIZE * p / 100, '|');
    print_n_chars(PROGRESS_BAR_SIZE - PROGRESS_BAR_SIZE * p / 100, '_');
    putchar(']');
}

int main() {
    int p;
    for (p = 0; p <= 100; ++p) {
        display_progress_bar(p);
        Sleep(20);
    }
    return 0;
}

/*
'\r' is the carriage return character. The main times it would be useful are:
When reading text in binary mode, or which may come from a foreign OS, you'll find (and probably want to discard) it due to CR/LF line-endings from Windows-format text files.
When writing to an interactive terminal on stdout or stderr, '\r' can be used to move the cursor back to the beginning of the line, to overwrite it with new contents. This makes a nice primitive progress indicator.
*/