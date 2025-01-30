import React, { useState, useEffect } from "react";
import { Container, Row, Col, Card, Button, Form } from "react-bootstrap";
import "./styles.css"; // Custom styles

const CameraControl = () => {
  const [cameras, setCameras] = useState([
    { id: "front", name: "Front Camera", fps: 30, active: true, mode: "rgb", streamUrl: "/camera/front" },
    { id: "back", name: "Back Camera", fps: 30, active: true, mode: "rgb", streamUrl: "/camera/back" },
  ]);

  const handleFpsChange = (id, fps) => {
    setCameras((prevCameras) =>
      prevCameras.map((cam) =>
        cam.id === id ? { ...cam, fps: fps } : cam
      )
    );

    fetch(`/camera/${id}/fps`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ fps }),
    });
  };

  const toggleCamera = (id) => {
    setCameras((prevCameras) =>
      prevCameras.map((cam) =>
        cam.id === id ? { ...cam, active: !cam.active } : cam
      )
    );

    fetch(`/camera/${id}/toggle`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
    });
  };

  const toggleMode = (id) => {
    setCameras((prevCameras) =>
      prevCameras.map((cam) =>
        cam.id === id ? { ...cam, mode: cam.mode === "rgb" ? "depth" : "rgb" } : cam
      )
    );
  };

  return (
    <Container className="camera-page">
      <h2 className="text-center my-4">Rover Camera Control</h2>
      <Row>
        {cameras.map((camera) => (
          <Col md={6} key={camera.id}>
            <Card className="camera-card">
              <Card.Body>
                <Card.Title>{camera.name}</Card.Title>
                <div className="camera-stream">
                  {camera.active ? (
                    <img src={`${camera.streamUrl}?mode=${camera.mode}`} alt={`${camera.name} Stream`} className="camera-feed" />
                  ) : (
                    <div className="camera-off">Camera Off</div>
                  )}
                </div>
                <Form.Group controlId={`fps-control-${camera.id}`} className="mt-3">
                  <Form.Label>FPS:</Form.Label>
                  <Form.Control
                    as="select"
                    value={camera.fps}
                    onChange={(e) => handleFpsChange(camera.id, parseInt(e.target.value))}
                  >
                    {[5, 10, 15, 30, 60].map((fps) => (
                      <option key={fps} value={fps}>{fps} FPS</option>
                    ))}
                  </Form.Control>
                </Form.Group>
                <Button variant={camera.active ? "danger" : "success"} className="mt-2 mx-2" onClick={() => toggleCamera(camera.id)}>
                  {camera.active ? "Turn Off" : "Turn On"}
                </Button>
                <Button variant="info" className="mt-2" onClick={() => toggleMode(camera.id)}>
                  Switch to {camera.mode === "rgb" ? "Depth" : "RGB"}
                </Button>
              </Card.Body>
            </Card>
          </Col>
        ))}
      </Row>
    </Container>
  );
};

export default CameraControl;
