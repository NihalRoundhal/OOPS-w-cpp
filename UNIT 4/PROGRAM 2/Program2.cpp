#include <fstream>      // For file handling
#include <iostream>     // For input and output
#include <string>       // For using string
#include <vector>       // For using vector

using namespace std;

// Structure to store one log entry
struct LogEntry {
    string line;        // Stores the complete log line
};

int main() {

    // Create and open server.log file for writing
    ofstream sampleLog("server.log");

    // Check if the file was created successfully
    if (!sampleLog) {
        cerr << "Unable to create log file." << endl;
        return 1;       // Stop the program if file cannot be created
    }

    // Write log entries into the file
    sampleLog << "2026-09-09 08:00:00 INFO Server started\n";
    sampleLog << "2026-09-09 08:10:00 WARNING High memory usage\n";
    sampleLog << "2026-09-09 08:20:00 ERROR Database connection failed\n";
    sampleLog << "2026-09-09 08:30:00 INFO Backup completed\n";
    sampleLog << "2026-09-09 08:40:00 CRITICAL Disk space low\n";

    // Close the file after writing
    sampleLog.close();

    // Open server.log file for reading
    ifstream logFile("server.log");

    // Check if the file was opened successfully
    if (!logFile) {
        cerr << "Unable to open server.log." << endl;
        return 1;       // Stop the program if file cannot be opened
    }

    // Vector to store ERROR and CRITICAL log entries
    vector<LogEntry> errors;

    // Variable to store each line read from the file
    string line;

    // Read the log file line by line
    while (getline(logFile, line)) {

        // Check if the line contains "ERROR" or "CRITICAL"
        if (line.find("ERROR") != string::npos ||
            line.find("CRITICAL") != string::npos) {

            // Add the matching line to the vector
            errors.push_back({line});
        }
    }

    // Display heading
    cout << "=== Critical Log Events ===" << endl;

    // Display all critical/error log entries
    for (const auto& entry : errors) {
        cout << entry.line << endl;
    }

    // Display total number of critical events
    cout << "Total critical events: " << errors.size() << endl;

    return 0;       // End the program successfully
}
