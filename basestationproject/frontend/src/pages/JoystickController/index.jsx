import React, { useEffect, useState } from "react";
import axios from "axios";
import "./styles.css"; // Ensure you include the CSS file

const JoystickControl = () => {
  const [leftDrive, setLeftDrive] = useState(0);
  const [rightDrive, setRightDrive] = useState(0);
  const [leftJoystick, setLeftJoystick] = useState({ x: 0, y: 0 });
  const [rightJoystick, setRightJoystick] = useState({ x: 0, y: 0 });

  const sendCommand = async (leftDrive, rightDrive) => {
    const command = { left_drive: leftDrive, right_drive: rightDrive };

    try {
      const response = await axios.post("http://127.0.0.1:8080/command", command, {
        headers: { "Content-Type": "application/json" },
      });
      console.log("Command sent:", response.data);
    } catch (error) {
      console.error("Failed to send command:", error.response?.data || error.message);
    }
  };

  // Dedicated effect for left joystick
  useEffect(() => {
    const handleLeftJoystickInput = () => {
      const gamepads = navigator.getGamepads();
      const gamepad = gamepads[0]; // Use the first connected gamepad

      if (gamepad) {
        // Update left joystick state
        const leftStickX = Math.round(gamepad.axes[0] * 100); // Left/right on left stick
        const leftStickY = Math.round(gamepad.axes[1] * 100); // Up/down on left stick
        setLeftJoystick({ x: leftStickX, y: leftStickY }); // Invert Y for correct orientation

        // Map Y-axis of left stick to leftDrive
        const newLeftDrive = Math.round(gamepad.axes[1] * -100);
        if (newLeftDrive !== leftDrive) {
          setLeftDrive(newLeftDrive);
          sendCommand(newLeftDrive, rightDrive); // Send updated values
        }
      }
    };

    const interval = setInterval(handleLeftJoystickInput, 50); // Polling every 50ms
    return () => clearInterval(interval);
  }, [leftDrive, rightDrive]);

  // Dedicated effect for right joystick
  useEffect(() => {
    const handleRightJoystickInput = () => {
      const gamepads = navigator.getGamepads();
      const gamepad = gamepads[0]; // Use the first connected gamepad

      if (gamepad) {
        // Update right joystick state
        const rightStickX = Math.round(gamepad.axes[2] * 100); // Left/right on right stick
        const rightStickY = Math.round(gamepad.axes[3] * 100); // Up/down on right stick
        setRightJoystick({ x: rightStickX, y: rightStickY }); // Invert Y for correct orientation

        // Map Y-axis of right stick to rightDrive
        const newRightDrive = Math.round(gamepad.axes[3] * -100);
        if (newRightDrive !== rightDrive) {
          setRightDrive(newRightDrive);
          sendCommand(leftDrive, newRightDrive); // Send updated values
        }
      }
    };

    const interval = setInterval(handleRightJoystickInput, 50); // Polling every 50ms
    return () => clearInterval(interval);
  }, [leftDrive, rightDrive]);

  return (
    <div className="container">
      <h1 className="header">Dual Joystick Control</h1>
      <div className="drive-values">
        <p>Left Drive: {leftDrive}</p>
        <p>Right Drive: {rightDrive}</p>
      </div>
      <div className="joysticks">
        {/* Left Joystick */}
        <div className="joystick-container">
          <div
            className="joystick-knob"
            style={{
              transform: `translate(${leftJoystick.x}px, ${leftJoystick.y}px)`,
            }}
          ></div>
        </div>
        {/* Right Joystick */}
        <div className="joystick-container">
          <div
            className="joystick-knob"
            style={{
              transform: `translate(${rightJoystick.x}px, ${rightJoystick.y}px)`,
            }}
          ></div>
        </div>
      </div>
    </div>
  );
};

export default JoystickControl;
