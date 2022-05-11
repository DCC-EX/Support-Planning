# Turntable-EX Regression Testing Process

The regression testing process is to be completed prior to any new release of Turntable-EX.

Note that the focus of the regression testing is the reliability and functionality of the Turntable-EX code, not the accuracy or performance of the stepper motors. There are variances to take into account with different manufacturers of stepper motors, particular when it comes to generic clones that have questionable quality control. The automatic calibration sequence has been written specifically to cater for this.

## Preparation

The CommandStation used to for this testing must be running the [add-turntable-controller](https://github.com/DCC-EX/CommandStation-EX/tree/add-turntable-controller) branch of release version 4.1.0.

In addition, the myAutomation.h and myHal.cpp files included in the folder with this file must be included with the software uploaded to the CommandStation.

**NOTE on myAutomation.h:** If you are not using the default ULN2003/28BYJ-48 stepper driver/motor combination, you will likely need to update config.h to be relevant for your testing setup. If this is the case, you will likely also need to ensure that the step positions used during the Basic Movement tests are updated to suit.

### Hardware Requirements

- CommandStation-EX with EX-RAIL support (Wireless optional but required if testing with Engine Driver/WiThrottle).
- An Arduino Nano/Uno configured as per the Turntable-EX documentation with a supported stepper driver, motor, and homing sensor. A dual relay board is optional but recommended for validation of phase switching.
- A suitable config.h file configured as per the Turntable-EX documentation, with the only configuration change being the appropriate stepper driver to suit the supported hardware in use.
- LEDs for validating the LED and accessory outputs.
- A phone or tablet running Engine Driver (A full WiThrottle app supporting ROUTEs will also work).

If Engine Driver or a WiThrottle app is not available for testing, the test steps will include the equivalent diagnostic command to execute directly from the CommandStation serial console to perform the same test.

## Outputs

Outputs of each step are to be recorded... somewhere?

## Testing Process

Ensure Turntable-EX is correctly connected via the I2C bus to the CommandStation, then power on Turntable-EX first, followed by the CommandStation, ensuring both are connected via serial, with serial console opened to both.

### Startup Sequence

On startup, use the serial console of Turntable-EX to validate the version, and note if steps have been stored previously in EEPROM or not:

```
License GPLv3 fsf.org (c) dcc-ex.com
Turntable-EX version X.X.X
Turntable-EX has been calibrated for XXXX steps per revolution    <<== Previous calibration complete *OR*
Turntable-EX has not been calibrated yet                          <<== Has not been calibrated
```

If Turntable-EX has been calibrated, it will proceed to home. Using the defaults in config.h should having homing operate in a clockwise direction, and cease movement when the homing sensor is triggered:

```
Turntable-EX has been calibrated for 4093 steps per revolution
Homing...
Homing started
Turntable homed successfully
```

If Turntable-EX has not been calibrated, it will also proceed to home, and once homed, it should automatically start the calibration process:

```
Turntable-EX has not been calibrated yet
Calibrating...
Homing started
Turntable homed successfully
CALIBRATION: Phase 1, homing...
CALIBRATION: Phase 2, counting full turn steps...
CALIBRATION: Completed, storing full turn step count: 4093
Turntable homed successfully
```

`Success Criteria:` Startup displays as per the above, with the turntable successfully homed and/or calibrated according to the initial state.

*Note that the homing sensor must be connected correctly and functional for this test to succeed.*

### Turntable-EX is Available

In the serial console of the CommandStation, execute `<D HAL SHOW>` and ensure the output is as displayed:

```
<D HAL SHOW><* Arduino Vpins:2-69 *>
<* PCA9685 I2C:x40 Configured on Vpins:100-115 OFFLINE *>
<* PCA9685 I2C:x41 Configured on Vpins:116-131 OFFLINE *>
<* MCP23017 I2C:x20 Configured on Vpins:164-179 OFFLINE *>
<* MCP23017 I2C:x21 Configured on Vpins:180-195 OFFLINE *>
<* TurntableEX I2C:x60 Configured on Vpins:600-600  *>          <<== Turntable-EX is online
<* LCD3:Free RAM= 2412b *>
```

`Success Criteria:` Output of `<D HAL SHOW>` does not have TurntableEX marked 'OFFLINE'.

*Note that the I2C connection to the CommandStation must be reliable, and Turntable-EX powered on prior to the CommandStation for this test to succeed.*

### Basic Movement and Phase Inversion

#### Part 1 - Clockwise

Testing basic movement requires use of the serial console of the CommandStation and/or Engine Driver or a WiThrottle application in order to issue the required commands.

When using the serial console, executing the below commands in this order should have the turntable rotate in a clockwise direction only, with the last three positions activating the dual relay board for DCC phase inversion.

```
<D TT 600 114 0>
<D TT 600 227 0>
<D TT 600 341 0>
<D TT 600 2159 1>
<D TT 600 2273 1>
<D TT 600 2386 1>
```

If using Engine Driver or a WiThrottle for these tests, select these ROUTEs in this order which should have the same output as the serial commands above:

1. TTEX-RT1 - Position 1
2. TTEX-RT2 - Position 2
3. TTEX-RT3 - Position 3
4. TTEX-RT4 - Position 4
5. TTEX-RT5 - Position 5
6. TTEX-RT6 - Position 6

`Success Criteria:` The turntable should rotate to ~10 degrees from home, then ~20 degrees, then ~30 degrees, then ~190 degrees with relay activation, ~200 degrees maintaining relay activation, and finally ~210 degrees maintaining relay activation, all in a clockwise direction.

#### Part 2 - Counter Clockwise

Executing the below commands in this order should have the turntable rotate in a counter clockwise direction, with the second command deactivating the dual relay board:

```
<D TT 600 2159 1>
<D TT 600 227 0>
```

If using Engine Driver or a WiThrottle for these tests, select these ROUTEs in this order which should have the same output as the serial commands above:

1. TTEX-RT7 - Position 4
2. TTEX-RT8 - Position 2

`Success Criteria:` The turntable should rotate to ~190 degrees from home maintaining relay activation, then ~20 degrees and deactiving the relays.