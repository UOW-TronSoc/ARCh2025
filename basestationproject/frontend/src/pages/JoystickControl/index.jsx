import React, { useEffect, useState } from "react";
import axios from "axios";
import "bootstrap/dist/css/bootstrap.min.css";

const JoystickControl = () => {
  const [leftDrive, setLeftDrive] = useState(0);
  const [rightDrive, setRightDrive] = useState(0);
  const [leftJoystick, setLeftJoystick] = useState({ x: 0, y: 0 });
  const [rightJoystick, setRightJoystick] = useState({ x: 0, y: 0 });
  const [drivetrainFeedback, setDrivetrainFeedback] = useState({
    epoch_time: null,
    wheel_position: [],
    wheel_velocity: [],
    wheel_torque: [],
  });

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
    const interval = setInterval(fetchDrivetrainFeedback, 1000);
    return () => clearInterval(interval);
  }, []);

  const sendCommand = async (leftDrive, rightDrive) => {
    try {
      const response = await axios.post("http://127.0.0.1:8080/command", { left_drive: leftDrive, right_drive: rightDrive }, {
        headers: { "Content-Type": "application/json" },
      });
      console.log("Command sent:", response.data);
    } catch (error) {
      console.error("Failed to send command:", error.response?.data || error.message);
    }
  };

  useEffect(() => {
    const handleJoystickInput = () => {
      const gamepads = navigator.getGamepads();
      const gamepad = gamepads[0];
      if (gamepad) {
        setLeftJoystick({ x: Math.round(gamepad.axes[0] * 100), y: Math.round(gamepad.axes[1] * 100) });
        setRightJoystick({ x: Math.round(gamepad.axes[2] * 100), y: Math.round(gamepad.axes[3] * 100) });
        const newLeftDrive = Math.round(gamepad.axes[1] * -100);
        const newRightDrive = Math.round(gamepad.axes[3] * -100);
        setLeftDrive(newLeftDrive);
        setRightDrive(newRightDrive);
        sendCommand(newLeftDrive, newRightDrive);
      }
    };
    const interval = setInterval(handleJoystickInput, 50);
    return () => clearInterval(interval);
  }, [leftDrive, rightDrive]);

  return (
    <div className="container text-center py-5 text-white">
      <h1 className="mb-4">Dual Joystick Control</h1>
      <div className="mb-3">
        <p className="fw-bold">Left Drive: {leftDrive}</p>
        <p className="fw-bold">Right Drive: {rightDrive}</p>
      </div>
      <div className="d-flex justify-content-center gap-4">
        <div className="border rounded-circle bg-light d-flex align-items-center justify-content-center" style={{ width: "200px", height: "200px" }}>
          <div className="bg-dark rounded-circle position-absolute" style={{ width: "40px", height: "40px", transform: `translate(${leftJoystick.x}px, ${leftJoystick.y}px)` }}></div>
        </div>
        <div className="border rounded-circle bg-light d-flex align-items-center justify-content-center" style={{ width: "200px", height: "200px" }}>
          <div className="bg-dark rounded-circle position-absolute" style={{ width: "40px", height: "40px", transform: `translate(${rightJoystick.x}px, ${rightJoystick.y}px)` }}></div>
        </div>
      </div>
      <div className="drivetrain-container container col-lg-8 col-md-4 col-sm-12 mt-4 p-3 border rounded bg-light text-dark">
        <h2>Drivetrain Feedback</h2>
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
  );
};

export default JoystickControl;
