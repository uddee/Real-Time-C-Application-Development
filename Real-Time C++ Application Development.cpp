#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void analyzeData(std::vector<int>& data) {
    for (auto& value : data) {
        // Simulate data analysis by squaring each value
        value *= value;
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};  // Sample data

    // Start real-time data analysis in a separate thread
    std::thread analysisThread(analyzeData, std::ref(data));

    // Simulate other real-time processing (e.g., user input, sensor data, etc.)
    while (analysisThread.joinable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Processing data in real-time..." << std::endl;
    }

    // Wait for analysis thread to complete
    analysisThread.join();

    // Print the processed data
    std::cout << "Processed data: ";
    for (const auto& value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
