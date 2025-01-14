import React from "react";
import { Card, Col, Row } from "react-bootstrap";

const DeviceOverview = ({ devices }) => {
  console.log("Devices Received:", devices); // Debugging

  if (!devices || devices.length === 0) {
    return <p>No devices connected yet.</p>;
  }

  return (
    <Row>
      {devices.map((device, index) => (
        <Col key={index} md={4} className="mb-3">
          <Card className={index === 0 ? "card-highlight" : ""} body>
            <h6>{device.name}</h6>
            <p>{device.status}%</p>
          </Card>
        </Col>
      ))}
    </Row>
  );
};

export default DeviceOverview;
