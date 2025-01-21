import React, { useState } from "react";
import { Joystick } from "react-joystick-component";
import axios from "axios";

const JoystickController = () => {
  const [leftDrive, setLeftDrive] = useState(0);
  const [rightDrive, setRightDrive] = useState(0);

  const handleMove = (event) => {
    const { x, y } = event;
    // Map joystick values to left and right drive percentages
    const left = Math.min(Math.max(Math.round((y - x) * 100), -100), 100); // Cap between -100 to 100
    const right = Math.min(Math.max(Math.round((y + x) * 100), -100), 100); // Cap between -100 to 100
    setLeftDrive(left);
    setRightDrive(right);
  };

  const handleStop = () => {
    // Reset drives when joystick stops
    setLeftDrive(0);
    setRightDrive(0);
  };

  const sendDriveCommand = async () => {
    const command = {
      epoch_time: Date.now(),
      data: "Joystick control input",
      flag: true,
      leftDrive,
      rightDrive,
    };

    try {
      const response = await axios.post("http://127.0.0.1:8000/api/send-drive-command/", command);
      console.log("Command sent:", response.data);
    } catch (error) {
      console.error("Failed to send command:", error);
    }
  };

  return (
    <div>
      <h1>Joystick Controller</h1>
      <Joystick size={100} baseColor="black" stickColor="red" move={handleMove} stop={handleStop} />
      <div>
        <p>Left Drive: {leftDrive}%</p>
        <p>Right Drive: {rightDrive}%</p>
        <button onClick={sendDriveCommand}>Send Command</button>
      </div>
    </div>
  );
};

export default JoystickController;
