# Arduino Gemini AI Assistant

A project developed during MLH Hack Nights in Sheffield × iForge on April 26th, 2025. This project connects an Arduino to Google's Gemini AI API to create an intelligent assistant device.

## Project Overview

This project uses an Arduino board with WiFi capabilities to connect to Google's Gemini AI API. It sends text prompts to the API and receives AI-generated responses, allowing your Arduino to act as an AI assistant for various applications. If you wish to use 

## Requirements

- Arduino board with WiFi capabilities
- Arduino IDE installed ([Download here](https://www.arduino.cc/en/software/))
- USB Type-C cable for connecting Arduino to computer
- Google Gemini API key
- WiFi connection

## Setup Instructions

1. Clone this repository to your local machine
2. Create a `secrets.h` file in the `src` directory with the following content:

   ```cpp
   #define SSID "your_wifi_name"
   #define WIFI_PASSWORD "your_wifi_password"
   #define API_KEY "your_gemini_api_key"
   ```

3. Connect your Arduino board to your computer using a USB-C cable
4. Open the Arduino IDE and load the project
5. Select your Arduino board from Tools > Board menu
6. Upload the code to your Arduino

## Usage

Once the code is uploaded and running:

1. The Arduino will connect to your WiFi network
2. It will send a sample prompt to the Gemini API
3. The response will be displayed in the Serial Monitor
4. You can customize the prompts in the `main.ino` file

## Project Structure

- `main.ino`: Contains the main Arduino setup and loop functions
- `gemini.ino`: Contains the WiFi connection and Gemini API functions
- `secrets.h`: Contains your personal WiFi and API credentials (not included in repository)

## Event Information

This project was created during the MLH Hack Nights in Sheffield × iForge event.

### Event Schedule (April 26th, 2025)

- 11:30am-12:00pm: Arrival (Diamond CR4)
- 12:00pm-12:30pm: Opening ceremony and team building
- 12:30pm: Hacking begins
- 1:00pm: Lunch
- 3:00pm: Mini event
- 5:00pm: Dinner
- 6:00pm: Soft deadline for submissions
- 6:30pm: Hard deadline - Hacking ends
- 6:30pm-7:30pm: Judging
- 7:30pm-8:00pm: Closing ceremony and prizes

## Credits

Developed by [Your Name/Team Name] during MLH Hack Nights in Sheffield × iForge, April 2025.

## License

This project is open source and available under the [MIT License](LICENSE).
