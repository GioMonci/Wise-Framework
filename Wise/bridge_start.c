#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "lora.h"



// Predefined compression weights
const float weights[2][3] = {
    {0.5, 0.1, 0.3},   
    {0.2, 0.7, 0.5}    
};

// Placeholder for I2C initialization
void init_i2c() {
    // Add I2C initialization code here if necessary
}

// Placeholder for accelerometer data reading
void read_accelerometer(float *data) {
    data[0] = 0.5;  // Simulated X-axis value
    data[1] = 1.0;  // Simulated Y-axis value
    data[2] = -0.5; // Simulated Z-axis value
}

// Compression logic using weights
void compress_data(const float *input, float *output) {
    for (int i = 0; i < 2; i++) {
        output[i] = 0;
        for (int j = 0; j < 3; j++) {
            output[i] += weights[i][j] * input[j];
        }
    }
}

// Send compressed data via LoRa
void send_lora(float *compressed_data) {
    printf("Sending data via LoRa: %.2f, %.2f\n", compressed_data[0], compressed_data[1]);
}

// Main application loop
//void app_main() {
    init_i2c();             // Initialize I2C (optional)
    lora_init();            // Initialize LoRa
    lora_set_frequency(915E6);  // Set LoRa frequency
    printf("LoRa initialized.\n");

    float accel_data[3];       // Placeholder for accelerometer data
    float compressed_data[2];  // Placeholder for compressed data

    while (1) {
        read_accelerometer(accel_data);        // Simulate accelerometer data reading
        compress_data(accel_data, compressed_data);  // Compress data
        send_lora(compressed_data);            // Send compressed data via LoRa
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Delay for 2 seconds
    }
}
