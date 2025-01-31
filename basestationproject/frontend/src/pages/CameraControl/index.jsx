import React, { useState, useEffect } from "react";
import { Form, Button, Row, Col } from "react-bootstrap";
import axios from "axios";

const CameraControl = () => {
  const [cameras, setCameras] = useState([]);
  const [activeCameras, setActiveCameras] = useState({});
  const [fps, setFps] = useState(30);

  useEffect(() => {
    axios.get("http://127.0.0.1:8000/api/available_cameras/")
      .then(response => {
        setCameras(response.data.cameras);
        const initialStates = {};
        response.data.cameras.forEach(cam => (initialStates[cam] = true));
        setActiveCameras(initialStates);
      })
      .catch(error => console.error("Failed to fetch cameras", error));
  }, []);

  return (
    <div className="camera-control-container">
      <h2>Camera Feeds</h2>

      <Row>
        {cameras.map((cameraId) => (
          <Col md={6} key={cameraId} className="camera-container">
            <h4>Camera {cameraId}</h4>

            <Form.Check
              type="switch"
              id={`camera-toggle-${cameraId}`}
              label={activeCameras[cameraId] ? "On" : "Off"}
              checked={activeCameras[cameraId]}
              onChange={() => setActiveCameras({
                ...activeCameras, [cameraId]: !activeCameras[cameraId]
              })}
            />

            <Form.Group controlId={`fps-select-${cameraId}`}>
              <Form.Label>FPS</Form.Label>
              <Form.Control
                as="select"
                value={fps}
                onChange={(e) => setFps(parseInt(e.target.value))}
              >
                {[15, 30, 60].map((fpsVal) => (
                  <option key={fpsVal} value={fpsVal}>{fpsVal} FPS</option>
                ))}
              </Form.Control>
            </Form.Group>

            {activeCameras[cameraId] && (
              <img
                src={`http://127.0.0.1:8000/api/camera_stream/${cameraId}/image_raw/?fps=${fps}`}
                alt={`Camera ${cameraId}`}
                className="camera-stream"
              />
            )}
          </Col>
        ))}
      </Row>
    </div>
  );
};

export default CameraControl;
