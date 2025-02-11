import React, { useState } from "react";

function NLISection() {
  const [command, setCommand] = useState("");

  const handleInputChange = (e) => {
    setCommand(e.target.value);
  };

  const handleSendCommand = () => {
    // Placeholder for sending the command to the backend or updating the response
    console.log("Command sent:", command);
  };

  return (
    <div className="nli-section p-4 rounded shadow-sm bg-light">
      <h3 className="text-center mb-4">Natural Language Interface</h3>
      <div className="nli-content mb-4">
        <p className="user-command">
          <span className="fw-bold">/YOU:</span> Show me obstacle avoidance model.
        </p>
        <p className="response">Creating cognitive map...</p>
      </div>
      <div className="nli-input d-flex align-items-center">
        <input
          type="text"
          className="form-control me-2"
          placeholder="Enter command..."
          value={command}
          onChange={handleInputChange}
        />
        <button
          className="btn btn-primary"
          onClick={handleSendCommand}
          disabled={!command.trim()}
        >
          ↩
        </button>
      </div>
    </div>
  );
}

export default NLISection;
