import React, { useEffect, useState } from "react";
import axios from "axios";
import "bootstrap/dist/css/bootstrap.min.css";

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

  useEffect(() => {
    document.title = "Science Dashboard";
    const fetchScienceFeedback = async () => {
      try {
        const response = await axios.get("http://django_server:8000/api/science-feedback/");
        setScienceData(response.data);
      } catch (error) {
        console.error("Failed to fetch science feedback:", error.response?.data || error.message);
      }
    };

    const interval = setInterval(fetchScienceFeedback, 1000);
    return () => clearInterval(interval);
  }, []);

  const sendControlCommand = async () => {
    try {
      await axios.post("http://django_server:8000/api/science-control/", controlState, {
        headers: { "Content-Type": "application/json" },
      });
      console.log("Control command sent successfully!");
    } catch (error) {
      console.error("Failed to send control command:", error.response?.data || error.message);
    }
  };

  return (
    <div className="container mt-1 mb-4">
      <h1 className="text-center mb-4 text-white">Science Dasπhboard</h1>

      {/* Science Feedback Section */}
      <div className="container card mb-4 col-lg-6 col-md-8">
        <div className="card-header bg-primary text-white">
          <h2 className="h5 mb-0">Live Science Feedback</h2>
        </div>
        <div className="card-body">
          <p><strong>Water Percentage:</strong> {Math.round(scienceData.water_percent * 100) / 100}%</p>
          <p><strong>Temperature:</strong> {Math.round(scienceData.temperature * 100) / 100}°C</p>
          <p><strong>Ilmenite Percentage:</strong> N/A</p>
        </div>
      </div>

      {/* Science Control Section */}
      <div className="container card col-lg-6 col-md-8 mx-auto">
        <div className="card-header bg-secondary text-white">
          <h2 className="h5 mb-0">Science Control</h2>
        </div>
        <div className="card-body">
          {[
            { label: "Heat Status", key: "heat_status" },
            { label: "Water Status", key: "water_status" },
            { label: "Ilmenite Status", key: "ilmenite_status" },
            { label: "Deploy Heat", key: "deploy_heat" },
            { label: "Deploy Sensors", key: "deploy_sensors" },
          ].map((item) => (
            <div className="form-check d-flex align-items-center mb-2" key={item.key}>
              <input
                className="form-check-input me-2"
                type="checkbox"
                checked={controlState[item.key]}
                onChange={() => setControlState({ ...controlState, [item.key]: !controlState[item.key] })}
                id={item.key}
              />
              <label className="form-check-label" htmlFor={item.key}>
                {item.label}
              </label>
            </div>
          ))}

          <button onClick={sendControlCommand} className="btn btn-success mt-3">
            Send Control Command
          </button>
        </div>
      </div>
    </div>
  );
};

export default ScienceDashboard;
