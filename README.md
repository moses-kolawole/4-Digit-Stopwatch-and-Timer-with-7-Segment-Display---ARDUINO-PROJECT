# 4-Digit Stopwatch and Timer with 7-Segment Display - ARDUINO PROJECT

## Overview
This project implements a digital stopwatch and timer system using an Arduino and a 4-digit 7-segment display. Push buttons are used to set minutes and seconds, switch between modes, and start a countdown-style stopwatch. The display is multiplexed to show time accurately across all four digits.

## Objective
- Learn how to control a multi-digit 7-segment display using multiplexing  
- Implement timer and stopwatch logic using Arduino  
- Read and manage multiple push button inputs  
- Practice breaking complex logic into reusable functions  
- Understand time-based counting using delays and loops  

## Components Used
- Arduino Uno  
- 4-Digit 7-Segment Display  
- Push buttons × 4  
- 220Ω resistors  
- Breadboard  
- Jumper wires  
- 9V Battery  
- 9V Battery Clip

## Circuit Diagram
![Circuit Diagram](images/stopwatch_photo7.jpg)

## How It Works
1. The 4-digit 7-segment display is controlled using multiplexing, where each digit is enabled one at a time very quickly.
2. Buttons are assigned specific functions:
   - Button 1: Increase value (seconds or minutes)
   - Button 2: Decrease value (seconds or minutes)
   - Button 3: Switch between seconds-setting mode and minutes-setting mode
   - Button 4: Start the stopwatch countdown
3. The timer mode allows the user to set minutes and seconds manually.
4. The stopwatch mode counts down from the set time until it reaches zero.
5. Separate functions handle:
   - Displaying digits on the 7-segment display
   - Updating seconds and minutes
   - Running the stopwatch countdown
6. The display continuously refreshes to give a stable visual output.

## Code
The Arduino sketch for this project is located in the [code/ directory](code/stopwatch_project_on_8th_november_2025.ino).

## Demo Video
A demonstration video showing the working project is included in this repository.

📹 **Project Demonstration:**  
[Click here to watch/download the demo video](video/)

*(If the video does not preview directly on GitHub, please download it using the link above.)*

## Reflection (What I Learned)
- How to multiplex a 4-digit 7-segment display  
- Implementing timer and countdown logic in Arduino  
- Managing multiple button inputs with shared functionality  
- Structuring larger Arduino programs using functions  

## Challenges Faced
- Preventing flicker during display multiplexing  
- Managing button presses without unintended multiple triggers  
- Keeping timing accurate using delay-based logic  

## Possible Improvements
- Add buzzer or LED alert when the countdown reaches zero  
- Implement non-blocking timing using `millis()`  
- Add pause and reset functionality  
- Replace buttons with a keypad or rotary encoder  

## Project Status
Completed







