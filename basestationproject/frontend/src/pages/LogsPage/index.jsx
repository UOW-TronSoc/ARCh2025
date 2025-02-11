import React, { useState, useEffect, useRef } from "react";
import axios from "axios";
import "bootstrap/dist/css/bootstrap.min.css"; // Import Bootstrap

const LogsPage = () => {
  const [logs, setLogs] = useState([]);
  const logsContainerRef = useRef(null); // Reference to the logs container
  const [isAutoScrollEnabled, setIsAutoScrollEnabled] = useState(true); // Track if auto-scroll is active

  useEffect(() => {
    document.title = "Logs";
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

  // Auto-scroll to the bottom when logs update (if auto-scroll is enabled)
  useEffect(() => {
    if (isAutoScrollEnabled && logsContainerRef.current) {
      logsContainerRef.current.scrollTop = logsContainerRef.current.scrollHeight;
    }
  }, [logs, isAutoScrollEnabled]);

  // Detect user's scroll position
  const handleScroll = () => {
    const { scrollTop, scrollHeight, clientHeight } = logsContainerRef.current;
    const isAtBottom = scrollTop + clientHeight >= scrollHeight - 10; // 10px threshold
    setIsAutoScrollEnabled(isAtBottom); // Enable auto-scroll only if the user is near the bottom
  };

  const saveLogsToFile = () => {
    const logContent = logs.join("\n");
    const blob = new Blob([logContent], { type: "text/plain" });
    const a = document.createElement("a");
    a.href = URL.createObjectURL(blob);
    a.download = "rover_logs.txt";
    a.click();
  };

  return (
    <div className="container mt-1 mb-4">
      <h1 className="text-center mb-4 text-white">Command Logs</h1>

      {/* Logs Display Section */}
      <div className="container card mb-4 col-lg-6 col-md-8 mx-auto">
        <div className="card-header bg-primary text-white text-center">
          <h2 className="h5 mb-0">Live Command Logs</h2>
        </div>
        <div
          className="card-body bg-light border rounded overflow-auto"
          style={{ maxHeight: "400px" }}
          ref={logsContainerRef}
          onScroll={handleScroll}
        >
          {logs.length === 0 ? (
            <p className="text-muted text-center fst-italic">
              No logs available...
            </p>
          ) : (
            logs.map((log, index) => (
              <div
                key={index}
                className="border-start border-4 border-warning bg-dark text-white p-2 mb-2 rounded"
                style={{ fontFamily: "Courier New, monospace" }}
              >
                {log}
              </div>
            ))
          )}
        </div>
      </div>

      {/* Save Logs Button */}
      <div className="text-center">
        <button onClick={saveLogsToFile} className="btn btn-success mt-2">
          Save Logs
        </button>
      </div>
    </div>
  );
};

export default LogsPage;
