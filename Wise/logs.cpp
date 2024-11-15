#include <Arduino.h>
#include <FS.h>
#include <SPIFFS.h>

class CustomLogger {
public:
    CustomLogger(const char* logFileName = "/project_log.txt") {
        this->logFileName = logFileName;
        if (!SPIFFS.begin(true)) {
            Serial.println("[ERROR] Failed to initialize SPIFFS.");
        }
    }

    void logInfo(const String& message) {
        String logMessage = formatMessage("INFO", message);
        writeToSerial(logMessage);
        writeToFile(logMessage);
    }

    void logError(const String& message) {
        String logMessage = formatMessage("ERROR", message);
        writeToSerial(logMessage);
        writeToFile(logMessage);
    }

    void addSeparator(char character = '-', int length = 40) {
        String separator = String(character).repeat(length);
        writeToSerial(separator);
        writeToFile(separator);
    }

private:
    const char* logFileName;

    String formatMessage(const String& level, const String& message) {
        String timestamp = String(millis() / 1000.0, 2) + "s"; // Time since boot in seconds
        return "[" + level + "] " + timestamp + " - " + message;
    }

    void writeToSerial(const String& message) {
        Serial.println(message);
    }

    void writeToFile(const String& message) {
        File file = SPIFFS.open(logFileName, FILE_APPEND);
        if (!file) {
            Serial.println("[ERROR] Failed to open log file for writing.");
            return;
        }
        file.println(message);
        file.close();
    }
};