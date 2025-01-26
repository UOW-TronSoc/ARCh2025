import React from "react";
import Layout from "../components/Layout";
import KangaConnection from "../index/kanga_connection/KangaConnection";
import DeviceDetails from "../index/device_details/DeviceDetails";
import QuickOverview from "../index/quick_overview/QuickOverview";
import RoboSpec from "../index/robot_specs/RoboSpec";
import ControlCommandLogHistory from "../control_command/LogHistory";
import NLISection from "../control_command/NLISection";
import MapAndControls from "../control_command/MapAndControls";
import DataGraph from "../data_sensors/DataGraph";
import DataLogHistory from "../data_sensors/LogHistory";

const Dashboard = () => {
  return (
    <Layout>
      {/* Main Seciton with Kanga Connection */}
      <KangaConnection />

      <div className="main-container">
        <div className="middle-section">
          {/* Left Column: Device Details and Quick Overview */}
          <div className="left-column">
            <DeviceDetails />
            <QuickOverview />
          </div>
          {/* Right Column: Robot Specifications */}
          <div className="right-column">
            <RoboSpec />
          </div>
        </div>
      </div>
      <div className="main-container">
        <div className="middle-section">
          {/* Left Column: Control Command Log History and NLI Section */}
          <div className="left-column">
            <ControlCommandLogHistory />
            <NLISection />
          </div>
          {/* Right Column: Map and Controls */}
          <div className="right-column">
            <MapAndControls />
          </div>
        </div>
        <div className="main-container">
          <div className="middle-section">
            {/* Left Column: Data Graph */}
            <div className="left-column">
              <DataGraph />
            </div>
            {/* Right Column: Data Log History */}
            <div className="right-column">
              <DataLogHistory />
            </div>
          </div>
        </div>
      </div>
    </Layout>
  );
};

export default Dashboard;
