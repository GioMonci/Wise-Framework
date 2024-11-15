#ifndef LOGS_H
#define LOGS_H

#include <Arduino.h>

class Logs {
public:
    // Constructor
    Logs(Stream &outputStream);

    // Logs a message with an optional newline
    void logMessage(const String &message, bool newline = true);

    // Logs an error message
    void logError(const String &error);

    // Logs a line separator
    void logSeparator(char separator = '-', size_t length = 40);

    // Logs the current timestamp
    void logTimestamp();

private:
    Stream &stream; // Reference to the output stream (e.g., Serial)
};

#endif // LOGS_H