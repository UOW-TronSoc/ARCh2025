import React, { useEffect, useState } from "react";
import axios from "axios";

const JoystickControl = () => {
  const [leftDrive, setLeftDrive] = useState(0);
  const [rightDrive, setRightDrive] = useState(0);

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

  useEffect(() => {
    const handleGamepadInput = () => {
      const gamepads = navigator.getGamepads();
      const gamepad = gamepads[0]; // Assuming the first connected gamepad

      if (gamepad) {
        // Map joystick axes (-1 to 1) to left_drive and right_drive (-100 to 100)
        const leftAxis = Math.round(gamepad.axes[2] * -100); // Up/Down on left stick
        const rightAxis = Math.round(gamepad.axes[4] * -100); // Up/Down on right stick

        if (leftAxis !== leftDrive || rightAxis !== rightDrive) {
          setLeftDrive(leftAxis);
          setRightDrive(rightAxis);
          sendCommand(leftAxis, rightAxis);
        }
      }
    };

    const interval = setInterval(handleGamepadInput, 100); // Polling every 100ms
    return () => clearInterval(interval);
  }, [leftDrive, rightDrive]);

  return (
    <div>
      <h1>Joystick Control</h1>
      <p>Left Drive: {leftDrive}</p>
      <p>Right Drive: {rightDrive}</p>
    </div>
  );
};

export default JoystickControl;
