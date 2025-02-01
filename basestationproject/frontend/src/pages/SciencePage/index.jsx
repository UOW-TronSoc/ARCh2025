import React, { useEffect, useState } from "react";
import axios from "axios";
import "./styles.css"; // Ensure you include the CSS file

const SciencePage = () => {
  const [drivetrainFeedback, setDrivetrainFeedback] = useState({
    epoch_time: null,
    wheel_position: [],
    wheel_velocity: [],
    wheel_torque: [],
  });
  
};

export default SciencePage;
