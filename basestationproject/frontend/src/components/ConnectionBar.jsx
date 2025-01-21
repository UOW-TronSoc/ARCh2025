import React, { useState } from "react";
import { Button, Row, Col } from "react-bootstrap";
import axios from "axios";

const ConnectionBar = () => {
  const [connected, setConnected] = useState(false);

  const handleConnect = async () => {
    try {
      await axios.post("http://localhost:8000/api/connect");
      setConnected(true);
    } catch (error) {
      console.error("Error connecting:", error);
    }
  };

  const handleDisconnect = async () => {
    try {
      await axios.post("http://localhost:8000/api/disconnect");
      setConnected(false);
    } catch (error) {
      console.error("Error disconnecting:", error);
    }
  };

  return (
    <div className="connection-bar d-flex justify-content-between align-items-center">
      <h4 className="m-0">Kanga</h4>
      <div>
        {connected ? (
          <Button variant="success" onClick={handleDisconnect}>
            Connected
          </Button>
        ) : (
          <Button variant="danger" onClick={handleConnect}>
            Disconnect
          </Button>
        )}
      </div>
    </div>
  );
};

export default ConnectionBar;