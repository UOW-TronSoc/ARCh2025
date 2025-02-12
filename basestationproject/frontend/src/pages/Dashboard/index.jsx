import React, { useEffect, useState } from "react";
import { Container, Row, Col } from "react-bootstrap";
import ConnectionBar from "../../components/ConnectionBar";
import DeviceOverview from "../DeviceOverview";
import RoboSpec from "../RoboSpec";
import axios from "axios";
import "./index.css";

const Dashboard = () => {
  const [devices, setDevices] = useState([]);
  const [specs, setSpecs] = useState([]);

  // Fetch devices and robo specs on component load
  useEffect(() => {
    const fetchData = async () => {
      try {
        const [deviceResponse, specResponse] = await Promise.all([
          axios.get("http://django_server:8000/api/devices"),
          axios.get("http://django_server:8000/api/specs"),
        ]);
  
        console.log("Device Data:", deviceResponse.data); // Debugging
        console.log("Specs Data:", specResponse.data);   // Debugging
  
        setDevices(deviceResponse.data || []);
        setSpecs(specResponse.data || []);
      } catch (error) {
        console.error("Error fetching data:", error);
      }
    };
  
    fetchData();
  }, []);

  return (
    <Container fluid className="py-4 dashboard-container">
      {/* Connection Bar */}
      <Row className="mb-4">
        <Col>
          <ConnectionBar />
        </Col>
      </Row>

      {/* Main Content */}
      <Row>
        {/* Device Overview */}
        <Col md={8} className="mb-4">
          <h5 className="section-title">Quick Overview</h5>
          <DeviceOverview devices={devices} />
        </Col>

        {/* Robo Spec */}
        <Col md={4} className="mb-4">
          <h5 className="section-title">Robo Spec</h5>
          <RoboSpec specs={specs} />
        </Col>
      </Row>
    </Container>
  );
};

export default Dashboard;
