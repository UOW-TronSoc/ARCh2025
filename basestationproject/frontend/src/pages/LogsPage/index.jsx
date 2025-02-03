import React, { useState, useEffect, useRef } from "react";
import axios from "axios";
import "./styles.css"; // Ensure this CSS file is created and used

const LogsPage = () => {
  const [logs, setLogs] = useState([]);
  const logsEndRef = useRef(null); // Reference to the bottom of the logs container

  useEffect(() => {
    document.title = "Logs"
    const fetchLogs = async () => {
      try {
        const response = await axios.get("http://127.0.0.1:8000/api/logs/");
        setLogs(response.data.logs || []);
      } catch (error) {
        console.error("Error fetching logs:", error);
        setLogs([]);
      }
    };

    const interval = setInterval(fetchLogs, 1000); // Fetch logs every second
    return () => clearInterval(interval);
  }, []);

  // Auto-scroll to the bottom when logs update
  useEffect(() => {
    if (logsEndRef.current) {
      logsEndRef.current.scrollIntoView({ behavior: "smooth" });
    }
  }, [logs]);

  const saveLogsToFile = () => {
    const logContent = logs.join("\n");
    const blob = new Blob([logContent], { type: "text/plain" });
    const a = document.createElement("a");
    a.href = URL.createObjectURL(blob);
    a.download = "rover_logs.txt";
    a.click();
  };

  return (
    <div className="logs-container">
      <h1 className="logs-title">Rover Logs</h1>
      <button onClick={saveLogsToFile} className="save-button">Save Logs</button>
      <div className="logs-display">
        {logs.length === 0 ? (
          <p className="no-logs">No logs available...</p>
        ) : (
          logs.map((log, index) => (
            <p key={index} className="log-entry">{log}</p>
          ))
        )}
        {/* Invisible div to scroll into view */}
        <div ref={logsEndRef} />
      </div>
    </div>
  );
};

export default LogsPage;
