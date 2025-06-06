#!/bin/bash
set -e

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"
ARDUINO_CLI=$(which arduino-cli || true)
DIRNAME="$(basename "$SCRIPTPATH")"
EXPECTED_CLI_MAJOR=0
EXPECTED_CLI_MINOR=33

if [ ! -x "$ARDUINO_CLI" ]; then
    echo "Cannot find 'arduino-cli' in your PATH. Install the Arduino CLI before you continue."
    echo "Installation instructions: https://arduino.github.io/arduino-cli/latest/"
    exit 1
fi

CLI_MAJOR=$(arduino-cli version | cut -d. -f1 | rev | cut -d ' '  -f1)
CLI_MINOR=$(arduino-cli version | cut -d. -f2)
CLI_REV=$(arduino-cli version | cut -d. -f3 | cut -d ' '  -f1)

if ((CLI_MAJOR <= EXPECTED_CLI_MAJOR && CLI_MINOR < EXPECTED_CLI_MINOR)); then
    echo "You need to upgrade your Arduino CLI version (now: $CLI_MAJOR.$CLI_MINOR.$CLI_REV, but required: $EXPECTED_CLI_MAJOR.$EXPECTED_CLI_MINOR.x or higher)"
    echo "See https://arduino.github.io/arduino-cli/installation/ for upgrade instructions"
    exit 1
fi

if (( CLI_MAJOR != EXPECTED_CLI_MAJOR || CLI_MINOR != EXPECTED_CLI_MINOR || CLI_REV != EXPECTED_CLI_REV)); then
    echo "You're using an untested version of Arduino CLI, this might cause issues (found: $CLI_MAJOR.$CLI_MINOR.$CLI_REV, expected: $EXPECTED_CLI_MAJOR.$EXPECTED_CLI_MINOR.$EXPECTED_CLI_REV)"
fi

echo "Finding Arduino Mbed core..."

has_arduino_core() {
    arduino-cli core list | grep "arduino:mbed_nano" || true
}
HAS_ARDUINO_CORE="$(has_arduino_core)"
if [ -z "$HAS_ARDUINO_CORE" ]; then
    echo "Installing Arduino Mbed core..."
    arduino-cli core update-index
    arduino-cli core install arduino:mbed_nano@4.0.2
    echo "Installing Arduino Mbed core OK"
else
    echo "Finding Arduino Mbed OK"
fi

echo "Finding Arduino Nano 33 BLE..."

has_serial_port() {
    (arduino-cli board list | grep "Arduino Nano 33 BLE" || true) | cut -d ' ' -f1
}
SERIAL_PORT=$(has_serial_port)
if [ -z "$SERIAL_PORT" ]; then
    echo "Cannot find a connected Arduino Nano 33 BLE development board (via 'arduino-cli board list')."
    echo "If your board is connected, double-tap on the RESET button to bring the board in recovery mode."
    exit 1
fi

has_nano_core() {
    (arduino-cli board list | grep "arduino:mbed_nano") || true
}
HAS_NANO_CORE="$(has_nano_core)"
if [ -z "$HAS_NANO_CORE" ]; then
    BOARD="arduino:mbed:nano33ble"
else
    BOARD="arduino:mbed_nano:nano33ble"
fi

echo "Finding Arduino Nano 33 BLE OK"

echo "Flashing board... If you receive a 'Permission denied' error, you can set up udev rules via:"
echo "    printf 'KERNEL==\"ttyUSB[0-9]*\",MODE=\"0666\"\\\nKERNEL==\"ttyACM[0-9]*\",MODE=\"0666\"' | sudo tee -a /etc/udev/rules.d/50-myusb.rules"
echo "(unplug the device for this to take effect)"
echo ""

cd "$SCRIPTPATH"
arduino-cli upload -p $SERIAL_PORT --fqbn $BOARD --input-dir $SCRIPTPATH

echo ""
echo "Flashed your Arduino Nano 33 BLE development board."
echo "To set up your development with Edge Impulse, run 'edge-impulse-daemon'"
echo "To run your impulse on your development board, run 'edge-impulse-run-impulse'"
