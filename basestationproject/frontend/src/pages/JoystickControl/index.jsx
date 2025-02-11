import React, { useEffect, useState } from "react";
import axios from "axios";
import "bootstrap/dist/css/bootstrap.min.css";
import "./styles.css"; // Keeping custom styles for joysticks

const JoystickControl = () => {
  const [leftDrive, setLeftDrive] = useState(0);
  const [rightDrive, setRightDrive] = useState(0);
  const [leftJoystick, setLeftJoystick] = useState({ x: 0, y: 0 });
  const [rightJoystick, setRightJoystick] = useState({ x: 0, y: 0 });

  // State for drivetrain feedback
  const [drivetrainFeedback, setDrivetrainFeedback] = useState({
    epoch_time: null,
    wheel_position: [],
    wheel_velocity: [],
    wheel_torque: [],
  });

  // Fetch drivetrain feedback from the Django API
  useEffect(() => {
    document.title = "Drive Control Rover";
    const fetchDrivetrainFeedback = async () => {
      try {
        const response = await axios.get("http://127.0.0.1:8000/api/drivetrain-feedback/");
        setDrivetrainFeedback(response.data);
      } catch (error) {
        console.error("Failed to fetch drivetrain feedback:", error.response?.data || error.message);
      }
    };

    const interval = setInterval(fetchDrivetrainFeedback, 1000); // Auto-refresh every 1 sec
    return () => clearInterval(interval);
  }, []);

  // Send drive command to backend
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

  // Dedicated effect for right joystick
  useEffect(() => {
    const handleRightJoystickInput = () => {
      const gamepads = navigator.getGamepads();
      const gamepad = gamepads[0]; // Use the first connected gamepad

      if (gamepad) {
        // Update right joystick state
        const rightStickX = Math.round(gamepad.axes[2] * 100);
        const rightStickY = Math.round(gamepad.axes[3] * 100);
        setRightJoystick({ x: rightStickX, y: rightStickY });

        const leftStickX = Math.round(gamepad.axes[0] * 100); // Left/right on left stick
        const leftStickY = Math.round(gamepad.axes[1] * 100); // Up/down on left stick
        setLeftJoystick({ x: leftStickX, y: leftStickY });

        // Map Y-axis of right stick to rightDrive
        const newRightDrive = Math.round(gamepad.axes[3] * -100);
        const newLeftDrive = Math.round(gamepad.axes[1] * -100);

        setRightDrive(newRightDrive);
        setLeftDrive(newLeftDrive);

        sendCommand(newLeftDrive, newRightDrive);
      }
    };

    const interval = setInterval(handleRightJoystickInput, 50); // Polling every 50ms
    return () => clearInterval(interval);
  }, [leftDrive, rightDrive]);

  return (
    <div className="container mt-4">
      <h1 className="text-center text-white mb-4">Dual Joystick Control</h1>

      {/* Drive Values Section */}
      <div className="card col-lg-6 col-md-8 mx-auto mb-4 shadow-sm">
        <div className="card-header bg-primary text-white text-center">
          <h2 className="h5 mb-0">Drive Values</h2>
        </div>
        <div className="card-body text-center">
          <p><strong>Left Drive:</strong> {leftDrive}</p>
          <p><strong>Right Drive:</strong> {rightDrive}</p>
        </div>
      </div>

      {/* Joysticks UI */}
      <div className="joysticks d-flex justify-content-center gap-4 mb-4">
        {/* Left Joystick */}
        <div className="joystick-container shadow">
          <div
            className="joystick-knob"
            style={{
              transform: `translate(${leftJoystick.x}px, ${leftJoystick.y}px)`,
            }}
          ></div>
        </div>

        {/* Right Joystick */}
        <div className="joystick-container shadow">
          <div
            className="joystick-knob"
            style={{
              transform: `translate(${rightJoystick.x}px, ${rightJoystick.y}px)`,
            }}
          ></div>
        </div>
      </div>

      {/* Drivetrain Feedback Section */}
      <div className="card col-lg-6 col-md-8 mx-auto shadow-sm">
        <div className="card-header bg-secondary text-white text-center">
          <h2 className="h5 mb-0">Drivetrain Feedback</h2>
        </div>
        <div className="card-body">
          {drivetrainFeedback.epoch_time ? (
            <div>
              <p><strong>Timestamp:</strong> {drivetrainFeedback.epoch_time}</p>
              <p><strong>Wheel Positions:</strong> {drivetrainFeedback.wheel_position.join(", ")}</p>
              <p><strong>Wheel Velocities:</strong> {drivetrainFeedback.wheel_velocity.join(", ")}</p>
              <p><strong>Wheel Torques:</strong> {drivetrainFeedback.wheel_torque.join(", ")}</p>
            </div>
          ) : (
            <div>
              <p><strong>Timestamp:</strong> N/A</p>
              <p><strong>Wheel Positions:</strong> N/A</p>
              <p><strong>Wheel Velocities:</strong> N/A</p>
              <p><strong>Wheel Torques:</strong> N/A</p>
            </div>
          )}
        </div>
      </div>
    </div>
  );
};

export default JoystickControl;
