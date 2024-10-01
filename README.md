<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Smart Home System</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            background-color: #f4f4f4;
            color: #333;
            padding: 20px;
            margin: 0;
        }
        h1, h2, h3 {
            color: #2c3e50;
        }
        code {
            background-color: #eaeaea;
            padding: 2px 4px;
            border-radius: 4px;
        }
        pre {
            background-color: #eaeaea;
            padding: 10px;
            border-radius: 4px;
            overflow-x: auto;
        }
        ul {
            list-style-type: none;
            padding: 0;
        }
        ul li {
            background: #fff;
            margin: 5px 0;
            padding: 10px;
            border-radius: 4px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        }
    </style>
</head>
<body>

<h1>Smart Home System</h1>
<p>This project implements a Smart Home System using the ATmega32 microcontroller. The system allows users to control devices such as lights and fans in different rooms through a keypad or UART communication.</p>

<h2>Features</h2>
<ul>
    <li>User authentication with a unique ID and password.</li>
    <li>Control of lights and fans in multiple rooms.</li>
    <li>Interactive LCD display for user feedback.</li>
    <li>UART communication for remote control via serial interface.</li>
</ul>

<h2>Components Used</h2>
<ul>
    <li>ATmega32 Microcontroller</li>
    <li>LCD Display</li>
    <li>Keypad</li>
    <li>L293D Motor Driver</li>
    <li>DC Motors (Fans)</li>
    <li>LEDs (Lights)</li>
</ul>

<h2>Code Overview</h2>
<h3>Main Functionality</h3>
<p>The project consists of two main files:</p>
<pre><code>main.c</code></pre>
<p>The first <code>main.c</code> handles the user interface and controls the devices based on user input from the keypad.</p>
<pre><code>main1.c</code></pre>
<p>The second <code>main1.c</code> implements UART communication for controlling devices through serial commands.</p>

<h3>Connections</h3>
<p>The following connections should be made to the ATmega32 microcontroller:</p>
<ul>
    <li>LCD: Connected to PORTC</li>
    <li>Keypad: Connected to PORTD</li>
    <li>Fans: Connected via L293D to PORTB (Pin 0 and Pin 1 for Room 1, Pin 2 and Pin 3 for Room 2)</li>
    <li>LEDs: Connected to PORTA</li>
</ul>

<h2>Usage</h2>
<p>1. Compile the code and upload it to the ATmega32 microcontroller.</p>
<p>2. Connect the components as described above.</p>
<p>3. Power on the system and use the keypad to interact with the devices.</p>
<p>4. For UART control, connect a serial terminal to the appropriate COM port.</p>


</body>
</html>
