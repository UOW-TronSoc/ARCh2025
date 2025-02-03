import React, { useEffect, useState } from "react";
import axios from "axios";
import "./styles.css";

const ScienceDashboard = () => {
  const [scienceData, setScienceData] = useState({
    water_percent: 0,
    temperature: 0,
    ilmenite_percent: 0,
  });

  const [controlState, setControlState] = useState({
    heat_status: false,
    water_status: false,
    ilmenite_status: false,
    deploy_heat: false,
    deploy_sensors: false,
  });

  // Fetch Science Feedback
  useEffect(() => {
    document.title = "Science Dashboard"
    const fetchScienceFeedback = async () => {
      try {
        const response = await axios.get("http://127.0.0.1:8000/api/science-feedback/");
        setScienceData(response.data);
      } catch (error) {
        console.error("Failed to fetch science feedback:", error.response?.data || error.message);
      }
    };

    const interval = setInterval(fetchScienceFeedback, 1000); // Auto-refresh every second
    return () => clearInterval(interval);
  }, []);

  // Send Science Control Command
  const sendControlCommand = async () => {
    try {
      await axios.post("http://127.0.0.1:8000/api/science-control/", controlState, {
        headers: { "Content-Type": "application/json" },
      });
      console.log("Control command sent successfully!");
    } catch (error) {
      console.error("Failed to send control command:", error.response?.data || error.message);
    }
  };

  return (
    <div className="science-container">
      <h1 className="header">Science Dashboard</h1>

      {/* Science Feedback Section */}
      <div className="science-feedback">
        <h2>Live Science Feedback</h2>
        <p><strong>Water Percentage:</strong> {Math.round(scienceData.water_percent * 100)/100}%</p>
        <p><strong>Temperature:</strong> {Math.round(scienceData.temperature * 100)/100}°C</p>
        {/* <p><strong>Ilmenite Percentage:</strong> {Math.round(scienceData.ilmenite_percent * 100)/100}%</p> */}
        <p><strong>Ilmenite Percentage:</strong>  N/A</p>
      </div>

      {/* Science Control Section */}
      <div className="science-control">
        <h2>Science Control</h2>
        <label>
          <input
            type="checkbox"
            checked={controlState.heat_status}
            onChange={() => setControlState({ ...controlState, heat_status: !controlState.heat_status })}
          />
          Heat Status
        </label>

        <label>
          <input
            type="checkbox"
            checked={controlState.water_status}
            onChange={() => setControlState({ ...controlState, water_status: !controlState.water_status })}
          />
          Water Status
        </label>

        <label>
          <input
            type="checkbox"
            checked={controlState.ilmenite_status}
            onChange={() => setControlState({ ...controlState, ilmenite_status: !controlState.ilmenite_status })}
          />
          Ilmenite Status
        </label>

        <label>
          <input
            type="checkbox"
            checked={controlState.deploy_heat}
            onChange={() => setControlState({ ...controlState, deploy_heat: !controlState.deploy_heat })}
          />
          Deploy Heat
        </label>

        <label>
          <input
            type="checkbox"
            checked={controlState.deploy_sensors}
            onChange={() => setControlState({ ...controlState, deploy_sensors: !controlState.deploy_sensors })}
          />
          Deploy Sensors
        </label>

        <button onClick={sendControlCommand} className="send-button">
          Send Control Command
        </button>
      </div>
    </div>
  );
};

export default ScienceDashboard;
