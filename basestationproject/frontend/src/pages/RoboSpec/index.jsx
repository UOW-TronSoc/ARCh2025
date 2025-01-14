import React from "react";
import { ListGroup } from "react-bootstrap";

const RoboSpec = ({ specs }) => {
  console.log("Specs Received:", specs); // Debugging

  if (!specs || specs.length === 0) {
    return <p>No robo specs available.</p>;
  }

  return (
    <ListGroup>
      {specs.map((spec, index) => (
        <ListGroup.Item key={index} className="bg-dark text-white border-0">
          <div className="d-flex justify-content-between">
            <span>
              <strong>{spec.name}</strong> ({spec.type})
            </span>
            <span>{spec.quantity} pcs.</span>
          </div>
        </ListGroup.Item>
      ))}
    </ListGroup>
  );
};

export default RoboSpec;
