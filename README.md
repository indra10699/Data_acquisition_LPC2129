Data Acquisition System for LPC2129
===================================
> This project implements a Data Acquisition System (DAQ) built on the LPC2129 microcontroller. The system is designed to interface with a temperature sensor, I2C RTC, MCP3204 ADC, and a 16x2 LCD to collect, process, and display real-time data. It is ideal for embedded systems applications where precision in data collection and display is essential.

=> Overview
> The DAQ system collects temperature data from a temperature sensor (e.g., LM35), reads the current time from the I2C RTC (e.g., DS3231), and converts analog inputs using the MCP3204 ADC. The processed data is then displayed on a 16x2 LCD. This system is designed to provide a simple, yet effective, way to monitor environmental conditions and interface with external sensors in real-time.

=> Key Features
> Microcontroller: Built using the LPC2129 ARM7-based microcontroller, providing low power consumption and high processing power.
> Temperature Monitoring: Interfaces with an analog temperature sensor (such as the LM35) to measure temperature.
> I2C Real-Time Clock: Reads time and date data from an I2C RTC module (such as the DS3231) to timestamp the collected data.
> Analog-to-Digital Conversion: Uses the MCP3204 ADC to convert analog signals (e.g., sensor outputs) to digital form for processing.
> Real-Time Data Display: Displays the temperature and time data on a 16x2 LCD (LCD16x2) in a user-friendly format.
> Modular Design: Easily extendable to support additional sensors or other peripherals.

=> Hardware Components
> LPC2129 microcontroller development board or custom PCB.
> Temperature Sensor (e.g., LM35): To measure ambient temperature.
> I2C Real-Time Clock (RTC): DS3231 or similar for real-time date and time.
> MCP3204 ADC: A 4-channel, 12-bit analog-to-digital converter used to convert analog signals to digital.
> 16x2 LCD Display: Used to display temperature data, time, and other relevant information.

=> Software Components
> I2C Communication: Used to interface with the RTC and other I2C devices.
> MCP3204 Driver: Software module to interface with the MCP3204 ADC.
> LCD Driver: Software module to communicate with the 16x2 LCD.
> Real-Time Clock Handling: Code to initialize, read, and display time and date from the RTC.
